#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//2e5*5e3 = 1e9
//#define textNum 1000000005//文章的字符总个数+5,1e9
#define senNum 200000//句子个数
#define word_len 30//一个单词的长度

char st[10000][word_len];//放停用词，1e4个
typedef struct sentences
{
	int times;
	char sentence[5000];//句子
	char words[150][word_len];//单词
	int n;//一个句子中的单词个数
}sentences;
sentences sen[senNum];

typedef struct not_stopwords
{
	char words[word_len];
	int times;
	struct not_stopwords* left;
	struct not_stopwords* right;
}nst;

//放句子的序号(第几句)和次数
typedef struct sen_num
{
	int index;
	int times;
}sen_num;

nst* NstTreeInsert(nst* root, char* s);//把非停用词放入二叉查找树里
int BinarySearch1(char st[][word_len], int left, int right, const char* s);//二分查找s是不是停用词
int NstTreeFind(nst* root, char* s);//查找字符串在树中的位置，并返回它的次数
int comp(const void* a, const void* b);

//char all[textNum];
sen_num sn[senNum];

int main()
{
	FILE* read = fopen("article.txt", "r");//文章
	FILE* write = fopen("results.txt", "w");//输出
	FILE* stop = fopen("stopwords.txt", "r");//停用词

	int n;
	scanf("%d", &n);

	int i = 1, j = 0;
	//for (i = 0; i < 100000; i++)
	//	memset(st[i], 0, word_len);
	while (fscanf(stop, "%s", st[i]) != EOF)
		i++;
	int word_num = i;//停用词数，从1开始

	//把每一句话读入sentences里
	i = 0;
	while (1)
	{
		//按照字符读入
		char c = fgetc(read);
		if (c == EOF)
			break;
		//把句子读入sen
		if (c != '.' && c != '!' && c != '?')//句子分割标志
		{
			sen[i].sentence[j] = c;//原文章存入sentence
			j++;
		}
		else//一句话结束
		{
			//把最后的标点存入
			sen[i].sentence[j] = c;

			//删掉sentence句子前的空格
			int i2 = 0, tmp_len = strlen(sen[i].sentence);
			for (i2 = 0; i2 < tmp_len; i2++)
			{
				if (sen[i].sentence[i2] != ' ')
					break;
			}
			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';

			//读取下一句话
			i++;
			j = 0;
		}
	}
	int line = i;//句子个数，从0开始

	//把非停用词读到一个二叉查找树里
	rewind(read);
	char all_tmp[word_len] = { 0 };//暂时存储一个单词
	//memset(all_tmp, 0, word_len);

	//非停用词的二叉查找树的根
	nst* nst_root = NULL;
	int k = 0;
	//memset(all, 0, textNum);//all存整个文章
	
	//fread(all, 1, textNum - 5, read);//整个文章的长度
	//int len = strlen(all);

	for (i = 0; i < line; i++)
	{
		int len = strlen(sen[i].sentence);
		for (j = 0; j < len; j++)
		{
			if (!isalpha(sen[i].sentence[j]))//不是单词
				continue;
			else
			{
				k = 0;
				while (isalpha(sen[i].sentence[j]))//向all_tmp中读入一个单词
				{
					all_tmp[k] = tolower(sen[i].sentence[j]);
					j++;
					k++;
				}
				all_tmp[k] = '\0';

				int flag = BinarySearch1(st, 1, word_num, all_tmp);
				//不是停用词，放进二叉查找树里
				if (flag == -1)
				{
					nst_root = NstTreeInsert(nst_root, all_tmp);
					strcpy(sen[i].words[sen[i].n], all_tmp);//把这个单词放入结构体的单词表中
					sen[i].n++;
				}
			}
		}
	}

	//统计每句话的非停用词总次数
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < sen[i].n; j++)
		{
			char word_tmp[word_len] = { 0 };//存单词
			strcpy(word_tmp, sen[i].words[j]);
			int flag = BinarySearch1(st, 1, word_num, word_tmp);

			if (flag == -1)//是非停用词就计数
			{
				int word_times = NstTreeFind(nst_root, word_tmp);
				sen[i].times += word_times;
			}
		}	}

	//排序
	//memset(sn, 0, sizeof(sen_num)* senNum);
	for (i = 0; i < line; i++)
	{
		sn[i].index = i;//存句子的序号
		sn[i].times = sen[i].times;//存该序号句子的非停用词频度
	}
	qsort(sn, line, sizeof(sn[0]), comp);

	//打印
	for (i = 0; i < 5; i++)
		printf("%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence);
	for (i = 0; i < n; i++)
		fprintf(write, "%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence);

	fclose(stop);
	fclose(read);
	fclose(write);
	return 0;
}

nst* NstTreeInsert(nst* root, char* s)
{
	if (root == NULL)
	{
		root = (nst*)malloc(sizeof(nst));
		//if (root == NULL)
		//{
		//	printf("malloc fail\n");
		//	exit(-1);
		//}
		strcpy(root->words, s);
		root->left = NULL;
		root->right = NULL;
		root->times = 1;
	}
	else
	{
		//s和root的等，次数加一
		if (strcmp(s, root->words) == 0)
			root->times++;
		//s比root的大，往右放
		else if (strcmp(s, root->words) > 0)
			root->right = NstTreeInsert(root->right, s);
		else
			root->left = NstTreeInsert(root->left, s);
	}

	return root;
}

//返回-1说明不是停用词
int BinarySearch1(char st[][word_len], int left, int right, const char* s)
{
	while (left <= right)
	{
		int mid = (right + left) >> 1;
		if (strcmp(st[mid], s) < 0)
			left = mid + 1;
		else if (strcmp(st[mid], s) > 0)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}

//查找字符串在树中的位置，并返回它的次数
int NstTreeFind(nst* root, char* s)
{
	while (1)
	{
		if (strcmp(s, root->words) > 0)
			root = root->right;
		else if (strcmp(s, root->words) < 0)
			root = root->left;
		//相等
		else
			return root->times;
	}
}

int comp(const void* a, const void* b)
{
	sen_num pa = *(sen_num*)a;
	sen_num pb = *(sen_num*)b;

	return (pb.times - pa.times);
}