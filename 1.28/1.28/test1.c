#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//assert���������ڱ��ʽΪ�棬ʲô��������
//�����ڱ��ʽΪ�٣�����
char* my_strcpy(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);

	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}


//void my_strcpy(char* dest, char* src)
//{
//	int len = strlen(src);
//	int i = 0;
//	for (i = 0; i <= len; i++)
//	{
//		*(dest + i) = *(src + i);
//	}
//}
int main()
{
	char arr1[] = "qqqqqqqqqq";
	char arr2[] = "abcdef";
	my_strcpy(arr1, arr2);
	printf("%s\n", arr1);
    return 0;
}


//int main()
//{
//	int arr1[10] = { 0, 98, 20, 35, 47, 52, 63, 71, 80, 99 };
//	int arr2[10];
//	int i, j = 0; 
//	for (i = 0; i < 10; i++)
//	{
//		if (arr1[i] % 2 == 1)
//		{
//			arr2[j] = arr1[i];
//			j++;
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (arr1[i] % 2 == 0)
//		{
//			arr2[j] = arr1[i];
//			j++;
//		}
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}


//const����*���(int const* ��const int*һ��)�����ε���ָ��ָ�������
//ʹ��ָ��ָ������ݲ���ͨ�������ò������ı�


//const����*�ұ�(int *cons)�����ε���ָ��ָ��ĵ�ַ
//ʹ��ָ��ָ��ĵ�ַ���ܱ��޸�
//���Ǹõ�ַ�����ݿ��Ա��ı�
