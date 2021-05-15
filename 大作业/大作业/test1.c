//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//char st[10000][50];//��ͣ�ô�
//typedef struct sentences
//{
//	int times;
//	char sentence[5000];//����
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
//nst* NstTreeInsert(nst* root, char* s);//�ѷ�ͣ�ôʶ���һ�������������
//int BinarySearch1(char st[][50], int left, int right, const char* s);
//int NstTreeFind(nst* root, char* s);//�����ַ��������е�λ�ã����������Ĵ���
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
//	FILE* read = fopen("article.txt", "r");//����
//	FILE* write = fopen("results.txt", "w");//���
//	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�
//	//word = fopen("word.txt", "w");//�����ͣ�ô�
//
//	int n;
//	scanf("%d", &n);
//	//int n = 200;
//	
//	//ͣ�ô��Ѿ��ǰ�ASCII������ģ�û��Ҫ����һ�������������
//	memset(st, 0, sizeof(st));
//	int i = 1, j = 0;
//	while (fscanf(stop, "%s", st[i]) != EOF)
//		i++;
//	int wordNum = i;//ͣ�ô�������1��ʼ
//
//	//��ÿһ�仰����sentences��
//	i = 0;
//	while (1)
//	{
//		//�����ַ�����
//		char c = fgetc(read);
//		
//		if (c == EOF)
//			break;
//	
//		//�Ѿ��Ӷ���sen
//		if (c != '.' && c != '!' && c != '?')//���ӷָ��־
//		{
//			sen[i].sentence[j] = c;//ԭ���´���sentence
//			j++;
//		}
//		else//һ�仰����
//		{
//			//�����ı�����
//			sen[i].sentence[j] = c;
//	
//			//ɾ��sentence����ǰ�Ŀո�
//			int i2 = 0, tmp_len = strlen(sen[i].sentence);
//			for (; i2 < tmp_len; i2++)
//			{
//				if (sen[i].sentence[i2] != ' ')
//					break;
//			}
//			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
//			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';
//	
//			//��ȡ��һ�仰
//			i++;
//			j = 0;
//		}
//	}
//	int line = i;//������������0��ʼ
//
//	//�ѷ�ͣ�ôʶ���һ�������������
//	rewind(read);
//	char all_tmp[50];//��ʱ�洢һ������
//	memset(all_tmp, 0, sizeof(all_tmp));
//
//	//��ͣ�ôʵĶ���������ĸ�
//	nst* nst_root = NULL;
//	memset(all, 0, sizeof(all));
//
//	int len = fread(all, 1, 70000000, read);
//	//while (fread(all, 70000000, read) != NULL)
//	//{
//	//int len = strlen(all);
//	for (i = 0; i < len; i++)
//	{
//		if (all[i] == ' ' || all[i] == '.' || all[i] == '!' || all[i] == '?')//���ǵ���
//			continue;
//		else
//		{
//			j = 0;
//			while (isalpha(all[i]))//��all_tmp�ж���һ������
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
//			//����ͣ�ôʣ��Ž������������
//			if (flag == -1)
//				nst_root = NstTreeInsert(nst_root, all_tmp);
//		}
//	}
//	//}
//
//	//InOrder(nst_root);
//
//	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
//	int k = 0;
//	for (i = 0; i < line; i++)
//	{
//		int len = strlen(sen[i].sentence);
//		char word_tmp[2000];//�浥��
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
//			//��һ������
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
//			if (flag == -1)//�Ƿ�ͣ�ôʾͼ���
//			{
//				int word_times = NstTreeFind(nst_root, word_tmp);
//				sen[i].times += word_times;
//			}
//		}
//	}
//
//	//����
//	//sen_num sn[200000];
//	memset(sn, 0, sizeof(sn));
//	for (i = 0; i < line; i++)
//	{
//		sn[i].index = i;//����ӵ����
//		sn[i].times = sen[i].times;//�����ž��ӵķ�ͣ�ô�Ƶ��
//	}
//	//MergeSort(sn, line);
//	qsort(sn, line, sizeof(sn[0]), comp);
//
//	//��ӡ
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
////		//s��*root�ĵȣ�������һ
////		if (strcmp(s, (*root)->words) == 0)
////			(*root)->times++;
////		//s��*root�Ĵ����ҷ�
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
//		//s��root�ĵȣ�������һ
//		if (strcmp(s, root->words) == 0)
//			root->times++;
//		//s��root�Ĵ����ҷ�
//		else if (strcmp(s, root->words) > 0)
//			root->right = NstTreeInsert(root->right, s);
//		else
//			root->left = NstTreeInsert(root->left, s);
//	}
//
//	return root;
//}
//
////����-1˵������ͣ�ô�
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
////�����ַ��������е�λ�ã����������Ĵ���
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
//		//���
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