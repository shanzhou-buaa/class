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
//		//��ǰ�����һ��ż��
//		while ((left < right) &&(p[left] % 2 == 1))
//		{
//			left++;
//		}
//		//�Ӻ���ǰ��һ������
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


//5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
//Aѡ��˵��B�ڶ����ҵ�����
//Bѡ��˵���ҵڶ���E���ģ�
//Cѡ��˵���ҵ�һ��D�ڶ���
//Dѡ��˵��C����ҵ�����
//Eѡ��˵���ҵ��ģ�A��һ��
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
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
//	printf("%d\n", offsetof(struct S3, c1));//������д�������������Ǳ�����
//	printf("%d\n", offsetof(struct S3, c2));//������д�������������Ǳ�����
//	printf("%d\n", offsetof(struct S3, a));//������д�������������Ǳ�����
//	printf("%d\n", offsetof(struct S3, b));//������д�������������Ǳ�����
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

//λ��
//Ϊ�˽�ʡ�ռ�
//struct S
//{
//	int a : 2;//int a����ռ32������λ����λ�λ��aռ2������λ
//	int b : 5;//int b����ռ32������λ����λ�λ��bռ5������λ
//	int c : 10;
//	int d : 30; 
//};

//������/�����壬����ͬһ��ռ�
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
//	printf("%p\n", &U);//4����ַһ��
//	printf("%p\n", &(U.a));
//	printf("%p\n", &(U.b));
//	printf("%p\n", &(U.c));
//	//��Ϊ4����ַһ��������ֻ��ͬʱʹ�ã��ı䣩һ����
//	//��Ϊ3����������ͬһ��ռ䣬����Ӱ��
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
	//����1��ʾС��
	//����0��ʾ���
}