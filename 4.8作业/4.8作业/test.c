#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdio.h>
#include <assert.h>

//char* my_strncat(char* dest, const char* src, int n)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (*dest)
//		dest++;
//	int i = 0;
//	for (; i < n; i++)
//	{
//		*(dest + i) = *(src + i);
//	}
//	*(dest + i) = '\0';
//	return ret;
//}
//
//int main()
//{
//	char a[20] = "hello ";
//	char b[] = "world";
//	my_strncat(a, b, 2);
//	printf("%s\n", a);
//	return 0;
//}

int my_strncmp(const char* a, const char* b, int n)
{
	int i = 0;
	for (; i < n; i++)
	{
		if (a[i] != b[i])
		{
			return (a[i] - b[i]);
		}
	}
	return 0;
}

int main()
{
	char a[20] = "hello";
	char b[20] = "heaven";
	if (my_strncmp(a, b, 2) > 0)
		printf(">\n");
	else if (my_strncmp(a, b, 2) == 0)
		printf("=\n");
	else
		printf("<\n");

	return 0;
}