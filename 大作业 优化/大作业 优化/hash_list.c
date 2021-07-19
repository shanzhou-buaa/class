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
//#define MOD 70005
//#define sen_words 200//一句话中的单词个数
//
//typedef struct sentences
//{
//	int times;//句子中非停用词总次数
//	char sentence[5000];//句子
//	char words[sen_words][word_len];//单词，交的时候改成200个词
//	int n;//一个句子中的单词个数
//	//int space;
//}sentences;
//sentences sen[senNum];
//
//typedef struct HashNode
//{
//	char words[word_len];
//	int times;
//	struct HashNode* next;
//}hash;
//
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
//unsigned long long HashKey(char *st);
//void HashInsert(hash* ph, char* s);//把非停用词放入哈希表里
//int HashSearch(hash* ph, char* s);//哈希查找s是不是停用词
//int HashFind(hash* ph, char* s);//返回非停用词的次数
//int comp(const void* a, const void* b);
////void ListNum(hash* h);
//
//char all[article];
//sen_num sn[senNum];
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//文章
//	FILE* write = fopen("results.txt", "w");//输出
//	FILE* stop = fopen("stopwords.txt", "r");//停用词
//	//int n = 20;
//	int n;
//	scanf("%d", &n);
//
//	//停用词放进哈希表
//	char st_tmp[word_len] = { 0 };
//	while (fscanf(stop, "%s", st_tmp) != EOF)
//		HashInsert(sth, st_tmp);
//
//	//把每一句话读入sentences里
//	int i = 0, j = 0, index = 0;
//	fread(all, article - 5, 1, read);
//	int article_len = strlen(all);
//	int time1 = clock();
//	for (index = 0; index < article_len; index++)
//	{
//		//按照字符读入
//		char c = all[index];
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
//			for (i2 = 0; i2 < tmp_len; i2++)
//			{
//				if (sen[i].sentence[i2] != ' ')
//					break;
//			}
//			//sen[i].space = i2;
//			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
//			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';
//
//			//读取下一句话
//			i++;
//			j = 0;
//		}
//	}
//	int line = i;//句子个数，从0开始
//
//	//把非停用词读到哈希表里
//	rewind(read);
//	char all_tmp[word_len] = { 0 };//暂时存储一个单词
//	int k = 0;
//	for (i = 0; i < line; i++)
//	{
//		int len = strlen(sen[i].sentence);
//		for (j = 0; j < len; j++)
//		{
//			if (isalpha(sen[i].sentence[j]))//是字母
//			{
//				k = 0;
//				while (isalpha(sen[i].sentence[j]))//向all_tmp中读入一个单词
//					all_tmp[k++] = tolower(sen[i].sentence[j++]);
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
//	int time2 = clock();
//	printf("%d\n", time2 - time1);
//	//ListNum(h);
//	//统计每句话的非停用词总次数
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < sen[i].n; j++)
//		{
//			if (HashSearch(sth, sen[i].words[j]) == -1)//是非停用词就计数
//			{
//				int word_times = HashFind(h, sen[i].words[j]);
//				sen[i].times += word_times;
//			}
//		}
//		sn[i].index = i;//存句子的序号
//		sn[i].times = sen[i].times;//存该序号句子的非停用词频度
//	}
//
//	//排序
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
////把非停用词放入哈希表里
//void HashInsert(hash* ph, char* s)
//{
//	int key = HashKey(s);
//	if (ph[key].times == 0)
//	{
//		strcpy(ph[key].words, s);
//		ph[key].times = 1;
//	}
//	else
//	{
//		hash* cur = &ph[key];
//		hash* prev = NULL;
//		while (cur != NULL)
//		{
//			if (strcmp(s, cur->words) == 0)
//			{
//				cur->times++;
//				return;
//			}
//			prev = cur;
//			cur = cur->next;
//		}
//		if (cur == NULL)
//		{
//			cur = (hash*)malloc(sizeof(hash));
//			strcpy(cur->words, s);
//			cur->times = 1;
//			cur->next = NULL;
//			prev->next = cur;
//		}
//	}
//}
//
////返回字符串的次数
//int HashFind(hash* ph, char* s)
//{
//	int key = HashKey(s);
//	hash* cur = &ph[key];
//	while (cur != NULL)
//	{
//		if (strcmp(cur->words, s) == 0)
//			return cur->times;
//		cur = cur->next;
//	}
//	return cur->times;
//}
//
////哈希查找s是不是停用词
//int HashSearch(hash* ph, char* s)
//{
//	int key = HashKey(s);
//	hash* cur = &ph[key];
//	while (cur != NULL)
//	{
//		if (strcmp(cur->words, s) == 0)
//			return key;
//		cur = cur->next;
//	}
//	return -1;
//}
//
//int comp(const void* a, const void* b)
//{
//	return ((*(sen_num*)b).times - (*(sen_num*)a).times);
//}
//
//unsigned long long HashKey(char *s)
//{
//	unsigned long long key = 0;
//	while (*s != '\0')
//		key = key * 31 + (unsigned long long)(*s++);
//	return key % MOD;
//}
//
////void ListNum(hash* h)
////{
////	int i = 0;
////	for (i = 0; i < MOD; i++)
////	{
////		int num = 0;
////		hash* cur = &h[i];
////		while (cur != NULL)
////		{
////			cur = cur->next;
////			num++;
////		}
////		printf("%d\n", num);
////		//sleep(1000);
////	}
////}