#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long ull;
#define article 7000005
#define senNum 200000//句子个数
#define word_len 30//一个单词的长度
#define MOD 100005
#define sen_words 200//一句话中的单词个数

typedef struct sentences
{
	char words[sen_words][word_len];
	int n;//一个句子中的单词个数
	int begin;
	int end;
}sentences;
sentences sen[senNum];

typedef struct HashNode
{
	char words[word_len];
	int times;
	struct HashNode* next;
}hash;

hash h[MOD + 5];
hash sth[MOD + 5];

//放句子的序号(第几句)和次数
typedef struct sen_num
{
	int index;
	int times;
}sen_num;

ull HashKey(char *st);
void HashInsert(hash* ph, char* s);//把非停用词放入哈希表里
ull HashSearch(hash* ph, char* s);//哈希查找s是不是停用词
int HashFind(hash* ph, char* s);//返回非停用词的次数
int comp(const void* a, const void* b);

char all[article];
sen_num sn[senNum];

int main()
{
	FILE* read = fopen("article.txt", "r");//文章
	FILE* write = fopen("results.txt", "w");//输出
	FILE* stop = fopen("stopwords.txt", "r");//停用词
	
	int n;
	scanf("%d", &n);

	int time1 = clock();
	//停用词放进哈希表
	char st_tmp[word_len] = { 0 };
	while (fscanf(stop, "%s", st_tmp) != EOF)
		HashInsert(sth, st_tmp);
	int time2 = clock();
	printf("停用词放进哈希表:%d\n", time2 - time1);

	//找到sentences的begin，end
	int i = 0, j = 0, index = 0;
	int	line = 0;//句子个数，从0开始
	fread(all, article - 5, 1, read);
	int time8 = clock();
	printf("读文章：%d\n", time8 - time2);
	int article_len = strlen(all);
	for (index = 0; index < article_len; index++)
	{
		//按照字符读入
		char c = all[index];

		//把句子读入sen
		if (c != '?' && c != '.' && c != '!')//句子分割标志
		{
			if (j == 0)
				sen[line].begin = index;
			j = 1;
		}
		else//一句话结束
		{
			//最后的标点
			sen[line].end = index;

			//删掉sentence句子前的空格
			while (all[sen[line].begin] == ' ')
				sen[line].begin++;

			//读取下一句话
			line++;
			j = 0;
		}
	}
	int time3 = clock();
	printf("把每一句话读入sentences里:%d\n", time3 - time8);

	//把非停用词读到哈希表里
	char all_tmp[word_len] = { 0 };//暂时存储一个单词
	int k = 0;
	for (i = 0; i < line; i++)
	{
		int len = sen[i].end - sen[i].begin;
		for (j = 0; j < len; j++)
		{
			if (isalpha(all[sen[i].begin + j]))//是字母
			{
				k = 0;
				while (isalpha(all[sen[i].begin + j]))//向all_tmp中读入一个单词
				{
					all_tmp[k] = tolower(all[sen[i].begin + j]);
					k++;
					j++;
				}
				all_tmp[k] = '\0';

				//不是停用词，放进哈希表
				if (HashSearch(sth, all_tmp) == -1)
				{
					HashInsert(h, all_tmp);
					strcpy(sen[i].words[sen[i].n], all_tmp);//把这个单词放入结构体的单词表中
					sen[i].n++;
				}
			}
		}
	}	
	int time4 = clock();
	printf("把非停用词读到哈希表里:%d\n", time4 - time3);

	//i = 0;
	//统计每句话的非停用词总次数
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < sen[i].n; j++)
				sn[i].times += HashFind(h, sen[i].words[j]);
		sn[i].index = i;//存句子的序号
	}
	int time5 = clock();
	printf("统计每句话的非停用词总次数:%d\n", time5 - time4);

	//排序
	qsort(sn, line, sizeof(sn[0]), comp);
	int time6 = clock();
	printf("排序:%d\n", time6 - time5);

	//打印
	for (i = 0; i < 5; i++)
	{
		printf("%d ", sn[i].times);
		for (j = sen[sn[i].index].begin; j <= sen[sn[i].index].end; j++)
			fputc(all[j], stdout);
		fputc('\n', stdout);
	}
	for (i = 0; i < n; i++)
	{
		fprintf(write, "%d ", sn[i].times);
		for (j = sen[sn[i].index].begin; j <= sen[sn[i].index].end; j++)
			fputc(all[j], write);
		fputc('\n', write);
	}
	int time7 = clock();
	printf("打印:%d\n", time7 - time6);
	fclose(stop);
	fclose(read);
	fclose(write);
	return 0;
}

//把非停用词放入哈希表里
void HashInsert(hash* ph, char* s)
{
	ull key = HashKey(s);
	if (ph[key].times == 0)
	{
		strcpy(ph[key].words, s);
		ph[key].times = 1;
	}
	else
	{
		hash* cur = &ph[key];
		hash* prev = NULL;
		while (cur != NULL)
		{
			if (strcmp(s, cur->words) == 0)
			{
				cur->times++;
				return;
			}
			prev = cur;
			cur = cur->next;
		}
		if (cur == NULL)
		{
			cur = (hash*)malloc(sizeof(hash));
			strcpy(cur->words, s);
			cur->times = 1;
			cur->next = NULL;
			prev->next = cur;
		}
	}
}

//返回字符串的次数
int HashFind(hash* ph, char* s)
{
	ull key = HashKey(s);
	hash* cur = &ph[key];
	while (cur != NULL)
	{
		if (strcmp(cur->words, s) == 0)
			return cur->times;
		cur = cur->next;
	}
	return cur->times;
}

//哈希查找s是不是停用词
ull HashSearch(hash* ph, char* s)
{
	ull key = HashKey(s);
	hash* cur = &ph[key];
	while (cur != NULL)
	{
		if (strcmp(cur->words, s) == 0)
			return key;
		cur = cur->next;
	}
	return -1;
}

int comp(const void* a, const void* b)
{
	return ((*(sen_num*)b).times - (*(sen_num*)a).times);
}

ull HashKey(char *s)
{
	ull key = 0;
	while (*s != '\0')
		key = key * 26 + (ull)(*s++);
	return key % MOD;
}

//ull HashKey(char *s)
//{
//	ull key = 0;
//	int len = strlen(s) / 3;
//	int i = 0;
//	for (i = 0; i < len; i++)
//		key = key * 26 + *(s + i);
//	return key % MOD;
//}
