#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

char s[100], ss[100];
int a[100], b[100];
int len, i;

int main()
{
	scanf("%s%s", s, ss);
	int l1 = strlen(s);
	int l2 = strlen(ss);
	int flag = 0;

	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));

	if ((l1 < l2) || (strcmp(s, ss) < 0 && l1 == l2))
		//s < ss
	{
		flag = 1;
		i = 0;
		for (i = l2 - 1; i >= 0; i--)
			a[l2 - i - 1] = ss[i] - '0';
		for (i = l1 - 1; i >= 0; i--)
			b[l1 - i - 1] = s[i] - '0';
	}
	//a数组是大的数
	else
		//s > ss
	{
		i = 0;
		for (i = l1 - 1; i >= 0; i--)
			a[l1 - i - 1] = s[i] - '0';
		for (i = l2 - 1; i >= 0; i--)
			b[l2 - i - 1] = ss[i] - '0';
	}
	len = (l1 > l2) ? l1 : l2;
	for (i = 0; i <= len - 1; i++)
	{
		a[i] = a[i] - b[i];
		if (a[i] < 0)
		{
			a[i + 1]--;
			a[i] += 10;
		}
	}
	while (a[len - 1] == 0 && len > 1)
		len--;
	if (flag == 1)
		printf("-");
	for (i = len - 1; i >= 0; i--)
		printf("%d", a[i]);
	printf("\n");
	return 0;
}