#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//int main()
//{
//    //float a = 55.6; �ᱨ������ĸ�����Ĭ����double����
//	float a = 55.6f;//�����ֺ����f�Ϳ���
//    return 0;
//}


//int a = 100;
//int main()
//{
//	int a = 20;
//	//һ����������һ�������
//	//�ֲ�����ֻ���ڶ�Ӧ�Ĵ������ʹ��
//	//�ֲ������������������ڵľֲ���Χ
//	//ȫ�ֱ�������������������
//	{//�ڲ���a����
//		int a = 10;//�м����a����������
//		printf("a1 = %d\n", a);//10
//   //�ڲ���a����
//	}
//	printf("a2 = %d\n", a);//20
//	//�ֲ�������ȫ�ֱ�����ͻʱ���ֲ���������
//	return 0;
//}


//extern int test;//extern�����������ⲿ������
//������ֻ���������͡�����������
//int main()
//{
//	printf("test = %d\n", test);
//	return 0;
//}


////һ�������ж����Ŀ�ܹ�ֻ����һ��main����
//enum sex
//{//ö�ٳ�������ʼ��Ĭ�ϴ�0��ʼ���µ���1
//	male = 2,
//	female = 4
//};
//int main()
//{
//	enum sex a = male;
//	printf("male = %d\n", male);//2
//	printf("female = %d\n", female);//4
//	return 0;
//}


//int main()
//{
//	printf("%c\n", '\x1F');//Ҫ��''
//  return 0��
//}


//int main()
//{
//	printf("%d\n", strlen("c:\test\328\test.c"));
//	//c,:,\t,e,s,t,\32,8,\t,e,s,t,.,c
//	//8����8������������\32��һ����(����\032)
//}


//int main()
//{
//	auto int a = 10;//�ֲ��������Զ��������Զ����٣�auto��ʡ��
//	//���еľֲ����������Զ�����
//	return 0;
//}


//typedef unsigned int uint;//��c�����趨�Ĺؼ�����������
//typedef unsigned long long ull;
//int main()
//{
//	uint a = 10;
//	printf("%u\n", a);
//	ull b = 100;
//	printf("%u\n", b);
//	return 0;
//}


//void test1()
//{
//	int a = 1;//a�Ǿֲ�������ÿ�ν��붼��������ʼ����1
//	a++;
//	printf("%d ", a);//������ʱa������
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test1();//��ӡ10��2
//		i++;
//	}
//	return 0;
//}


//void test1()
//{
//	static int a = 1;//static���ξֲ��������ı�ֲ��������������ڣ���main����һ����
//	//������û�䣬��Ȼֻ���ں����ڲ�ʹ��
//	a++;
//	printf("%d ", a);//������ʱa������
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test1();
//		i++;
//	}
//	return 0;
//}

//static����ȫ�ֱ�������ȫ�ֱ���ֻ�������Դ�ļ��ڲ�ʹ��
//������Դ�ļ�����extern����ʱ���ܱ����ӵ�
//ȫ�ֱ����Ǿ����ⲿ�������Ե�
//static���κ󣬽�ȫ�ֱ������ⲿ�������Ը�Ϊ�ڲ���������

//extern int Add(int x, int y);
////��test2.c��Addǰ����static���仯ͬȫ�ֱ���
//int main()
//{
//	int a = 10, b = 20;
//	int c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}


//register�ǰѱ������ڼĴ�����
//register���εı�������ȡ��ַ&

//�����ʱ�ǵ����еĶ�������
//#define str "hello world!"
//#define add(x, y) (x + y)//�����
//#define max(x, y) ((x)>(y)?(x):(y))
//int main()
//{
//	printf("%s\n", str);
//	int a = 100, b = 50;
//	printf("%d\n", add(a, b));
//	printf("%d\n", max(a, b));
//	return 0;
//}

//�ṹ������
//struct stu
//{
//	char name[20];//����ѧ��������
//	short age;
//	char sex[10];
//};
//struct book
//{
//	char name[20];
//	double price;
//	char id[20];
//};
//int main()
//{
//	struct stu s1 = { "����", 20, "��" };
//	struct stu* ps = &s1;
//	printf("%s %d %s\n", s1.name, s1.age, s1.sex);
//	printf("%s %d %s\n", (*ps).name, (*ps).age, (*ps).sex);
//	printf("%s %d %s\n", ps->name, ps->age, ps->sex);
//
//	return 0;
//}
int max (int x, int y)
{
	int z = x > y ? x : y;
	return z;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int c = max(a, b);
	printf("%d\n", c);
	return 0;
}