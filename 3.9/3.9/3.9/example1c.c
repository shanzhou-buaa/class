#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void squeez(char s[], char c)
{
	int i, j;
	for (i = 0, j = 0; i < strlen(s); i++)
		if (s[i] != c)
			s[j++] = s[i];
		s[j] = '\0';
}

int cal(int x, int y, char c)
{
	if (c == '+')
		return x + y;
	else if (c == '-')
		return x - y;
	else if (c == '*')
		return x * y;
	else
		return x / y;
}
int main()
{
	char s[500];//存整个表达式,i
	char a[500];//存符号,j
	int b[500];//存数字,k
	gets(s);
	squeez(s, ' ');
	int flag = 0, temp = 0;
	int i = 0, j = 0, k = 0;
	int len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(s[i]))//s[i]是运算符
		{
			a[j] = s[i];
			j++;
		}
		else//s[i]是数字
		{
			temp = s[i] - '0';
			int i_temp = i + 1;
			while (isdigit(s[i_temp]))//s[i+1]也是数字，把字符串转变成数字
			{
				temp = temp * 10 + s[i_temp] - '0';
				i_temp++;
			}
			i = i_temp - 1;
			k++;
			b[k] = temp;//数字放在b
		}
	}
	//5 - 1 * 2 * 3 + 12 / 2 / 2 =
	//a:-**+//=    j = 7
	//b:空 5 1 2 3 12 2 2   k = 8
	int sum = b[1];
	for (i = 0; i <= k; i++)
	{
		if (a[i] == '=')
			break;
		if (a[i] == '+' || a[i] == '-')
		{
			if (a[i + 1] != '*' && a[i + 1] != '/')
				sum = cal(sum, b[i + 2], a[i]);
			else
			{
				int i_temp = i + 1;
				int temp = b[i + 2];
				for (; i_temp < k; i_temp++)
				{
					if (a[i_temp] == '*' || a[i_temp] == '/')
						temp = cal(temp, b[i_temp + 2], a[i_temp]);
					else
						break;
				}
				sum = cal(sum, temp, a[i]);
				i = i_temp - 1;
			}
		}
		else
			sum = cal(sum, b[i + 2], a[i]);
	}
	printf("%d", sum);
	return 0;
}