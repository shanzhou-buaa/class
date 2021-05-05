#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//%8:30S
//hello, word!

//%-20:30S
//Hello, word!

int main()
{
	char input[1000];//输入的格式
	memset(input, 0, sizeof(input));
	char s[150];
	memset(s, 0, sizeof(s));//输入的字符串
	int m = 0, n = 0;
	int i = 0;
	gets(input);
	gets(s);
	int len = strlen(s);

	if (input[1] != '-')//靠左
	{
		for (i = 1; input[i] != ':'; i++)
			m = m * 10 + input[i] - '0';
		i++;
		for (; input[i] != 'S'; i++)
			n = n * 10 + input[i] - '0';

		if (m > len)//输出整个字符串
		{
			printf("%s", s);
			if (n > len)
			{
				int num = n - len;
				for (i = 0; i < num; i++)
					printf("%c", '#');
			}
			printf("\n");
		}
		else
		{
			for (i = 0; i < m; i++)
				printf("%c", s[i]);
			if (n > m)
			{
				int num = n - m;
				for (i = 0; i < num; i++)
					printf("%c", '#');
			}
			printf("\n");
		}
	}

	else//靠右
	{
		for (i = 2; input[i] != ':'; i++)
			m = m * 10 + input[i] - '0';
		i++;
		for (; input[i] != 'S'; i++)
			n = n * 10 + input[i] - '0';

		if (m > len)
		{
			if (n > len)
			{
				int num = n - len;
				for (i = 0; i < num; i++)
					printf("%c", '#');
				printf("%s\n", s);
			}
		}
		else
		{
			if (n > len)
			{
				int num = n - m;
				for (i = 0; i < num; i++)
					printf("%c", '#');
			}
			for (i = 0; i < m; i++)
				printf("%c", s[i]);
			printf("\n");
		}
	}

	return 0;
}