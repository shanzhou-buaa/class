//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <ctype.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
////sentence�ṹ��ÿ�����ӵ��±�Ͷ�Ӧ�Ĵ���
//typedef struct sen_num
//{
//	int times;
//	int index;
//}sen_num;
//
//typedef struct sentences
//{
//	int times;
//	char sentence[5000];//ԭ����
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
//nstopwords nst[40000];//��ͣ�ô�
//char st[1000][50];//ͣ�ô� 1~320
//sentences sen[200000];//���� 1~31032
//char all[3000005] = { 0 };//ͳ�Ʒ�ͣ�ô�ʱһ�δ������ж���ô����ַ�
//
//int BinarySearch1(const char* st, int left, int right, const char* s);
//
//int main()
//{
//	FILE* read = fopen("article.txt", "r");//����
//	FILE* write = fopen("results.txt", "w");//���
//	FILE* stop = fopen("stopwords.txt", "r");//ͣ�ô�
//
//	int n;
//	scanf("%d", &n);
//	//int n = 200;
//
//	//��ͣ�ôʶ���stopwords������
//	int i = 1, j = 0, k = 1;
//	while (fscanf(stop, "%s", st[i]) != EOF)//ÿ����ĩβ��\n
//	{
//		//st[i].times = 0;//ͣ�ôʴ�����Ϊ0
//		i++;
//	}
//	int wordNum = i;//ͣ�ô�������1��ʼ
//
//	//��ÿһ�仰����sentences��
//	i = 1;
//	while (1)
//	{
//		//�����ַ�����
//		char c = fgetc(read);
//
//		if (c == EOF)
//			break;
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
//	int line = i;//������������1��ʼ
//
//	//�����������£�ͳ��ÿ����ͣ�ôʵ�Ƶ��
//	rewind(read);//��read�Ż��ļ���ͷ
//	int len = 0, index = 1;//index�Ƿ�ͣ�ô�����Ĵ�С
//	while (fgets(all, 3000000, read) != NULL)
//	{
//		char temp[50];
//		len = strlen(all);
//		for (i = 0; i < len; i++)//�ӿ�ͷ�������������
//		{
//			if (all[i] == ' ' || all[i] == '.' || all[i] == '!' || all[i] == '?')//���ǵ���
//				continue;
//			else
//			{
//				j = 0;
//				while (isalpha(all[i]))//��temp�ж���һ������
//				{
//					if (isupper(all[i]))
//						temp[j] = all[i] + 32;
//					else
//						temp[j] = all[i];
//					i++;
//					j++;
//				}
//
//				temp[j] = '\0';//��\0�����ַ���
//
//				int flag = BinarySearch1(st, 1, wordNum, temp);//flag����-1˵����ͣ�ô�
//				if (flag == -1)//temp�еĵ��ʲ���ͣ�ô�
//				{
//					int m, sign = 1;//sign��1˵�������ͣ�ô�û����¼��
//					for (m = 1; m <= index; m++)//���κͷ�ͣ�ôʵ�����Ƚ�
//					{
//						if (strcmp(temp, nst[m].words) == 0)
//						{
//							sign = 0;
//							nst[m].times++;//��������ͣ�ô��Ѿ�����¼��������+1
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
//	//ͳ��ÿ�������з�ͣ�ô�Ƶ��֮��
//	for (i = 1; i <= line; i++)
//	{
//		len = strlen(sen[i].sentence);
//		for (k = 0; k < len; k++)
//		{
//			char temp[50] = { 0 };
//			j = 0;
//			while (isalpha(sen[i].sentence[k]) && k < len)//��temp�ж�������е�һ������
//			{
//				temp[j] = tolower(sen[i].sentence[k]);
//				k++;//newsentence����Ų
//				j++;//temp����Ų
//			}
//			temp[j] = '\0';//��\0�����ַ���
//
//			int flag = 1;//flag��1˵��temp�еĵ����Ƿ�ͣ�ô�
//			for (j = 1; j <= wordNum; j++)//������ͣ�ôʱȽ�
//			{
//				if (strcmp(temp, st[j]) == 0)
//				{
//					flag = 0;//flag��0˵��temp�еĵ�����ͣ�ô�
//					break;
//				}
//			}
//			if (flag)
//			{
//				int l;
//				//index�Ƿ�ͣ�ô�����Ĵ�С
//				//l������ͣ�ô�����
//				for (l = 1; l <= index; l++)
//				{
//					//�þ����к��е�l����ͣ�ô�
//					if (strcmp(nst[l].words, temp) == 0)
//					{
//						sen[i].times += nst[l].times;//���ӵķ�ͣ�ôʴ������ϸ÷�ͣ�ôʵĴ���
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
//		sn[i].index = i;//����ӵ����
//		sn[i].times = sen[i].times;//�����ž��ӵķ�ͣ�ô�Ƶ��
//	}
//
//	//ð��������sn�����times
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
//	//���
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