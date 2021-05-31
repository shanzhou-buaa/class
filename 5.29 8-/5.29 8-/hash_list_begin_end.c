#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long ull;
#define article 7000005
#define senNum 200000//���Ӹ���
#define word_len 30//һ�����ʵĳ���
#define MOD 100005
#define sen_words 200//һ�仰�еĵ��ʸ���

typedef struct sentences
{
	char words[sen_words][word_len];
	int n;//һ�������еĵ��ʸ���
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

//�ž��ӵ����(�ڼ���)�ʹ���
typedef struct sen_num
{
	int index;
	int times;
}sen_num;

ull HashKey(char *st);
void HashInsert(hash* ph, char* s);//�ѷ�ͣ�ôʷ����ϣ����
ull HashSearch(hash* ph, char* s);//��ϣ����s�ǲ���ͣ�ô�
int HashFind(hash* ph, char* s);//���ط�ͣ�ôʵĴ���
int comp(const void* a, const void* b);

char all[article];
sen_num sn[senNum];

int main()
{
	FILE* read = fopen("article.txt", "r");//����
	FILE* write = fopen("results.txt", "w");//���
	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�
	
	int n;
	scanf("%d", &n);

	int time1 = clock();
	//ͣ�ôʷŽ���ϣ��
	char st_tmp[word_len] = { 0 };
	while (fscanf(stop, "%s", st_tmp) != EOF)
		HashInsert(sth, st_tmp);
	int time2 = clock();
	printf("ͣ�ôʷŽ���ϣ��:%d\n", time2 - time1);

	//�ҵ�sentences��begin��end
	int i = 0, j = 0, index = 0;
	int	line = 0;//���Ӹ�������0��ʼ
	fread(all, article - 5, 1, read);
	int time8 = clock();
	printf("�����£�%d\n", time8 - time2);
	int article_len = strlen(all);
	for (index = 0; index < article_len; index++)
	{
		//�����ַ�����
		char c = all[index];

		//�Ѿ��Ӷ���sen
		if (c != '?' && c != '.' && c != '!')//���ӷָ��־
		{
			if (j == 0)
				sen[line].begin = index;
			j = 1;
		}
		else//һ�仰����
		{
			//���ı��
			sen[line].end = index;

			//ɾ��sentence����ǰ�Ŀո�
			while (all[sen[line].begin] == ' ')
				sen[line].begin++;

			//��ȡ��һ�仰
			line++;
			j = 0;
		}
	}
	int time3 = clock();
	printf("��ÿһ�仰����sentences��:%d\n", time3 - time8);

	//�ѷ�ͣ�ôʶ�����ϣ����
	char all_tmp[word_len] = { 0 };//��ʱ�洢һ������
	int k = 0;
	for (i = 0; i < line; i++)
	{
		int len = sen[i].end - sen[i].begin;
		for (j = 0; j < len; j++)
		{
			if (isalpha(all[sen[i].begin + j]))//����ĸ
			{
				k = 0;
				while (isalpha(all[sen[i].begin + j]))//��all_tmp�ж���һ������
				{
					all_tmp[k] = tolower(all[sen[i].begin + j]);
					k++;
					j++;
				}
				all_tmp[k] = '\0';

				//����ͣ�ôʣ��Ž���ϣ��
				if (HashSearch(sth, all_tmp) == -1)
				{
					HashInsert(h, all_tmp);
					strcpy(sen[i].words[sen[i].n], all_tmp);//��������ʷ���ṹ��ĵ��ʱ���
					sen[i].n++;
				}
			}
		}
	}	
	int time4 = clock();
	printf("�ѷ�ͣ�ôʶ�����ϣ����:%d\n", time4 - time3);

	//i = 0;
	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < sen[i].n; j++)
				sn[i].times += HashFind(h, sen[i].words[j]);
		sn[i].index = i;//����ӵ����
	}
	int time5 = clock();
	printf("ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���:%d\n", time5 - time4);

	//����
	qsort(sn, line, sizeof(sn[0]), comp);
	int time6 = clock();
	printf("����:%d\n", time6 - time5);

	//��ӡ
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
	printf("��ӡ:%d\n", time7 - time6);
	fclose(stop);
	fclose(read);
	fclose(write);
	return 0;
}

//�ѷ�ͣ�ôʷ����ϣ����
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

//�����ַ����Ĵ���
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

//��ϣ����s�ǲ���ͣ�ô�
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
