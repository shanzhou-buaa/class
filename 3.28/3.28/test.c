#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct article
{
	char word[1000];
	int n;
}article;

//article* init(article* prev, char* s)
//{
//	article* newnode = (article*)malloc(sizeof(article));
//	prev->next = newnode;
//	strcpy(newnode->word, s);
//	newnode->n = 1;
//	newnode->next = NULL;
//	return newnode;
//}
int main()
{
	FILE* in = fopen("article.txt", "r");
	article a[1000];
	int i = 0, j = 0, sz = 0;

	//读入单词
	//while (fscanf(in, "%s", a[sz].word) != EOF)
	//{
	//	a[sz].n = 1;
	//	int len = strlen(a[sz].word);
	//	for (i = 0; i < len; i++)
	//	{
	//		if (isupper(a[sz].word[i]))//处理大写字母
	//			a[sz].word[i] = tolower(a[sz].word[i]);
	//		if (!isalpha(a[sz].word[i]))//处理句末标点
	//			a[sz].word[i] = '\0';
	//	}
	//	sz++;
	//}

	char words[10000];
	int sum = fread(words, 1, 10000, in);
	for (i = 0; i < sum; i++)
	{
		if (words[i] >= 'A' && words[i] <= 'Z')
			words[i] += 32;
	}

	//得到单词
	for (i = 0; i < sum; i++)
	{
		if (words[i] >= 'a' && words[i] <= 'z')
		{
			j = 0;
			for (; words[i] >= 'a' && words[i] <= 'z'; i++, j++)
				a[sz].word[j] = words[i];
			a[sz].word[j] = '\0';
			a[sz].n = 1;
			sz++;
		}
	}

	//把相同的单词合并
	for (i = 0; i < sz; i++)
	{
		if (a[i].n == -1)
			continue;
		for (j = i + 1; j < sz; j++)
		{
			if (a[j].n == -1)
				continue;
			if (strcmp(a[i].word, a[j].word) == 0)
			{
				a[i].n++;
				a[j].n = -1;
			}
		}
	}

	//把n = -1的结构体删除
	for (i = 0; i < sz; i++)
	{
		if (a[i].n == -1)
		{
			for (j = i; j < sz; j++)
			{
				memmove(&a[j], &a[j + 1], sizeof(article));
			}
			sz--;
			i--;
		}
	}

	//冒泡排序
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (strcmp(a[j].word, a[j + 1].word) >= 0)
			{
				article tmp;
				memcpy(&tmp, &a[j], sizeof(article));
				memcpy(&a[j], &a[j + 1], sizeof(article));
				memcpy(&a[j + 1], &tmp, sizeof(article));
			}
		}
	}

	for (i = 0; i < sz; i++)
		printf("%s %d\n", a[i].word, a[i].n);

	fclose(in);
	return 0;
}
	/*for (cur1 = head->next; cur1->next != NULL; cur1 = cur1->next)
	{
		int temp = 0;
		strcpy(min, cur1->word, sizeof(cur1->word));
		for (cur2 = head->next; cur2 != NULL; cur2 = cur2->next)
		{
			if (strcmp(min, cur2->word) > 0 && cur2->n != -1)
			{
				strcpy(min, cur2->word);
				temp = cur2->n;
				cur2->n = -1;
			}
			printf("%s %d\n", min, temp);
		}
	}*/


//int main()
//{
//	FILE* in = fopen("article.txt", "r");
//	char c;
//	char word[1000][100];//存单个单词
//	int i = 0, j = 0;
//	while (fgetc(in) != EOF)
//	{
//		if ()
//	}
//
//	return 0;
//}