#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <ctype.h>

void squeez(char s[], char c, int index)
{
	int i, j;
	int len = strlen(s);
	for (i = index, j = index; i < len; i++)
	{
		if (s[i] != c)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

int main()
{
	FILE* read = fopen("encrypt.txt", "r");
	FILE* write = fopen("output.txt", "w");

	char s[500];
	gets(s);
	int a[30] = { 0 };
	memset(a, 0, sizeof(a));
	int len = strlen(s);
	int i = 0;
	
	//É¾³ýÖØ¸´×Ö·û
	for (i = 0; i < len; i++)
	{
		if (a[s[i] - 'a'] == 0)
			a[s[i] - 'a'] = 1;
		else
		{
			squeez(s, s[i], i);
			len = strlen(s);
			i--;
		}
	}
	//printf("%s", s);

	//¼ÓÃÜ×ÖÄ¸
	char s1[30] = { '0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0' };
	char s2[30];
	s2[0] = '0';
	int len2 = len, j = 0, k = 0;
	for (i = 0; i < len; i++)
		s2[i + 1] = s[i];
	for (i = len + 1, j = 0; i <= 26; i++, j++)
	{
		int flag = 1;
		for (k = 0; k < len; k++)
		{
			if ('z' - j == s[k])
			{
				flag = 0;
				i--;
				break;
			}
		}
		if (flag == 1)
		{
			len2++;
			s2[i] = 'z' - j;
		}
	}

	//    123
	//s1:0abcdefghijklmnopqrstuvwxyz
	//s2:0feathrzyxwvusqponmlkjigdcb
	//    0
	//str:c language is wonderful.
	//        0
	//answer: a
	char str[500];
	char answer[500];
	fgets(str, 500, read);
	int len3 = strlen(str);
	int index = 0;
	for (i = 0, j = 1; i < len3; i++, j++)
	{
		if (!isalpha(str[i]))
		{
			answer[i] = str[i];
			continue;
		}
		for (k = 1; k <= 26; k++)
		{
			if (str[i] == s1[k])
			{
				index = k;
				break;
			}
		}
		answer[i] = s2[index];
	}
	answer[i] = '\0';
	//printf("%s", answer);
	fputs(answer, write);
	return 0;
}