//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
////sentence结构体每个句子的下标和对应的次数
//typedef struct sen_num
//{
//	int times;
//	int index;
//}sen_num;
//
//typedef struct sentences
//{
//	int times;
//	char sentence[5000];//原句子
//}sentences;
//
//
//typedef struct not_stop_words
//{
//	char words[50];
//	int times;
//}nstopwords;
//
////2e5 *	5e3 = 1e9
//nstopwords nst[40000];//非停用词
//char st[1000][50];//停用词 1~320
//sentences sen[200000];//句子 1~31032
//char all[3000005] = { 0 };//统计非停用词时一次从文章中读这么多个字符
//
//int BinarySearch1(const char* st, int left, int right, const char* s);
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//文章
//	FILE* write = fopen("results.txt", "w");//输出
//	FILE* stop = fopen("stopwords.txt", "r");//停用词
//
//	int n;
//	scanf("%d", &n);
//	//int n = 200;
//
//	//把停用词读到stopwords数组里
//	int i = 1, j = 0, k = 1;
//	while (fscanf(stop, "%s", st[i]) != EOF)//每个词末尾有\n
//	{
//		//st[i].times = 0;//停用词次数置为0
//		i++;
//	}
//	int wordNum = i;//停用词数，从1开始
//
//	//把每一句话读入sentences里
//	i = 1;
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
//			int i2 = 0;
//			for (; i2 < strlen(sen[i].sentence); i2++)
//			{
//				if (sen[i].sentence[i2] != ' ')
//					break;
//			}
//			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
//			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';
//
//			i++;
//			j = 0;
//		}
//	}
//	int line = i;//句子行数，从1开始
//
//	//读入整个文章，统计每个非停用词的频度
//	rewind(read);//把read放回文件开头
//	int len = 0, index = 1;//index是非停用词数组的大小
//	while (fgets(all, 3000000, read) != NULL)
//	{
//		char temp[50];
//		len = strlen(all);
//		for (i = 0; i < len; i++)//从开头遍历读入的文章
//		{
//			if (all[i] == ' ' || all[i] == '.' || all[i] == '!' || all[i] == '?')//不是单词
//				continue;
//			else
//			{
//				j = 0;
//				while (isalpha(all[i]))//向temp中读入一个单词
//				{
//					if (isupper(all[i]))
//						temp[j] = all[i] + 32;
//					else
//						temp[j] = all[i];
//					i++;
//					j++;
//				}
//
//				temp[j] = '\0';//补\0结束字符串
//
//				int flag = BinarySearch1(st, 1, wordNum, temp);//flag不是-1说明是停用词
//				if (flag == -1)//temp中的单词不是停用词
//				{
//					int m, sign = 1;//sign是1说明这个非停用词没被记录过
//					for (m = 1; m <= index; m++)//依次和非停用词的数组比较
//					{
//						if (strcmp(temp, nst[m].words) == 0)
//						{
//							sign = 0;
//							nst[m].times++;//如果这个非停用词已经被记录过，次数+1
//							break;
//						}
//					}
//					if (sign)
//					{
//						strcpy(nst[index].words, temp);
//						nst[index].times = 1;
//						index++;
//					}
//				}
//			}
//		}
//	}
//
//	//统计每个句子中非停用词频度之和
//	for (i = 1; i <= line; i++)
//	{
//		len = strlen(sen[i].sentence);
//		for (k = 0; k < len; k++)
//		{
//			char temp[50] = { 0 };
//			j = 0;
//			while (isalpha(sen[i].sentence[k]) && k < len)//向temp中读入句子中的一个单词
//			{
//				temp[j] = tolower(sen[i].sentence[k]);
//				k++;//newsentence往后挪
//				j++;//temp往后挪
//			}
//			temp[j] = '\0';//补\0结束字符串
//
//			int flag = 1;//flag是1说明temp中的单词是非停用词
//			for (j = 1; j <= wordNum; j++)//与所有停用词比较
//			{
//				if (strcmp(temp, st[j]) == 0)
//				{
//					flag = 0;//flag是0说明temp中的单词是停用词
//					break;
//				}
//			}
//			if (flag)
//			{
//				int l;
//				//index是非停用词数组的大小
//				//l遍历非停用词数组
//				for (l = 1; l <= index; l++)
//				{
//					//该句子中含有第l个非停用词
//					if (strcmp(nst[l].words, temp) == 0)
//					{
//						sen[i].times += nst[l].times;//句子的非停用词次数加上该非停用词的次数
//					}
//				}
//			}
//		}
//	}
//
//	sen_num sn[50000];
//	memset(sn, 0, sizeof(sn));
//	for (i = 1; i <= line; i++)
//	{
//		sn[i].index = i;//存句子的序号
//		sn[i].times = sen[i].times;//存该序号句子的非停用词频度
//	}
//
//	//冒泡排序排sn数组的times
//	for (i = 1; i <= line; i++)
//	{
//		int flag1 = 1;
//		for (j = 1; j <= line - 1 - i; j++)
//		{
//			if (sn[j].times < sn[j + 1].times)
//			{
//				sen_num tmp;
//				tmp.index = sn[j].index;
//				tmp.times = sn[j].times;
//
//				sn[j].index = sn[j + 1].index;
//				sn[j].times = sn[j + 1].times;
//
//				sn[j + 1].index = tmp.index;
//				sn[j + 1].times = tmp.times;
//
//				flag1 = 0;
//			}
//		}
//		if (flag1)
//			break;
//	}
//
//	//输出
//	for (i = 1; i <= 5; i++)
//		printf("%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence + j);
//	for (i = 1; i <= n; i++)
//		fprintf(write, "%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence + j);
//
//	fclose(stop);
//	fclose(read);
//	fclose(write);
//	return 0;
//}
//
//int BinarySearch1(char st[][50], int left, int right, const char* s)
//{
//	int mid = (left + right) / 2;
//	while (left <= right)
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