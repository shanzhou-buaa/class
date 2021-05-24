#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//2e5*5e3 = 1e9
//#define textNum 1000000005//���µ��ַ��ܸ���+5,1e9
#define senNum 200000//���Ӹ���
#define word_len 30//һ�����ʵĳ���

char st[10000][word_len];//��ͣ�ôʣ�1e4��
typedef struct sentences
{
	int times;
	char sentence[5000];//����
	char words[150][word_len];//����
	int n;//һ�������еĵ��ʸ���
}sentences;
sentences sen[senNum];

typedef struct not_stopwords
{
	char words[word_len];
	int times;
	struct not_stopwords* left;
	struct not_stopwords* right;
}nst;

//�ž��ӵ����(�ڼ���)�ʹ���
typedef struct sen_num
{
	int index;
	int times;
}sen_num;

nst* NstTreeInsert(nst* root, char* s);//�ѷ�ͣ�ôʷ�������������
int BinarySearch1(char st[][word_len], int left, int right, const char* s);//���ֲ���s�ǲ���ͣ�ô�
int NstTreeFind(nst* root, char* s);//�����ַ��������е�λ�ã����������Ĵ���
int comp(const void* a, const void* b);

//char all[textNum];
sen_num sn[senNum];

int main()
{
	FILE* read = fopen("article.txt", "r");//����
	FILE* write = fopen("results.txt", "w");//���
	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�

	int n;
	scanf("%d", &n);

	int i = 1, j = 0;
	//for (i = 0; i < 100000; i++)
	//	memset(st[i], 0, word_len);
	while (fscanf(stop, "%s", st[i]) != EOF)
		i++;
	int word_num = i;//ͣ�ô�������1��ʼ

	//��ÿһ�仰����sentences��
	i = 0;
	while (1)
	{
		//�����ַ�����
		char c = fgetc(read);
		if (c == EOF)
			break;
		//�Ѿ��Ӷ���sen
		if (c != '.' && c != '!' && c != '?')//���ӷָ��־
		{
			sen[i].sentence[j] = c;//ԭ���´���sentence
			j++;
		}
		else//һ�仰����
		{
			//�����ı�����
			sen[i].sentence[j] = c;

			//ɾ��sentence����ǰ�Ŀո�
			int i2 = 0, tmp_len = strlen(sen[i].sentence);
			for (i2 = 0; i2 < tmp_len; i2++)
			{
				if (sen[i].sentence[i2] != ' ')
					break;
			}
			memcpy(sen[i].sentence, sen[i].sentence + i2, strlen(sen[i].sentence) - i2);
			sen[i].sentence[strlen(sen[i].sentence) - i2] = '\0';

			//��ȡ��һ�仰
			i++;
			j = 0;
		}
	}
	int line = i;//���Ӹ�������0��ʼ

	//�ѷ�ͣ�ôʶ���һ�������������
	rewind(read);
	char all_tmp[word_len] = { 0 };//��ʱ�洢һ������
	//memset(all_tmp, 0, word_len);

	//��ͣ�ôʵĶ���������ĸ�
	nst* nst_root = NULL;
	int k = 0;
	//memset(all, 0, textNum);//all����������
	
	//fread(all, 1, textNum - 5, read);//�������µĳ���
	//int len = strlen(all);

	for (i = 0; i < line; i++)
	{
		int len = strlen(sen[i].sentence);
		for (j = 0; j < len; j++)
		{
			if (!isalpha(sen[i].sentence[j]))//���ǵ���
				continue;
			else
			{
				k = 0;
				while (isalpha(sen[i].sentence[j]))//��all_tmp�ж���һ������
				{
					all_tmp[k] = tolower(sen[i].sentence[j]);
					j++;
					k++;
				}
				all_tmp[k] = '\0';

				int flag = BinarySearch1(st, 1, word_num, all_tmp);
				//����ͣ�ôʣ��Ž������������
				if (flag == -1)
				{
					nst_root = NstTreeInsert(nst_root, all_tmp);
					strcpy(sen[i].words[sen[i].n], all_tmp);//��������ʷ���ṹ��ĵ��ʱ���
					sen[i].n++;
				}
			}
		}
	}

	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < sen[i].n; j++)
		{
			char word_tmp[word_len] = { 0 };//�浥��
			strcpy(word_tmp, sen[i].words[j]);
			int flag = BinarySearch1(st, 1, word_num, word_tmp);

			if (flag == -1)//�Ƿ�ͣ�ôʾͼ���
			{
				int word_times = NstTreeFind(nst_root, word_tmp);
				sen[i].times += word_times;
			}
		}	}

	//����
	//memset(sn, 0, sizeof(sen_num)* senNum);
	for (i = 0; i < line; i++)
	{
		sn[i].index = i;//����ӵ����
		sn[i].times = sen[i].times;//�����ž��ӵķ�ͣ�ô�Ƶ��
	}
	qsort(sn, line, sizeof(sn[0]), comp);

	//��ӡ
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
		//s��root�ĵȣ�������һ
		if (strcmp(s, root->words) == 0)
			root->times++;
		//s��root�Ĵ����ҷ�
		else if (strcmp(s, root->words) > 0)
			root->right = NstTreeInsert(root->right, s);
		else
			root->left = NstTreeInsert(root->left, s);
	}

	return root;
}

//����-1˵������ͣ�ô�
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

//�����ַ��������е�λ�ã����������Ĵ���
int NstTreeFind(nst* root, char* s)
{
	while (1)
	{
		if (strcmp(s, root->words) > 0)
			root = root->right;
		else if (strcmp(s, root->words) < 0)
			root = root->left;
		//���
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