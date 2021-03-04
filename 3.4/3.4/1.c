#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char s[1000];
	gets(s);
	int i = 0, k = 0;
	int len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i] == '-')
		{
			if ((islower(s[i - 1]) && islower(s[i + 1]))
				|| (isupper(s[i - 1]) && isupper(s[i + 1]))
				|| (isdigit(s[i - 1]) && isdigit(s[i + 1])))
			{
				for (k = s[i - 1] + 1; k < s[i + 1]; k++)
					printf("%c", k);
			}
		}
		else
			printf("%c", s[i]);
	}
	return 0;
}