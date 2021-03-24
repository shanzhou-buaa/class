#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Book
{
	char name[60];
	char writer[30];
	char publish[40];
	char date[20];
}book;

void Sort(book arr[], int n)
{
	int j = 0, k = 0;
	for (j = 0; j < n - 1; j++)
	{
		for (k = 0; k < n - j - 1; k++)
		{
			int flag = 1;
			if (strcmp(arr[k].name, arr[k + 1].name) < 0)
				flag = 0;
			/*else if (strcmp(arr[k].name, arr[k + 1].name) == 0 && strcmp(arr[k].writer, arr[k + 1].writer) < 0)
				flag = 0;
			else if (strcmp(arr[k].name, arr[k + 1].name) == 0 && strcmp(arr[k].writer, arr[k + 1].writer) == 0 && strcmp(arr[k].publish, arr[k + 1].publish) < 0)
				flag = 0;
			else if (strcmp(arr[k].name, arr[k + 1].name) == 0 && strcmp(arr[k].writer, arr[k + 1].writer) == 0 && strcmp(arr[k].publish, arr[k + 1].publish) == 0 && strcmp(arr[k].date, arr[k + 1].date) < 0)
				flag = 0;*/
			if (flag == 1)
			{
				book tmp = { 0 };
				memcpy(&tmp, &arr[k], sizeof(book));
				memcpy(&arr[k], &arr[k + 1], sizeof(book));
				memcpy(&arr[k + 1], &tmp, sizeof(book));
			}
		}
	}
}

int main()
{
	//ÅÅÐò
	FILE* in = fopen("books.txt", "r");
	book arr[500];
	int i = 0, n = 0;
	while (fscanf(in, "%s%s%s%s", arr[n].name, arr[n].writer, arr[n].publish, arr[n].date) != EOF)
		n++;

	Sort(arr, n);

	//ÊäÈë
	int input;
	while (scanf("%d", &input) != EOF)
	{
		if (input == 0)
		{
			break;
		}
		if (input == 1)
		{
			book b1 = { 0 };
			scanf("%s%s%s%s", b1.name, b1.writer, b1.publish, b1.date);
			memcpy(&arr[n], &b1, sizeof(book));
			n++;
			Sort(arr, n);
		}
		if (input == 2)
		{
			char s[100];
			scanf("%s", s);
			Sort(arr, n);
			for (i = 0; i < n; i++)
			{
				if (strstr(arr[i].name, s) != NULL)
					printf("%-50s%-20s%-30s%-10s\n", arr[i].name, arr[i].writer, arr[i].publish, arr[i].date);
			}
		}
		if (input == 3)
		{
			char s[100];
			scanf("%s", s);
			for (i = 0; i < n; i++)
			{
				if (strstr(arr[i].name, s) != NULL)
				{
					memcpy(&arr[i], &arr[n-1], sizeof(book));
					n--;
					i--;
				}
			}
		}
	}
	FILE* out = fopen("ordered.txt", "w");
	Sort(arr, n);
	for (i = 0; i < n; i++)
	{
		fprintf(out, "%-50s%-20s%-30s%-10s\n", arr[i].name, arr[i].writer, arr[i].publish, arr[i].date);
//		printf("%-50s%-20s%-30s%-10s\n", arr[i].name, arr[i].writer, arr[i].publish, arr[i].date);
	}
	return 0;
}