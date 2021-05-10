#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//int fun(int x)
//{
//	if (x <= 1)
//		return 1;
//	else
//		return (2 + x * fun(x - 1));
//}

int main()
{
	char text[205];//存句子
	memset(text, 0, sizeof(text));
	char word[55][40];//存标识符
	memset(word, 0, sizeof(word));

	gets(text);
	int i = 0, j = 0, line = 0;//标识符个数
	int len = strlen(text);

	for (i = 0; i < len; i++)
	{
		if (text[i] == '\\' && text[i + 1] == 'n')
			break;
		j = 0;
		char temp[50];
		memset(temp, 0, sizeof(temp));//存读取到的标识符
		if (text[i] == ' ')
			continue;

		int sign = 0;
		while (isalpha(text[i]) || text[i] == '_' || isdigit(text[i]))
		{
			if (isdigit(text[i]))
			{
				int k = j;
				while (k--)
				{
					if (isalpha(temp[k]))
					{
						sign = 1;
						break;
					}
				}
			}
			if (sign == 0 && isdigit(text[i]))
				break;

			temp[j] = text[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		if (strlen(temp) == 0)
			continue;

		//int a11a = 0;

		if (line == 0)
		{
			strcpy(word[0], temp);
			line++;
		}
		else
		{
			int flag = 1;//flag是1说明没有一样的
			for (j = 0; j < line; j++)
			{
				if (strcmp(word[j], temp) == 0)
				{
					flag = 0;
					break;
				}
			}

			if (flag)
			{
				strcpy(word[line], temp);
				line++;
			}
		}
	}


	//int _2min = 0;
	//int 2min = 0;
	//int _2 = 1;
	//int _3 = 2;

	for (i = 0; i < line - 1; i++)
	{
		for (j = 0; j < line - i - 1; j++)
		{
			if (strcmp(word[j], word[j + 1]) > 0)
			{
				char ex[50];
				memset(ex, 0, sizeof(ex));
				strcpy(ex, word[j]);
				strcpy(word[j], word[j + 1]);
				strcpy(word[j + 1], ex);
			}
		}
	}
	for (i = 0; i < line; i++)
	{
		//j = 0;
		//while (word[i][j] == ' ')
		//	j++;
		printf("%s ", word[i]);
	}
	return 0;
}

//array_sum[i] = array_a[i] + array_a[j] + _next2[j] * getArea(x, y, z) - 100 * i;
//getArea GetArea _2sd = 2;\n
// int _2min = 0 & 5; _2min++;
//int min2m = 0 + 1;
//for(i_3 = 0; _3 < 2; i++)
//int _3 = 1;
