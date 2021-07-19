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
//#define MOD 50001
//#define sen_words 200//һ�仰�еĵ��ʸ���
//
//typedef unsigned long long ull;
//typedef struct sentences
//{
//	int begin;
//	int end;
//	char words[sen_words][word_len];//���ʣ�����ʱ��ĳ�200����
//	int n;//һ�������еĵ��ʸ���
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
////�ž��ӵ����(�ڼ���)�ʹ���
//typedef struct sen_num
//{
//	int index;
//	int times;
//}sen_num;
//
//ull HashKey(char *st);
//hash* _HashInsert(hash* h, char* s);
//void HashInsert(hash* ph, char* s);//�ѷ�ͣ�ôʷ����ϣ����
//int BinarySearch1(char st[][word_len], int left, int right, const char* s);//���ֲ���s�ǲ���ͣ�ô�
//ull HashSearch(hash* ph, char* s);//��ϣ����s�ǲ���ͣ�ô�
//int _HashFind(hash* h, char* s);
//int HashFind(hash* ph, char* s);//�����ַ����Ĵ���
//int comp(const void* a, const void* b);
//
//sen_num sn[senNum];
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//����
//	FILE* write = fopen("results.txt", "w");//���
//	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�
//
//	int n;
//	scanf("%d", &n);
//
//	int time1 = clock();
//
//	//ͣ�ôʷŽ���ϣ��
//	char st_tmp[word_len] = { 0 };
//	while (fscanf(stop, "%s", st_tmp) != EOF)
//		HashInsert(sth, st_tmp);
//
//	int time2 = clock();
//	printf("ͣ�ôʷŽ���ϣ��:%d\n", time2 - time1);
//	//��ÿһ�仰����sentences��
//	int i = 0, j = 0, index = 0;
//	int	line = 0;//���Ӹ�������0��ʼ
//	fread(all, article - 5, 1, read);
//	int time8 = clock();
//	int article_len = strlen(all);
//	for (index = 0; index < article_len; index++)
//	{
//		//�����ַ�����
//		char c = all[index];
//	
//		//�Ѿ��Ӷ���sen
//		if (c != '?' && c != '.' && c != '!')//���ӷָ��־
//		{
//			if (j == 0)
//				sen[line].begin = index;
//			j = 1;
//		}
//		else//һ�仰����
//		{
//			//���ı��
//			sen[line].end = index;
//	
//			//ɾ��sentence����ǰ�Ŀո�
//			while (all[sen[line].begin] == ' ')
//				sen[line].begin++;
//	
//			//��ȡ��һ�仰
//			line++;
//			j = 0;
//		}
//	}
//
//	int time3 = clock();
//	printf("��ÿһ�仰����sentences��:%d\n", time3 - time8);
//
//	//�ѷ�ͣ�ôʶ���һ�������������
//	rewind(read);
//	//�ѷ�ͣ�ôʶ�����ϣ����
//	char all_tmp[word_len] = { 0 };//��ʱ�洢һ������
//	int k = 0;
//	for (i = 0; i < line; i++)
//	{
//		int len = sen[i].end - sen[i].begin;
//		for (j = 0; j < len; j++)
//		{
//			if (isalpha(all[sen[i].begin + j]))//����ĸ
//			{
//				k = 0;
//				while (isalpha(all[sen[i].begin + j]))//��all_tmp�ж���һ������
//				{
//					all_tmp[k] = tolower(all[sen[i].begin + j]);
//					k++;
//					j++;
//				}
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
//
//	int time4 = clock();
//	printf("�ѷ�ͣ�ôʶ�����ϣ����:%d\n", time4 - time3);
//
//	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
//	i = 0;
//	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
//	for (i = 0; i < line; i++)
//	{
//		for (j = 0; j < sen[i].n; j++)
//				sn[i].times += HashFind(h, sen[i].words[j]);
//		sn[i].index = i;//����ӵ����
//	}
//
//	int time5 = clock();
//	printf("ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���:%d\n", time5 - time4);
//
//	//����
//	qsort(sn, line, sizeof(sn[0]), comp);
//	int time6 = clock();
//	printf("����:%d\n", time6 - time5);
//
//	//��ӡ
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
//	printf("��ӡ:%d\n", time7 - time6);
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
//		//s��keyλ�õ���ȴ���ֱ��++
//		if (strcmp(s, h->words) == 0)
//			h->times++;
//		//s��keyλ�õ��ַ�����ȥ�ұ�
//		else if (strcmp(s, h->words) > 0)
//			h->right = _HashInsert(h->right, s);
//		//s��keyλ�õ��ַ�����ȥ�ұ�
//		else
//			h->left = _HashInsert(h->left, s);
//	}
//	return h;
//}
//
////�ѷ�ͣ�ôʷ����ϣ����
//void HashInsert(hash* ph, char* s)
//{
//	ull key = HashKey(s);
//	_HashInsert(&ph[key], s);
//}
//
////����-1˵������ͣ�ô�
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
////��ϣ����s�ǲ���ͣ�ô�
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
////�����ַ����Ĵ���
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