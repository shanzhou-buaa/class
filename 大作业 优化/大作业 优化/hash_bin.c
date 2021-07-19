//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define article 7000005
//#define senNum 200000//句子个数
//#define word_len 30//一个单词的长度
//#define MOD 50001
//#define sen_words 200//一句话中的单词个数
//
//typedef unsigned long long ull;
//typedef struct sentences
//{
//	int begin;
//	int end;
//	char words[sen_words][word_len];//单词，交的时候改成200个词
//	int n;//一个句子中的单词个数
//}sentences;
//sentences sen[senNum];
//
//typedef struct HashNode
//{
//	char words[word_len];
//	int times;
//	struct HashNode* left;
//	struct HashNode* right;
//}hash;
//
//char all[article - 5];
//hash h[MOD + 5];
//hash sth[MOD + 5];
//
////放句子的序号(第几句)和次数
//typedef struct sen_num
//{
//	int index;
//	int times;
//}sen_num;
//
//ull HashKey(char *st);
//hash* _HashInsert(hash* h, char* s);
//void HashInsert(hash* ph, char* s);//把非停用词放入哈希表里
//int BinarySearch1(char st[][word_len], int left, int right, const char* s);//二分查找s是不是停用词
//ull HashSearch(hash* ph, char* s);//哈希查找s是不是停用词
//int _HashFind(hash* h, char* s);
//int HashFind(hash* ph, char* s);//返回字符串的次数
//int comp(const void* a, const void* b);
//
//sen_num sn[senNum];
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//文章
//	FILE* write = fopen("results.txt", "w");//输出
//	FILE* stop = fopen("stopwords.txt", "r");//停用词
//
//	int n;
//	scanf("%d", &n);
//
//	int time1 = clock();
//
//	//停用词放进哈希表
//	char st_tmp[word_len] = { 0 };
//	while (fscanf(stop, "%s", st_tmp) != EOF)
//		HashInsert(sth, st_tmp);
//
//	int time2 = clock();
//	printf("停用词放进哈希表:%d\n", time2 - time1);
//	//把每一句话读入sentences里
//	int i = 0, j = 0, index = 0;
//	int	line = 0;//句子个数，从0开始
//	fread(all, article - 5, 1, read);
//	int time8 = clock();
//	int article_len = strlen(all);
//	for (index = 0; index < article_len; index++)
//	{
//		//按照字符读入
//		char c = all[index];
//	
//		//把句子读入sen
//		if (c != '?' && c != '.' && c != '!')//句子分割标志
//		{
//			if (j == 0)
//				sen[line].begin = index;
//			j = 1;
//		}
//		else//一句话结束
//		{
//			//最后的标点
//			sen[line].end = index;
//	
//			//删掉sentence句子前的空格
//			while (all[sen[line].begin] == ' ')
//				sen[line].begin++;
//	
//			//读取下一句话
//			line++;
//			j = 0;
//		}
//	}
//
//	int time3 = clock();
//	printf("把每一句话读入sentences里:%d\n", time3 - time8);
//
//	//把非停用词读到一个二叉查找树里
//	rewind(read);
//	//把非停用词读到哈希表里
//	char all_tmp[word_len] = { 0 };//暂时存储一个单词
//	int k = 0;
//	for (i = 0; i < line; i++)
//	{
//		int len = sen[i].end - sen[i].begin;
//		for (j = 0; j < len; j++)
//		{
//			if (isalpha(all[sen[i].begin + j]))//是字母
//			{
//				k = 0;
//				while (isalpha(all[sen[i].begin + j]))//向all_tmp中读入一个单词
//				{
//					all_tmp[k] = tolower(all[sen[i].begin + j]);
//					k++;
//					j++;
//				}
//				all_tmp[k] = '\0';
//	
//				//不是停用词，放进哈希表
//				if (HashSearch(sth, all_tmp) == -1)
//				{
//					HashInsert(h, all_tmp);
//					strcpy(sen[i].words[sen[i].n], all_tmp);//把这个单词放入结构体的单词表中
//					sen[i].n++;
//				}
//			}
//		}
//	}
//
//	int time4 = clock();
//	printf("把非停用词读到哈希表里:%d\n", time4 - time3);
//
//	//统计每句话的非停用词总次数
//	i = 0;
//	//统计每句话的非停用词总次数
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < sen[i].n; j++)
//				sn[i].times += HashFind(h, sen[i].words[j]);
//		sn[i].index = i;//存句子的序号
//	}
//
//	int time5 = clock();
//	printf("统计每句话的非停用词总次数:%d\n", time5 - time4);
//
//	//排序
//	qsort(sn, line, sizeof(sn[0]), comp);
//	int time6 = clock();
//	printf("排序:%d\n", time6 - time5);
//
//	//打印
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", sn[i].times);
//		for (j = sen[sn[i].index].begin; j <= sen[sn[i].index].end; j++)
//			fputc(all[j], stdout);
//		fputc('\n', stdout);
//	}
//	for (i = 0; i < n; i++)
//	{
//		fprintf(write, "%d ", sn[i].times);
//		for (j = sen[sn[i].index].begin; j <= sen[sn[i].index].end; j++)
//			fputc(all[j], write);
//		fputc('\n', write);
//	}
//
//	int time7 = clock();
//	printf("打印:%d\n", time7 - time6);
//	fclose(stop);
//	fclose(read);
//	fclose(write);
//	return 0;
//}
//
//hash* _HashInsert(hash* h, char* s)
//{
//	if (h == NULL)
//	{
//		h = (hash*)malloc(sizeof(hash));
//		strcpy(h->words, s);
//		h->times = 1;
//		h->left = NULL;
//		h->right = NULL;
//	}
//	else if (h->times == 0)
//	{
//		strcpy(h->words, s);
//		h->times = 1;
//		h->left = NULL;
//		h->right = NULL;
//	}
//	else
//	{
//		//s和key位置的相等次数直接++
//		if (strcmp(s, h->words) == 0)
//			h->times++;
//		//s比key位置的字符串大，去右边
//		else if (strcmp(s, h->words) > 0)
//			h->right = _HashInsert(h->right, s);
//		//s比key位置的字符串大，去右边
//		else
//			h->left = _HashInsert(h->left, s);
//	}
//	return h;
//}
//
////把非停用词放入哈希表里
//void HashInsert(hash* ph, char* s)
//{
//	ull key = HashKey(s);
//	_HashInsert(&ph[key], s);
//}
//
////返回-1说明不是停用词
//int BinarySearch1(char st[][word_len], int left, int right, const char* s)
//{
//	while (left <= right)
//	{
//		int mid = (right + left) >> 1;
//		if (strcmp(st[mid], s) < 0)
//			left = mid + 1;
//		else if (strcmp(st[mid], s) > 0)
//			right = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//
////哈希查找s是不是停用词
//ull HashSearch(hash* ph, char* s)
//{
//	ull key = HashKey(s);
//	hash* cur = &ph[key];
//	while (cur != NULL)
//	{
//		if (strcmp(s, cur->words) == 0)
//			return key;
//		else if (strcmp(s, cur->words) > 0)
//			cur = cur->right;
//		else
//			cur = cur->left;
//	}
//	return -1;
//}
//
//int _HashFind(hash* h, char* s)
//{
//	if (strcmp(s, h->words) == 0)
//		return h->times;
//	else if (strcmp(s, h->words) > 0)
//		return _HashFind(h->right, s);
//	else
//		return _HashFind(h->left, s);
//}
//
////返回字符串的次数
//int HashFind(hash* ph, char* s)
//{
//	ull key = HashKey(s);
//	return _HashFind(&ph[key], s);
//}
//
//int comp(const void* a, const void* b)
//{
//	sen_num pa = *(sen_num*)a;
//	sen_num pb = *(sen_num*)b;
//
//	return (pb.times - pa.times);
//}
//
//ull HashKey(char *s)
//{
//	ull key = 0;
//	while (*s)
//		key = key * 26 + *s++;
//	return key % MOD;
//}
//
////ull HashKey(char *s)
////{
////	ull key = 0;
////	int len = strlen(s) / 3;
////	int i = 0;
////	for (i = 0; i < len; i++)
////		key = key * 26 + *(s + i);
////	return key % MOD;
////}