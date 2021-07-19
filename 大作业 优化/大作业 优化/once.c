//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//
//typedef unsigned long long ull;
//#define article 7000005
//#define senNum 200000//句子个数
//#define word_len 30//一个单词的长度
//#define MOD 700005//哈希
//#define sen_words 200//一句话中的单词个数，交的时候改成200个词
//
//typedef struct sentences
//{
//	//int times;//句子中非停用词总次数
//	//char sentence[5000];//句子
//	char words[sen_words][word_len];
//	int n;//一个句子中的单词个数
//	int begin;
//	int end;
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
//ull HashKey(char *st);
//void HashInsert(hash* ph, char* s);//把非停用词放入哈希表里
//ull HashSearch(hash* ph, char* s);//哈希查找s是不是停用词
//int HashFind(hash* ph, char* s);//返回非停用词的次数
//int comp(const void* a, const void* b);
//
//char all[article];
//sen_num sn[senNum];
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//文章
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
//	int i = 0, j = 0, index = 0, k = 0;
//	fread(all, article - 5, 1, read);
//	int article_len = strlen(all);//全文长度
//	char all_tmp[word_len] = { 0 };//暂时存储一个单词
//
//	fclose(read);
//	fclose(stop);
//
//	while(index < article_len)//遍历文章
//	{
//		if (j == 0)
//			sen[i].begin = index;
//
//		//是字母，放入all_tmp，并继续往后读直到不是字母
//		if (isalpha(all[index]))
//		{
//			k = 0;
//			while (isalpha(all[index]))//放入句子和all_tmp
//			{
//				all_tmp[k++] = tolower(all[index++]);
//				j++;
//			}
//			all_tmp[k] = '\0';
//
//			//不是停用词，放进哈希表
//			if (HashSearch(sth, all_tmp) == -1)
//			{
//				HashInsert(h, all_tmp);
//				strcpy(sen[i].words[sen[i].n], all_tmp);//把这个单词放入结构体的单词表中
//				sen[i].n++;
//			}
//		}
//
//		//是分割标志，处理空格后进入下一句话
//		else if (all[index] == '.' || all[index] == '!' || all[index] == '?')
//		{
//			sen[i].end = index;
//			//处理句子前面的空格
//			while (all[sen[i].begin] == ' ')
//				sen[i].begin++;
//			i++;
//			j = 0;
//			index++;
//		}
//		else//标点
//		{
//			index++;
//			j++;
//		}
//	}
//	int line = i;//句子个数，从0开始
//
//	//统计每句话的非停用词总次数
//	for (i = 0; i < line; i++)
//	{
//		sn[i].index = i;//存句子的序号
//		for (j = 0; j < sen[i].n; j++)
//		{
//			if (HashSearch(sth, sen[i].words[j]) == -1)//是非停用词就计数
//				sn[i].times += HashFind(h, sen[i].words[j]);
//		}
//	}
//
//	//排序
//	qsort(sn, line, sizeof(sn[0]), comp);
//
//	FILE* write = fopen("results.txt", "w");//输出
//	//打印
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", sn[i].times);
//		for (j = sen[sn[i].index].begin; j <= sen[sn[i].index].end; j++)
//			printf("%c", all[j]);
//		printf("\n");
//	}
//	for (i = 0; i < n; i++)
//	{
//		fprintf(write, "%d ", sn[i].times);
//		for (j = sen[sn[i].index].begin; j <= sen[sn[i].index].end; j++)
//			fprintf(write, "%c", all[j]);
//		fprintf(write, "\n");
//	}
//
//	fclose(write);
//	return 0;
//}
//
////把非停用词放入哈希表里
//void HashInsert(hash* ph, char* s)
//{
//	ull key = HashKey(s);
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
//	ull key = HashKey(s);
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
//ull HashSearch(hash* ph, char* s)
//{
//	ull key = HashKey(s);
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
//ull HashKey(char *s)
//{
//	ull key = 0;
//	while (*s != '\0')
//		key = key * 31 + (unsigned long long)(*s++);
//	return key % MOD;
//}