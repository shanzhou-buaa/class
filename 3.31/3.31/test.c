#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct tag
//{
//	member - list;
//};

//typedef struct birthday
//{
//	int year;
//	int month;
//	int day;
//}birthday;
//
//typedef struct student
//{
//	char name[10];
//	int age;
//	char telephone[20];
//	char address[50];
//	birthday b;
//}student;
//
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	double d;
//	char c;
//	int i;
//};
//
//int main()
//{
//	student s1 = { "zhang san", 18, "123456789", "shang hai", { 2000, 1, 1 } };
//	//printf("%d\n", sizeof(struct S2));
//	student* ps = &s1;
//	printf("name:%s age:%d telephone:%s address:%s\nbirthday:%d.%d.%d\n",
//		s1.name, s1.age, s1.telephone, s1.address, s1.b.year, s1.b.month, s1.b.day);
//	printf("name:%s age:%d telephone:%s address:%s\nbirthday:%d.%d.%d\n",
//		ps->name, ps->age, ps->telephone, ps->address, ps->b.year, ps->b.month, ps->b.day);
//	return 0;
//}

//#pragma pack(8)//设置默认对齐数为8
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//#pragma pack(1)//设置默认对齐数为1
//struct S2
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()//取消设置的默认对齐数，还原为默认
//int main()
//{
//	//输出的结果是什么？
//	printf("%d\n", sizeof(struct S1));
//	printf("%d\n", sizeof(struct S2));
//	return 0;
//}

struct S 
{
	int data[1000];
	int num;
};
struct S s = { { 1, 2, 3, 4 }, 1000 };

//结构体传参
void print1(struct S s) 
{
	printf("%d\n", s.num);
}

//结构体地址传参
void print2(struct S* ps) 
{
	printf("%d\n", ps->num);
}

int main()
{
	print1(s);//传结构体
	print2(&s);//传地址
	return 0;
}