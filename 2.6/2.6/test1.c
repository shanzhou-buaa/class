#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
//#include <ctype.h>
//
//void num_move(int* p, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		//从前向后找一个偶数
//		while ((left < right) &&(p[left] % 2 == 1))
//		{
//			left++;
//		}
//		//从后向前找一个奇数
//		while ((left < right) && (p[right] % 2 == 0))
//		{
//			right--;
//		}
//		int tmp = p[left];
//		p[left] = p[right];
//		p[right] = tmp;
//	}
//}
//int main()
//{
//	int arr[] = { 1, 45, 3, 463, 5, 67, 79, 81, 95, 103 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	num_move(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//    return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 'A'; i <= 'D'; i++)
//	{
//		if ((i != 'A') + (i == 'C') + (i == 'D') + (i != 'D') == 3)
//		{
//			printf("%c\n", i);
//		}
//	}
//	return 0;
//}


//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//int main()
//{	
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	int d = 1;
//	int e = 1;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a * b * c* d * e == 120)
//							{
//								printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
#include <assert.h>
//char* left_move1(char* p, int k)
//{
//	int len = strlen(p);
//	while (k--)
//	{
//		int i = 0;
//		char tmp = *p;
//		for (i = 1; i <= len; i++)
//		{
//			*(p + i - 1) = *(p + i);
//		}
//		*(p + len - 1) = tmp;
//	}
//	return p;
//}
//
//void reverse(char* left, char* right)
//{
//	assert(left && right);
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//char* left_move2(char* p, int k)
//{
//	int len = strlen(p);
//	reverse(p, p + k - 1);
//	reverse(p + k, p + len - 1);
//	reverse(p, p + len - 1);
//	return p;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	int k = 2;
//	//left_move1(arr, k);
//	left_move2(arr, k);
//	//cdefab
//	printf("%s\n", arr);
//}

//int find(int arr[3][3], int k, int r, int c)
//{
//	int x = 0;
//	int y = c - 1;
//	while (x < r && y >= 0)
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int ret = find(arr, 7, 3, 3);
//	printf("%d\n", ret);
//}


//struct S1
//{
//	char c1;
//	int a;
//	char c2;
//};
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//int main()
//{
//	struct S1 s1= { 0 };
//	printf("%d\n", sizeof(s1));
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));
//	return 0;
//}


#include <stddef.h>
struct S3
{
	char c1;
	char c2;
	int a;
	double b;
};
//int main()
//{
//	printf("%d\n", offsetof(struct S3, c1));//括号里写类型名，而不是变量名
//	printf("%d\n", offsetof(struct S3, c2));//括号里写类型名，而不是变量名
//	printf("%d\n", offsetof(struct S3, a));//括号里写类型名，而不是变量名
//	printf("%d\n", offsetof(struct S3, b));//括号里写类型名，而不是变量名
//}

//void Init(struct S3* ps)
//{
//	ps->c1 = 'a';
//	ps->c2 = '1';
//	ps->a = 10;
//	ps->b = 3.14;
//}
//void print(const struct S3* ps)
//{
//	printf("%c %c %d %f\n", ps->c1, ps->c2, ps->a, ps->b);
//}
//int main()
//{
//	struct S3 s = { 0 };
//	Init(&s);
//	print(&s);
//	return 0;
//}

//位段
//为了节省空间
//struct S
//{
//	int a : 2;//int a本来占32个比特位，用位段会后a占2个比特位
//	int b : 5;//int b本来占32个比特位，用位段会后b占5个比特位
//	int c : 10;
//	int d : 30; 
//};

//联合体/共用体，共用同一块空间
//union un
//{
//	int a;
//	char c;
//	double b;
//};

//int main()
//{
//	union un U = { 0 };
//	printf("%d\n", sizeof(union un));
//	printf("%p\n", &U);//4个地址一样
//	printf("%p\n", &(U.a));
//	printf("%p\n", &(U.b));
//	printf("%p\n", &(U.c));
//	//因为4个地址一样，所以只能同时使用（改变）一个量
//	//因为3个变量共用同一块空间，互相影响
//	return 0;
//}


int check_sys()
{
	union UN
	{
		char c;
		int a;
	}u;
	u.a = 1;
	return u.c;
	//返回1表示小端
	//返回0表示大端
}