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
//#define senNum 200000//���Ӹ���
//#define word_len 30//һ�����ʵĳ���
//#define MOD 700005//��ϣ
//#define sen_words 200//һ�仰�еĵ��ʸ���������ʱ��ĳ�200����
//
//typedef struct sentences
//{
//	//int times;//�����з�ͣ�ô��ܴ���
//	//char sentence[5000];//����
//	char words[sen_words][word_len];
//	int n;//һ�������еĵ��ʸ���
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
////�ž��ӵ����(�ڼ���)�ʹ���
//typedef struct sen_num
//{
//	int index;
//	int times;
//}sen_num;
//
//ull HashKey(char *st);
//void HashInsert(hash* ph, char* s);//�ѷ�ͣ�ôʷ����ϣ����
//ull HashSearch(hash* ph, char* s);//��ϣ����s�ǲ���ͣ�ô�
//int HashFind(hash* ph, char* s);//���ط�ͣ�ôʵĴ���
//int comp(const void* a, const void* b);
//
//char all[article];
//sen_num sn[senNum];
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//����
//	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�
//	//int n = 20;
//	int n;
//	scanf("%d", &n);
//
//	//ͣ�ôʷŽ���ϣ��
//	char st_tmp[word_len] = { 0 };
//	while (fscanf(stop, "%s", st_tmp) != EOF)
//		HashInsert(sth, st_tmp);
//
//	int i = 0, j = 0, index = 0, k = 0;
//	fread(all, article - 5, 1, read);
//	int article_len = strlen(all);//ȫ�ĳ���
//	char all_tmp[word_len] = { 0 };//��ʱ�洢һ������
//
//	fclose(read);
//	fclose(stop);
//
//	while(index < article_len)//��������
//	{
//		if (j == 0)
//			sen[i].begin = index;
//
//		//����ĸ������all_tmp�������������ֱ��������ĸ
//		if (isalpha(all[index]))
//		{
//			k = 0;
//			while (isalpha(all[index]))//������Ӻ�all_tmp
//			{
//				all_tmp[k++] = tolower(all[index++]);
//				j++;
//			}
//			all_tmp[k] = '\0';
//
//			//����ͣ�ôʣ��Ž���ϣ��
//			if (HashSearch(sth, all_tmp) == -1)
//			{
//				HashInsert(h, all_tmp);
//				strcpy(sen[i].words[sen[i].n], all_tmp);//��������ʷ���ṹ��ĵ��ʱ���
//				sen[i].n++;
//			}
//		}
//
//		//�Ƿָ��־������ո�������һ�仰
//		else if (all[index] == '.' || all[index] == '!' || all[index] == '?')
//		{
//			sen[i].end = index;
//			//�������ǰ��Ŀո�
//			while (all[sen[i].begin] == ' ')
//				sen[i].begin++;
//			i++;
//			j = 0;
//			index++;
//		}
//		else//���
//		{
//			index++;
//			j++;
//		}
//	}
//	int line = i;//���Ӹ�������0��ʼ
//
//	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
//	for (i = 0; i < line; i++)
//	{
//		sn[i].index = i;//����ӵ����
//		for (j = 0; j < sen[i].n; j++)
//		{
//			if (HashSearch(sth, sen[i].words[j]) == -1)//�Ƿ�ͣ�ôʾͼ���
//				sn[i].times += HashFind(h, sen[i].words[j]);
//		}
//	}
//
//	//����
//	qsort(sn, line, sizeof(sn[0]), comp);
//
//	FILE* write = fopen("results.txt", "w");//���
//	//��ӡ
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
////�ѷ�ͣ�ôʷ����ϣ����
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
////�����ַ����Ĵ���
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
////��ϣ����s�ǲ���ͣ�ô�
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