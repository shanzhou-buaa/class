#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define textNum 7000005//���µ��ַ��ܸ���+5
#define senNum 300000//���Ӹ���
#define wordn 200//һ�����ʵĳ���

char st[10000][wordn];//��ͣ�ô�
typedef struct sentences
{
	int times;
	char sentence[5000];//����
}sentences;
sentences sen[senNum];

typedef struct not_stopwords
{
	char words[wordn];
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

nst* NstTreeInsert(nst* root, char* s);//�ѷ�ͣ�ôʶ���һ�������������
int BinarySearch1(char st[][wordn], int left, int right, const char* s);//���ֲ���s�ǲ���ͣ�ô�
int NstTreeFind(nst* root, char* s);//�����ַ��������е�λ�ã����������Ĵ���
int comp(const void* a, const void* b);

char all[textNum];
sen_num sn[senNum];

int main()
{
	FILE* read = fopen("article.txt", "r");//����
	FILE* write = fopen("results.txt", "w");//���
	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�

	int n;
	scanf("%d", &n);

	memset(st, 0, 10000 * wordn);
	int i = 1, j = 0;
	while (fscanf(stop, "%s", st[i]) != EOF)
		i++;
	int wordNum = i;//ͣ�ô�������1��ʼ

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
			for (; i2 < tmp_len; i2++)
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
	int line = i;//������������0��ʼ

	//�ѷ�ͣ�ôʶ���һ�������������
	rewind(read);
	char all_tmp[wordn];//��ʱ�洢һ������
	memset(all_tmp, 0, wordn);

	//��ͣ�ôʵĶ���������ĸ�
	nst* nst_root = NULL;
	memset(all, 0, textNum);//all����������
	int len = fread(all, 1, textNum - 5, read);//�������µĳ���
	for (i = 0; i < len; i++)
	{
		if (all[i] == ' ' || all[i] == '.' || all[i] == '!' || all[i] == '?')//���ǵ���
			continue;
		else
		{
			j = 0;
			while (isalpha(all[i]))//��all_tmp�ж���һ������
			{
				all_tmp[j] = tolower(all[i]);
				i++;
				j++;
			}
			all_tmp[j] = '\0';

			int flag = BinarySearch1(st, 1, wordNum, all_tmp);

			//����ͣ�ôʣ��Ž������������
			if (flag == -1)
				nst_root = NstTreeInsert(nst_root, all_tmp);
		}
	}

	//ͳ��ÿ�仰�ķ�ͣ�ô��ܴ���
	int k = 0;
	for (i = 0; i < line; i++)
	{
		int len = strlen(sen[i].sentence);
		char word_tmp[wordn];//�浥��
		memset(word_tmp, 0, wordn);

		j = 0;
		while (j < len)
		{
			k = 0;
			if (!isalpha(sen[i].sentence[j]))
			{
				j++;
				continue;
			}

			//��һ������
			while (isalpha(sen[i].sentence[j]))
			{
				word_tmp[k] = tolower(sen[i].sentence[j]);
				k++;
				j++;
			}
			word_tmp[k] = '\0';

			int flag = BinarySearch1(st, 1, wordNum, word_tmp);

			if (flag == -1)//�Ƿ�ͣ�ôʾͼ���
			{
				int word_times = NstTreeFind(nst_root, word_tmp);
				sen[i].times += word_times;
			}
		}
	}

	//����
	memset(sn, 0, sizeof(sen_num)* senNum);
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
int BinarySearch1(char st[][wordn], int left, int right, const char* s)
{
	int mid = left + ((right - left) >> 1);
	while (left <= right)
	{
		if (strcmp(st[mid], s) < 0)
		{
			left = mid + 1;
			mid = left + ((right - left) >> 1);
		}
		else if (strcmp(st[mid], s) > 0)
		{
			right = mid - 1;
			mid = left + ((right - left) >> 1);
		}
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