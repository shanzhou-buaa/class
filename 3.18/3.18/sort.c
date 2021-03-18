#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char s[100][40];
	int n, i = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
		gets(s[i]);
	int j = 0, k = 0;

	//É¾³ýÖØ¸´µÄ
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(s[i], s[j]) == 0)
			{
				for (k = j; k < n - 1; k++)
				{
					strcpy(s[k], s[k + 1]);
				}
				n--;
			}
		}
	}

	char name[100][25];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < strlen(s[i]); j++)
		{
			if (s[i][j] != ' ')
				name[i][j] = s[i][j];
			else
			{
				name[i][j] = '\0';
				break;
			}
		}
	}

	//char min[40];
	//int index = 0;
	////ÅÅÐò
	//for (i = 0; i < n; i++)
	//{
	//	index = i;
	//	strcpy(min, name[i]);
	//	for (j = i + 1; j < n; j++)
	//	{
	//		if (strcmp(name[j], min) < 0)
	//		{
	//			strcpy(min, name[j]);
	//			index = j;
	//		}
	//	}
	//	int len = strlen(min);
	//	char temp[40];

	//	strcpy(temp, name[i]);
	//	strcpy(name[i], name[index]);
	//	strcpy(name[index], temp);

	//	strcpy(temp, s[i]);
	//	strcpy(s[i], s[index]);
	//	strcpy(s[index], temp);
	//}
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(name[j], name[i]) > 0)
			{
				char temp[40];

				strcpy(temp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], temp);

				strcpy(temp, s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], temp);
			}
		}
	}*/
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (strcmp(name[j], name[j + 1]) > 0)
			{
				char temp[40];

				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);

				strcpy(temp, s[j]);
				strcpy(s[j], s[j + 1]);
				strcpy(s[j + 1], temp);
			}
		}
	}

	//ÐòºÅ
	/*char name[100][25];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < strlen(s[i]); j++)
		{
			if (s[i][j] != ' ')
				name[i][j] = s[i][j];
			else
			{
				name[i][j] = '\0';
				break;
			}
		}
	}*/

	int flag = 1;
	for (i = 0; i < n - 1; i++)
	{
		if (strcmp(name[i], name[i + 1]) != 0)
			printf("%s\n", s[i]);
		else
		{
			int x = 0;
			while (strcmp(name[i], name[i + 1]) == 0)
			{
				if (x == 0)
					printf("%s\n", s[i]);
				else
				{
					for (j = 0; j < strlen(s[i]); j++)
					{
						if (s[i][j] != ' ')
							printf("%c", s[i][j]);
						else
							break;
					}
					j++;
					printf("_%d ", x);
					for (; j < strlen(s[i]); j++)
					{
						printf("%c", s[i][j]);
					}
					printf("\n");
				}
				i++;
				x++;
			}
			if (i == n - 1)
				flag = 0;
			for (j = 0; j < strlen(s[i]); j++)
			{
				if (s[i][j] != ' ')
					printf("%c", s[i][j]);
				else
					break;
			}
			printf("_%d ", x);
			j++;
			for (; j < strlen(s[i]); j++)
			{
				printf("%c", s[i][j]);
			}
			printf("\n");
		}
	}
	if (flag)
		printf("%s\n", s[i]);
	return 0;
}