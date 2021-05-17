#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define NHASH 3001
#define MULT 37

typedef struct ListNode
{
	char s[30];
	struct ListNode* next;
}ln;

unsigned int hash(char *str)
{
	unsigned int h = 0;
	char *p;
	for (p = str; (*p) != '\0'; p++)
		h = MULT*h + *p;
	return h % NHASH;
}

void ListNodePush(ln* node, char* str)
{
	ln* newnode = (ln*)malloc(sizeof(ln));
	strcpy(newnode->s, str);
	newnode->next = NULL;

	ln* cur = node;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = newnode;
}

char word[3600][30];//�����еĵ���

int main()
{
	//�ѵ��ʶ���word��
	FILE* read = fopen("dictionary3000.txt", "r");
	int i = 0;
	while (fscanf(read, "%s", word[i]) != EOF)
		i++;
	int word_num = i;//���ʸ���

	//����
	char str[30];
	int sign = 0;
	memset(str, 0, 30);
	while (scanf("%s%d", str, &sign) != EOF)
	{
		int times = 0;
		int flag = 1;//flag��1˵�����������
		if (sign == 1)//˳�����
		{
			for (i = 0; i < word_num; i++)
			{
				times++;
				if (strcmp(str, word[i]) > 0)//����������
					continue;
				else if (strcmp(str, word[i]) == 0)//�ҵ���
					break;
				else//�Ҳ���
				{
					flag = 0;
					break;
				}
			}
			printf("%d %d\n", flag, times);
		}
		else if (sign == 2)
		{
			int left = 0;
			int right = word_num - 1;
			while (left <= right)
			{
				times++;
				int mid = (left + right) >> 1;
				if (strcmp(str, word[mid]) > 0)//str��
					left = mid + 1;
				else if (strcmp(str, word[mid]) < 0)//strС
					right = mid - 1;
				else
					break;
			}
			if (left > right)
				flag = 0;
			printf("%d %d\n", flag, times);
		}
		else if (sign == 3)
		{
			//����������
			char cur = 0;
			char next = 0;
			int num[30];//��ĳ������ĸ��Ӧ�ĵ��ʸ�������1��ʼ
			memset(num, 0, 120);
			for (i = 0; i < word_num - 1; i++)
			{
				cur = word[i][0];
				next = word[i + 1][0];
				if (cur != next)
					num[cur - 'a'] = i;
				if (cur == 'z')
				{
					num[cur - 'a'] = word_num - 1;
					break;
 				}
			}

			char c = str[0];
			//����
			int left = 0, right = 0;
			if (c == 'a')
				left = 0;
			else
			{
				if (num[c - 'a'] == 0)
				{
					printf("0 0\n");
					return 0;
				}
				if (num[c - 'a' - 1] == 0)
					left = num[c - 'a' - 2] + 1;
				else
					left = num[c - 'a' - 1] + 1;
			}
			if (num[c - 'a'] == 0)
				right = num[c - 'a' - 1];
			else
				right = num[c - 'a'];
			while (left <= right)
			{
				times++;
				int mid = (left + right) >> 1;
				if (strcmp(str, word[mid]) > 0)//str��
					left = mid + 1;
				else if (strcmp(str, word[mid]) < 0)//strС
					right = mid - 1;
				else
					break;
			}
			if (left > right)
				flag = 0;
			printf("%d %d\n", flag, times);
		}
		else if (sign == 4)
		{
			ln arr[3500];
			//��ʼ����ϣ��
			for (i = 0; i < 3500; i++)
			{
				strcpy(arr[i].s,"");
				arr[i].next = NULL;
			}

			//�ѵ��ʱ��еĵ��ʷ����ϣ��
			int key = 0;
			for (i = 0; i < word_num; i++)
			{
				key = hash(word[i]);
				if (strcmp(arr[key].s, "") == 0)//��λ���޵���
					strcpy(arr[key].s, word[i]);
				else
					ListNodePush(&arr[key], word[i]);
			}
			
			//����
			key = hash(str);
			if (strcmp(str, arr[key].s) == 0)
				printf("1 1\n");
			else if (strcmp(str, arr[key].s) > 0)
			{
				int flag1 = 0;//0˵���Ҳ���
				ln* curNode = &arr[key];
				
				while (curNode != NULL && strcmp(str, curNode->s) >= 0)
				{
					times++;
					if (strcmp(curNode->s, str) == 0)
					{
						flag1 = 1;
						break;
					}
					curNode = curNode->next;
				}
				printf("%d %d\n", flag1, times);
			}
		}
	}
	return 0;
}
//wins 4