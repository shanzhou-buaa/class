//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//char st[10000][50];//放停用词
//typedef struct sentences
//{
//	int times;
//	char sentence[5000];//句子
//}sentences;
//sentences sen[200000];
//
//typedef struct not_stopwords
//{
//	char words[50];
//	int times;
//	struct not_stopwords* left;
//	struct not_stopwords* right;
//}nst;
//
//typedef struct sen_num
//{
//	int index;
//	int times;
//}sen_num;
//
//nst* NstTreeInsert(nst* root, char* s);//把非停用词读到一个二叉查找树里
//int BinarySearch1(char st[][50], int left, int right, const char* s);
//int NstTreeFind(nst* root, char* s);//查找字符串在树中的位置，并返回它的次数
//void MergeSort(sen_num* a, int n);
//void MergeArr(sen_num* a, int begin1, int end1, int begin2, int end2, sen_num* tmp);
//int comp(const void* a, const void* b);
//
////void InOrder(nst* root);
//
//char all[70000005];
//sen_num sn[200000];
//
////FILE* word = NULL;
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//文章
//	FILE* write = fopen("results.txt", "w");//输出
//	FILE* stop = fopen("stopwords.txt", "r");//停用词
//	//word = fopen("word.txt", "w");//输出非停用词
//
//	int n;
//	scanf("%d", &n);
//	//int n = 200;
//	
//	//停用词已经是按ASCII码排序的，没必要读到一个二叉查找树里
//	memset(st, 0, sizeof(st));
//	int i = 1, j = 0;
//	while (fscanf(stop, "%s", st[i]) != EOF)
//		i++;
//	int wordNum = i;//停用词数，从1开始
//
//	//把每一句话读入sentences里
//	i = 0;
//	while (1)
//	{
//		//按照字符读入
//		char c = fgetc(read);
//		
//		if (c == EOF)
//			break;
//	
//		//把句子读入sen
//		if (c != '.' && c != '!' && c != '?')//句子分割标志
//		{
//			sen[i].sentence[j] = c;//原文章存入sentence
//			j++;
//		}
//		else//一句话结束
//		{
//			//把最后的标点存入
//			sen[i].sentence[j] = c;
//	
//			//删掉sentence句子前的空格
//			int i2 = 0, tmp_len = strlen(sen[i].sentence);
//			for (; i2 < tmp_len; i2++)
//			{
//				if (sen[i].sentence[i2] != ' ')
//					break;
//			}
//			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
//			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';
//	
//			//读取下一句话
//			i++;
//			j = 0;
//		}
//	}
//	int line = i;//句子行数，从0开始
//
//	//把非停用词读到一个二叉查找树里
//	rewind(read);
//	char all_tmp[50];//暂时存储一个单词
//	memset(all_tmp, 0, sizeof(all_tmp));
//
//	//非停用词的二叉查找树的根
//	nst* nst_root = NULL;
//	memset(all, 0, sizeof(all));
//
//	int len = fread(all, 1, 70000000, read);
//	//while (fread(all, 70000000, read) != NULL)
//	//{
//	//int len = strlen(all);
//	for (i = 0; i < len; i++)
//	{
//		if (all[i] == ' ' || all[i] == '.' || all[i] == '!' || all[i] == '?')//不是单词
//			continue;
//		else
//		{
//			j = 0;
//			while (isalpha(all[i]))//向all_tmp中读入一个单词
//			{
//				if (isupper(all[i]))
//					all_tmp[j] = all[i] + 32;
//				else
//					all_tmp[j] = all[i];
//				i++;
//				j++;
//			}
//			all_tmp[j] = '\0';
//
//			int flag = BinarySearch1(st, 1, wordNum, all_tmp);
//
//			//不是停用词，放进二叉查找树里
//			if (flag == -1)
//				nst_root = NstTreeInsert(nst_root, all_tmp);
//		}
//	}
//	//}
//
//	//InOrder(nst_root);
//
//	//统计每句话的非停用词总次数
//	int k = 0;
//	for (i = 0; i < line; i++)
//	{
//		int len = strlen(sen[i].sentence);
//		char word_tmp[2000];//存单词
//		memset(word_tmp, 0, sizeof(word_tmp));
//
//		j = 0;
//		while (j < len)
//		{
//			k = 0;
//			if (!isalpha(sen[i].sentence[j]))
//			{
//				j++;
//				continue;
//			}
//
//			//读一个单词
//			while (isalpha(sen[i].sentence[j]))
//			{
//				word_tmp[k] = tolower(sen[i].sentence[j]);
//				k++;
//				j++;
//			}
//			word_tmp[k] = '\0';
//
//			int flag = BinarySearch1(st, 1, wordNum, word_tmp);
//
//			if (flag == -1)//是非停用词就计数
//			{
//				int word_times = NstTreeFind(nst_root, word_tmp);
//				sen[i].times += word_times;
//			}
//		}
//	}
//
//	//排序
//	//sen_num sn[200000];
//	memset(sn, 0, sizeof(sn));
//	for (i = 0; i < line; i++)
//	{
//		sn[i].index = i;//存句子的序号
//		sn[i].times = sen[i].times;//存该序号句子的非停用词频度
//	}
//	//MergeSort(sn, line);
//	qsort(sn, line, sizeof(sn[0]), comp);
//
//	//打印
//	for (i = 0; i < 5; i++)
//		printf("%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence);
//	for (i = 0; i < n; i++)
//		fprintf(write, "%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence);
//
//	fclose(stop);
//	fclose(read);
//	fclose(write);
//	return 0;
//}
//
////nst* NstTreeInsert(nst** root, char* s)
////{
////	if ((*root) == NULL)
////	{
////		(*root) = (nst*)malloc(sizeof(nst));
////		strcpy((*root)->words, s);
////		(*root)->left = NULL;
////		(*root)->right = NULL;
////		(*root)->times = 1;
////	}
////	else
////	{
////		//s和*root的等，次数加一
////		if (strcmp(s, (*root)->words) == 0)
////			(*root)->times++;
////		//s比*root的大，往右放
////		else if (strcmp(s, (*root)->words) > 0)
////			(*root)->right = NstTreeInsert(&((*root)->right), s);
////		else
////			(*root)->left = NstTreeInsert(&((*root)->left), s);
////	}
////
////	return *(root);
////}
//
//nst* NstTreeInsert(nst* root, char* s)
//{
//	if (root == NULL)
//	{
//		root = (nst*)malloc(sizeof(nst));
//		strcpy(root->words, s);
//		root->left = NULL;
//		root->right = NULL;
//		root->times = 1;
//	}
//	else
//	{
//		//s和root的等，次数加一
//		if (strcmp(s, root->words) == 0)
//			root->times++;
//		//s比root的大，往右放
//		else if (strcmp(s, root->words) > 0)
//			root->right = NstTreeInsert(root->right, s);
//		else
//			root->left = NstTreeInsert(root->left, s);
//	}
//
//	return root;
//}
//
////返回-1说明不是停用词
//int BinarySearch1(char st[][50], int left, int right, const char* s)
//{
//	int mid = (left + right) / 2;
//	if (left <= right)
//	{
//		if (strcmp(st[mid], s) < 0)
//			return BinarySearch1(st, mid + 1, right, s);
//		else if (strcmp(st[mid], s) > 0)
//			return BinarySearch1(st, left, mid - 1, s);
//		else
//			return mid;
//	}
//	return -1;
//}
//
////查找字符串在树中的位置，并返回它的次数
//int NstTreeFind(nst* root, char* s)
//{
//	while (1)
//	{
//		if (strcmp(s, root->words) > 0)
//		{
//			root = root->right;
//		}
//		else if (strcmp(s, root->words) < 0)
//		{
//			root = root->left;
//		}
//		//相等
//		else
//		{
//			return root->times;
//		}
//	}
//}
//
//void MergeArr(sen_num* a, int begin1, int end1, int begin2, int end2, sen_num* tmp)
//{
//	int left = begin1, right = end2;
//	int index = begin1;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1].times >= a[begin2].times)
//		{
//			tmp[index].index = a[begin1].index;
//			tmp[index].times = a[begin1].times;
//			index++;
//			begin1++;
//		}
//		else
//		{
//			tmp[index].index = a[begin2].index;
//			tmp[index].times = a[begin2].times;
//			index++;
//			begin2++;
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[index].index = a[begin1].index;
//		tmp[index].times = a[begin1].times;
//		index++;
//		begin1++;
//	}
//	while (begin2 <= end2)
//	{
//		tmp[index].index = a[begin2].index;
//		tmp[index].times = a[begin2].times;
//		index++;
//		begin2++;
//	}
//	int i = 0;
//	for (i = left; i <= right; i++)
//	{
//		a[i].index = tmp[i].index;
//		a[i].times = tmp[i].times;
//	}
//}
//
//void MergeSort(sen_num* a, int n)
//{
//	sen_num* tmp = (sen_num*)malloc(sizeof(sen_num) * n);
//	int gap = 1, i = 0;
//	while (gap < n)
//	{
//		for (i = 0; i < n; i += 2 * gap)
//		{
//			int begin1 = i, end1 = i + gap - 1;
//			int begin2 = i + gap, end2 = i + 2 * gap - 1;
//			if (begin2 >= n)
//				break;
//
//			if (end2 >= n)
//				end2 = n - 1;
//
//			MergeArr(a, begin1, end1, begin2, end2, tmp);
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}
//
////void InOrder(nst* root)
////{
////	if (root == NULL)
////		return;
////
////	InOrder(root->left);
////	fprintf(word, "%s:%d\n", root->words, root->times);
////	InOrder(root->right);
////}
//
//int comp(const void* a, const void* b)
//{
//	sen_num pa = *(sen_num*)a;
//	sen_num pb = *(sen_num*)b;
//
//	return (pb.times - pa.times);
//}