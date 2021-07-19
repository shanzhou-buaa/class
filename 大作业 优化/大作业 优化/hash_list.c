//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define article 7000005
//#define senNum 200000//���Ӹ���
//#define word_len 30//һ�����ʵĳ���
//#define MOD 70005
//#define sen_words 200//һ�仰�еĵ��ʸ���
//
//typedef struct sentences
//{
//	int times;//�����з�ͣ�ô��ܴ���
//	char sentence[5000];//����
//	char words[sen_words][word_len];//���ʣ�����ʱ��ĳ�200����
//	int n;//һ�������еĵ��ʸ���
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
////�ž��ӵ����(�ڼ���)�ʹ���
//typedef struct sen_num
//{
//	int index;
//	int times;
//}sen_num;
//
//unsigned long long HashKey(char *st);
//void HashInsert(hash* ph, char* s);//�ѷ�ͣ�ôʷ����ϣ����
//int HashSearch(hash* ph, char* s);//��ϣ����s�ǲ���ͣ�ô�
//int HashFind(hash* ph, char* s);//���ط�ͣ�ôʵĴ���
//int comp(const void* a, const void* b);
////void ListNum(hash* h);
//
//char all[article];
//sen_num sn[senNum];
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//����
//	FILE* write = fopen("results.txt", "w");//���
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
//	//��ÿһ�仰����sentences��
//	int i = 0, j = 0, index = 0;
//	fread(all, article - 5, 1, read);
//	int article_len = strlen(all);
//	int time1 = clock();
//	for (index = 0; index < article_len; index++)
//	{
//		//�����ַ�����
//		char c = all[index];
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
//			for (i2 = 0; i2 < tmp_len; i2++)
//			{
//				if (sen[i].sentence[i2] != ' ')
//					break;
//			}
//			//sen[i].space = i2;
//			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
//			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';
//
//			//��ȡ��һ�仰
//			i++;
//			j = 0;
//		}
//	}
//	int line = i;//���Ӹ�������0��ʼ
//
//	//�ѷ�ͣ�ôʶ�����ϣ����
//	rewind(read);
//	char all_tmp[word_len] = { 0 };//��ʱ�洢һ������
//	int k = 0;
//	for (i = 0; i < line; i++)
//	{
//		int len = strlen(sen[i].sentence);
//		for (j = 0; j < len; j++)
//		{
//			if (isalpha(sen[i].sentence[j]))//����ĸ
//			{
//				k = 0;
//				while (isalpha(sen[i].sentence[j]))//��all_tmp�ж���һ������
//					all_tmp[k++] = tolower(sen[i].sentence[j++]);
//				all_tmp[k] = '\0';
//
//				//����ͣ�ôʣ��Ž���ϣ��
//				if (HashSearch(sth, all_tmp) == -1)
//				{
//					HashInsert(h, all_tmp);
//					strcpy(sen[i].words[sen[i].n], all_tmp);//��������ʷ���ṹ��ĵ��ʱ���
//					sen[i].n++;
//				}
//			}
//		}
//	}
//	int time2 = clock();
//	printf("%d\n", time2 - time1);
//	//ListNum(h);
//	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < sen[i].n; j++)
//		{
//			if (HashSearch(sth, sen[i].words[j]) == -1)//�Ƿ�ͣ�ôʾͼ���
//			{
//				int word_times = HashFind(h, sen[i].words[j]);
//				sen[i].times += word_times;
//			}
//		}
//		sn[i].index = i;//����ӵ����
//		sn[i].times = sen[i].times;//�����ž��ӵķ�ͣ�ô�Ƶ��
//	}
//
//	//����
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
////�ѷ�ͣ�ôʷ����ϣ����
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
////�����ַ����Ĵ���
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
////��ϣ����s�ǲ���ͣ�ô�
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