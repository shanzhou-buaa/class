#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum Sex
{
	Male,
	Female
};

//enum Weekday//����
//{
//	Mon,//�������ö��ŷֿ�
//	Tue,
//	Wed,
//	Thu,
//	Fri,
//	Sat,
//	Sun//ע�����һ��������û�ж���
//};

enum Weekday//����
{
	//��ĳ��������ʼֵ����Ӹ�����ʼ����1
	//����֮ǰ�Ĳ���Ӱ��
	Mon,//0
	Tue,//1
	Wed = 10,//10
	Thu,//11
	Fri,//12
	Sat,//13
	Sun//14
};

//�������͵�����
//union Un
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	//���ϱ����Ķ���
//	union Un un;
//	//��������������Ĵ�С
//	printf("%d\n", sizeof(un));
//	un.c = 1;
//
//	return 0;
//}

//
//union Un
//{
//	int a;
//	int b;
//	int c;
//};
//
//int main()
//{
//	union Un un;
//	un.a = 1;
//	printf("%d\n", un.b);//1
//	printf("%d\n", un.c);//1
//
//	un.b = 2;
//	printf("%d\n", un.a);//2
//	printf("%d\n", un.c);//2
//
//	printf("%d\n", &(un.a));
//	printf("%d\n", &(un.b));
//	printf("%d\n", &(un.c));
//
//	return 0;
//}


union Un1
{
	char c[5];
	int i;
};
union Un2
{
	short c[7];
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un1)); //
	printf("%d\n", sizeof(union Un2));//
	return 0;
}