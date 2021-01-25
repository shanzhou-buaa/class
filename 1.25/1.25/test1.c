#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//void bubbleSort(int arr[], int sz)
//{
//	int i, j, flag;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			flag = 1;//从小到大
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//			if (flag)
//				break;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i;
//	bubbleSort(arr, sz);
//	for (i = 0; i < sz; i++)
//		printf("%d ", i);
//    return 0;
//}


//void init(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void my_print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void reverse(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int temp = arr[left];
//		arr[left] = arr[right];
//		arr[right] = temp;
//		right--;
//		left++;
//	}
//}
//int main()
//{
//	int arr[10] = { 0, 1, 2, 4, 3, 5, 6, 7, 8, 9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse(arr, sz);
//	my_print(arr, sz);
//	printf("\n");
//	init(arr, sz);
//	my_print(arr, sz);
//	printf("\n");
//	return 0;
//}

//void Swap(int* p1, int *p2, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int temp = *(p1 + i);
//		*(p1 + i) = *(p2 + i);
//		*(p2 + i) = temp;
//	}
//}
//两个Swap都可
//void Swap(int arr1[], int arr2[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = temp;
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int arr2[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	Swap(arr1, arr2, sz);
//	printf("arr1:");
//	my_print(arr1, sz);
//	printf("\n");
//	printf("arr2:");
//	my_print(arr2, sz);
//	return 0;
//}


//位运算移动的是存储在内存中的二进制位的补码
//左移操作符：左边丢弃，右边补0（相当于乘2）
//int main()
//{
//	int a = 5;
//	//00000000 00000000 00000000 00000101   5的原码、反码、补码
//	//内存中存的是补码
//	int b = a << 1;
//	//00000000 00000000 00000000 00001010	b的原码、反码、补码
//	printf("b = %d\n", b);
//
//
//	a = -2;
//	int c = a << 1;
//	//原码符号位不变，其他位按位取反得反码
//	//反码+1得补码
//
//	//补码-1得反码
//	//反码符号位不变，其他位按位取反得原码
//
//	//10000000 00000000 00000000 00000010	-2的原码
//	//11111111 11111111 11111111 11111101	-2的反码
//	//11111111 11111111 11111111 11111110	-2的补码
//
//	//11111111 11111111 11111111 11111100	c的补码
//	//11111111 11111111 11111111 11111011	c的反码
//	//10000000 00000000 00000000 00000100	c的原码  即-4
//	printf("c = %d\n", c);
//	return 0;
//}

//右移操作符
//1、算术右移：左边补原来的符号位，右边丢弃
//2、逻辑右移：左边补0，右边丢弃

//int main()
//{
//	int a = 5;
//	int b = a >> 1;
//	//00000000 00000000 00000000 00000101   5的原码、反码、补码
//	//00000000 00000000 00000000 00000010	b	
//	printf("b = %d\n", b);
//
//	a = -5;
//	int c = a >> 1;
//	//10000000 00000000 00000000 00000101	-5的原码
//	//11111111 11111111 11111111 11111010	-5的反码
//	//11111111 11111111 11111111 11111011	-5的补码
//
//	//11111111 11111111 11111111 11111101   c的补码
//	//11111111 11111111 11111111 11111100	c的反码
//	//10000000 00000000 00000000 00000011   c的原码
//	printf("c = %d\n", c);//c = -3
//	//说明当前编译器是算术右移
//	return 0;
//}

//对于移位操作符，不要移动负数位
//比如a >> -1
//这是错误的

//逻辑操作符只能对整型操作
//逻辑操作符是针对补码操作的
//按位与有0就是0，全1才为1
//按位或有1就是1，全0才为0
//按位异或相同为0，相异为1
//int main()
//{
//	int a = -1;
//	int b = -2;
//	int c = a & b;
//	//10000000 00000000 00000000 00000001	a原码
//	//10000000 00000000 00000000 00000010	b原码
//	//按位与
//	//10000000 00000000 00000000 00000000
//	printf("%d\n", c); //-2
//	//11111111 11111111 11111111 11111111	a补码
//	//11111111 11111111 11111111 11111110	b补码
//	//按位与
//	//11111111 11111111 11111111 11111110	-2
//}


//int main()
//{
//	int a = 5, b = 3;
//	printf("a = %d, b = %d\n", a, b);
//	a = a ^ b;
//	//101	a
//	//011	b
//	//110	a
//	b = a ^ b;
//	//110	a
//	//011	b
//	//101	b
//	a = a ^ b;
//	//110	a
//	//101	b
//	//011	a
//	printf("a = %d, b = %d\n", a, b);
//	return 0;
//}