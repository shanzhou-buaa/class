#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

//sentence�ṹ��ÿ�����ӵ��±�Ͷ�Ӧ�Ĵ���
typedef struct sen_num
{
	int times;
	int index;
}sen_num;

typedef struct sentences
{
	int times;
	char sentence[5000];//ԭ����
	char newsentence[5000];//ȫСд
}sentences;

typedef struct stopwords
{
	char words[50];
	int times;
}stopwords;

typedef struct not_stop_words
{
	char words[50];
	int times;
}nstopwords;

//2e5 *	5e3 = 1e9
nstopwords nst[30000];//��ͣ�ô�
stopwords st[1000];//ͣ�ô� 1~320
sentences sen[50000];//���� 1~31032
char all[3000000] = { 0 };//ͳ�Ʒ�ͣ�ô�ʱһ�δ������ж���ô����ַ�

int BinarySearch1(const stopwords* st, int left, int right, const char* s);

int main()
{
	FILE* read = fopen("article.txt", "r");//����
	FILE* write = fopen("results.txt", "w");//���
	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�

	int n;
	scanf("%d", &n);
	//int n = 200;

	//��ͣ�ôʶ���stopwords������
	int i = 1, j = 0, k = 1;
	while (fscanf(stop, "%s", st[i].words) != EOF)//ÿ����ĩβ��\n
	{
		st[i].times = 0;//ͣ�ôʴ�����Ϊ0
		i++;
	}
	int wordNum = i;//ͣ�ô�������1��ʼ
	
	//��ÿһ�仰����sentences��
	i = 1;
	//int size = 0;//ĳ�����ӵĵ��ʸ���
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
			//ȫСд����newsentence
			if (isupper(c))
			{
				c += 32;
				sen[i].newsentence[j] = c;
			}
			else
				sen[i].newsentence[j] = c;
			j++;
		}
		//Mr.��һ�仰
		//else if (c == '.' && sen[i].newsentence[j - 1] == 'r'&&sen[i].newsentence[j - 2] == 'm')//Mr.���������
		//{
		//	sen[i].sentence[j] = c;
		//	sen[i].newsentence[j] = c;
		//	j++;
		//}
		else//һ�仰����
		{
			//�����ı�����
			sen[i].sentence[j] = c;
			sen[i].newsentence[j] = c;

			//ɾ��newsentence����ǰ�Ŀո�
			int i2 = 0;
			for (; i2 < strlen(sen[i].newsentence); i2++)
			{
				if (sen[i].newsentence[i2] != ' ')
					break;
			}
			memcpy(sen[i].newsentence, sen[i].newsentence + i2, strlen(sen[i].newsentence) - i2);
			sen[i].newsentence[strlen(sen[i].newsentence) - i2] = '\0';

			//char temp_word[1000][500];
			////��һ�仰��ÿ�����ʶ�����temp_word
			////ÿ���¶���һ������ʱ����֮ǰ���еĵ��ʱȽ�
			////����ظ������ڸ�λ�ö�����һ������(��������ظ��ĵ���)
			//int i1 = 0;
			//while (sscanf(sen[i].newsentence, "%s", temp_word[size]) != EOF)
			//{
			//	//���ַ�����ǰ�ƶ�һ�����ʼ�һ���ո�ľ���
			//	int temp_len = strlen(temp_word[size]) + 1;
			//	int total_len = strlen(sen[i].newsentence);
			//	if (total_len >= temp_len)
			//	{
			//		memcpy(sen[i].newsentence, sen[i].newsentence + temp_len, total_len - temp_len);
			//		sen[i].newsentence[total_len - temp_len] = '\0';
			//	}
			//	else
			//		sen[i].newsentence[0] = '\0';

			//	//û���ĵ���
			//	char no_punc[50] = { 0 };
			//	int j1 = 0;
			//	for (i1 = 0, j1 = 0; i1 < temp_len - 1; i1++)
			//	{
			//		if (isalpha(temp_word[size][i1]))
			//			no_punc[j1++] = temp_word[size][i1];
			//	}
			//	no_punc[j1] = '\0';
			//	int x = 1;//x = 1˵��û���ظ��ĵ���
			//	for (i1 = 0; i1 < size; i1++)
			//	{
			//		if (strcmp(temp_word[i1], no_punc) == 0)
			//		{
			//			x = 0;
			//			break;
			//		}
			//	}
			//	if (x == 1)
			//		size++;
			//}
			////temp_word�д���Ǹþ����д�ǰ�����ظ��ĵ���

			//for (i1 = 0; i1 < size; i1++)
			//{
			//	strcat(sen[i].newsentence, temp_word[i1]);
			//	if (i1 != size - 1)//�������һ�����ʾͲ����ո�
			//		strcat(sen[i].newsentence, " ");
			//}
			i++;
			j = 0;
		}
	}
	int line = i;//������������1��ʼ

	//�����������£�ͳ��ÿ����ͣ�ôʵ�Ƶ��
	rewind(read);//��read�Ż��ļ���ͷ
	int len = 0, index = 1;//index�Ƿ�ͣ�ô�����Ĵ�С
	while (fgets(all, 3000000, read) != NULL)
	{
		char temp[50];
		len = strlen(all);
		for (i = 0; i < len; i++)//�ӿ�ͷ�������������
		{
			if (all[i] == ' ' || all[i] == '.' || all[i] == '!' || all[i] == '?')//���ǵ���
				continue;
			else
			{
				j = 0;
				while (isalpha(all[i]))//��temp�ж���һ������
				{
					if (isupper(all[i]))
						temp[j] = all[i] + 32;
					else
						temp[j] = all[i];
					i++;
					j++;
				}
				//temp[j++] = '\n';//temp��һ������ĩβ��\n
				temp[j] = '\0';//��\0�����ַ���

				//if (strcmp(temp, "harrylockhart\n") == 0)
				//	printf("i : %d\n", i);

				int flag = BinarySearch1(st, 1, wordNum, temp);//flag����-1˵����ͣ�ô�

				//for (k = 1; k <= wordNum; k++)//������ͣ�ôʱȽ�
				//{
				//	if (strcmp(temp, st[k].words) == 0)
				//	{
				//		flag = 0;//temp�еĵ�����ͣ�ô�
				//		break;
				//	}
				//}

				if (flag == -1)//temp�еĵ��ʲ���ͣ�ô�
				{
					int m, sign = 1;//sign��1˵�������ͣ�ô�û����¼��
					for (m = 1; m <= index; m++)//���κͷ�ͣ�ôʵ�����Ƚ�
					{
						if (strcmp(temp, nst[m].words) == 0)
						{
							sign = 0;
							nst[m].times++;//��������ͣ�ô��Ѿ�����¼��������+1
							break;
						}
					}
					if (sign)
					{
						strcpy(nst[index].words, temp);
						nst[index].times = 1;
						index++;
					}
				}
			}
		}
	}

	//for (i = 1; i <= index; i++)
	//{
	//	if (nst[i].words[0] == 'h' && nst[i].words[1] == 'a' && nst[i].words[2] == 'r'&& nst[i].words[3] == 'r')
	//		printf("index:%d %d:%s", i, nst[i].times, nst[i].words);
	//}
	//printf("\n\n\n");

	//ͳ��ÿ�������з�ͣ�ô�Ƶ��֮��
	for (i = 1; i <= line; i++)
	{
		len = strlen(sen[i].newsentence);
		for (k = 0; k < len; k++)
		{
			char temp[50] = { 0 };
			j = 0;
			while (isalpha(sen[i].newsentence[k]) && k < len)//��temp�ж�������е�һ������
			{
				temp[j] = sen[i].newsentence[k];
				k++;//newsentence����Ų
				j++;//temp����Ų
			}
			//temp[j++] = '\n';//temp��һ�����ʣ�ĩβ��\n
			temp[j] = '\0';//��\0�����ַ���

			//û��������
			//if (strcmp(temp, "\n") == 0)
			//	continue;

			int flag = 1;//flag��1˵��temp�еĵ����Ƿ�ͣ�ô�
			for (j = 1; j <= wordNum; j++)//������ͣ�ôʱȽ�
			{
				if (strcmp(temp, st[j].words) == 0)
				{
					flag = 0;//flag��0˵��temp�еĵ�����ͣ�ô�
					break;
				}
			}
			if (flag)
			{
				int l;
				//index�Ƿ�ͣ�ô�����Ĵ�С
				//l������ͣ�ô�����
				for (l = 1; l <= index; l++)
				{
					//�þ����к��е�l����ͣ�ô�
					if (strcmp(nst[l].words, temp) == 0)
					{
						sen[i].times += nst[l].times;//���ӵķ�ͣ�ôʴ������ϸ÷�ͣ�ôʵĴ���
					}
				}
			}
		}
	}

	sen_num sn[50000];
	memset(sn, 0, sizeof(sn));
	for (i = 1; i <= line; i++)
	{
		sn[i].index = i;//����ӵ����
		sn[i].times = sen[i].times;//�����ž��ӵķ�ͣ�ô�Ƶ��
	}
	//sn
	//{{5,500},{4,400},{10,200},{50,180},{66,20}...{500,1}}
	//    1      2       3         4      5    ... line

	//ð��������sn�����times
	for (i = 1; i <= line; i++)
	{
		int flag1 = 1;
		for (j = 1; j <= line - 1 - i; j++)
		{
			if (sn[j].times < sn[j + 1].times)
			{
				sen_num tmp;
				tmp.index = sn[j].index;
				tmp.times = sn[j].times;

				sn[j].index = sn[j + 1].index;
				sn[j].times = sn[j + 1].times;

				sn[j + 1].index = tmp.index;
				sn[j + 1].times = tmp.times;

				flag1 = 0;
			}
		}
		if (flag1)
			break;
	}
	
	//���
	for (i = 1; i <= 5; i++)
	{
		j = 0;
		while (sen[sn[i].index].sentence[j] == ' ')//ȥ������ǰ��Ŀո�
			j++;
		printf("%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence + j);
	}
	for (i = 1; i <= n; i++)
	{
		j = 0;
		while (sen[sn[i].index].sentence[j] == ' ')
			j++;
		fprintf(write, "%d %s\n", sen[sn[i].index].times, sen[sn[i].index].sentence + j);
	}

	fclose(stop);
	fclose(read);
	fclose(write);
	return 0;
}

//����-1˵������ͣ�ô�
int BinarySearch1(const stopwords* st, int left, int right, const char* s)
{
	int mid = (left + right) / 2;
	while (left <= right)
	{
		if (strcmp(st[mid].words, s) < 0)
		{
			return BinarySearch1(st, mid + 1, right, s);
		}
		else if (strcmp(st[mid].words, s) > 0)
		{
			return BinarySearch1(st, left, mid - 1, s);
		}
		else
			return mid;
	}
	return -1;
}