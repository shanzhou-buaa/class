#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

//int a[10], book[10], n;
//void dfs(int step)
//{
//	int i;
//	if (step == n + 1)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			printf("%d ", a[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		if (book[i] == 0)
//		{
//			a[step] = i;
//			book[i] = 1;
//			dfs(step + 1);
//			book[i] = 0;
//		}
//	}
//	return;
//}
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//    return 0;
//}


//int Find(const char* src, char* find)
//{
//	char tmp[500] = { 0 };
//	strcpy(tmp, src);
//	strcat(tmp, src);
//	return strstr(tmp, find) != NULL;
//}
//int main()
//{
//	char src[] = "AABCD";
//	char find[] = "BCDAA";
//	printf("%d\n", Find(src, find));
//}

//
//int main()
//{
//	float a = -5.5;
//	return 0;
//}


//int main()
//{
//	printf("%u\n", strlen("abc") - strlen("abcdef"));
//	return 0;
//}


//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	//assert(dest && src);
//	char* p = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char arr1[50] = "******************";
//	char arr2[] = "hello world!";
//	my_strcpy(arr1, arr2);
//	printf("%s", my_strcpy(arr1, arr2));
//	return 0;
//}

//char* my_strcat1(char* dest, const char* src)
//{
//	assert(dest && src);
//	int len1 = strlen(dest);
//	int len2 = strlen(src);
//	char* p = dest + len1;
//	char* ret = dest;
//	int i = 0;
//	for (i = 0; i < len2 + 1; i++)
//	{
//		*p++ = *src++;
//	}
//	return ret;
//}


//char* my_strcat2(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest)
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[50] = "hello ";
//	char arr2[] = "world";
//	char* ret1 = my_strcat1(arr1, arr2);
//	//char* ret2 = my_strcat2(arr1, arr2);
//	printf("%s\n", ret1);
//	//printf("%s\n", ret2);
// 	return 0; 
//}

//strcat(arr, arr)不能实现自己给自己追加
//字符串中没有\0了，会不停地追加


//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//	//str1 > str2返回大于0的值
//	//str1 < str2返回大于0的值
//}
//int main()
//{
//	//printf("%d\n",strcmp("abq", "abcd"));
//	int ret = my_strcmp("abq", "abcd");
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	char arr1[] = "2115362170@qq.1.6@3.com.";
//	char arr2[50] = { 0 };
//	char* ret = NULL;
//	char p[] = ".@";//顺序不重要，都有就行
//	strcpy(arr2, arr1);
//	for (ret = strtok(arr2, p); ret != NULL; ret = strtok(NULL, p))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}


//int main()
//{
//	char arr[] = "Hello Bit!";
//	int i = 0;
//	while (arr[i])
//	{
//		if (islower(arr[i]))
//		{
//			arr[i] = toupper(arr[i]);
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}

//char* my_strstr(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	const char* cp = s1;
//	while (*cp)
//	{
//		const char* p1 = cp;
//		const char* p2 = s2;
//		while ((*p1) && (*p2) && (*p1 == *p2))
//		{
//			p1++;
//			p2++;
//		}
//		if (*p2 == '\0')
//		{
//			return (char*)cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abbbcdef";
//	char arr2[] = "bcd";
//	printf("%s\n", my_strstr(arr1, arr2));
//	return 0;
//}


//int my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}