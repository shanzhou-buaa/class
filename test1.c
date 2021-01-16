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
//    //float a = 55.6; 会报错，定义的浮点数默认是double类型
//	float a = 55.6f;//在数字后面加f就可以
//    return 0;
//}


//int a = 100;
//int main()
//{
//	int a = 20;
//	//一个大括号是一个代码块
//	//局部变量只能在对应的代码块内使用
//	//局部变量的作用域：其所在的局部范围
//	//全局变量的作用域：整个工程
//	{//内部的a创建
//		int a = 10;//中间就是a的生命周期
//		printf("a1 = %d\n", a);//10
//   //内部的a销毁
//	}
//	printf("a2 = %d\n", a);//20
//	//局部变量和全局变量冲突时，局部变量优先
//	return 0;
//}


//extern int test;//extern是用来声明外部变量的
//声明是只需声明类型、变量名即可
//int main()
//{
//	printf("test = %d\n", test);
//	return 0;
//}


////一个工程中多个项目总共只能有一个main函数
//enum sex
//{//枚举常量不初始化默认从0开始向下递增1
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
//	printf("%c\n", '\x1F');//要加''
//  return 0；
//}


//int main()
//{
//	printf("%d\n", strlen("c:\test\328\test.c"));
//	//c,:,\t,e,s,t,\32,8,\t,e,s,t,.,c
//	//8不是8进制数，所以\32是一个数(就是\032)
//}


//int main()
//{
//	auto int a = 10;//局部变量，自动产生，自动销毁，auto可省略
//	//所有的局部变量都是自动变量
//	return 0;
//}


//typedef unsigned int uint;//给c语言设定的关键字重新起名
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
//	int a = 1;//a是局部变量，每次进入都创建，初始化成1
//	a++;
//	printf("%d ", a);//出函数时a被销毁
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test1();//打印10个2
//		i++;
//	}
//	return 0;
//}


//void test1()
//{
//	static int a = 1;//static修饰局部变量，改变局部变量的生命周期，和main函数一样长
//	//作用域没变，仍然只能在函数内部使用
//	a++;
//	printf("%d ", a);//出函数时a被销毁
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

//static修饰全局变量，该全局变量只能在这个源文件内部使用
//在其他源文件中用extern声明时不能被链接到
//全局变量是具有外部链接属性的
//static修饰后，将全局变量的外部链接属性改为内部链接属性

//extern int Add(int x, int y);
////在test2.c中Add前加上static，变化同全局变量
//int main()
//{
//	int a = 10, b = 20;
//	int c = Add(a, b);
//	printf("%d\n", c);
//	return 0;
//}


//register是把变量放在寄存器上
//register修饰的变量不能取地址&

//定义宏时记得所有的都加括号
//#define str "hello world!"
//#define add(x, y) (x + y)//定义宏
//#define max(x, y) ((x)>(y)?(x):(y))
//int main()
//{
//	printf("%s\n", str);
//	int a = 100, b = 50;
//	printf("%d\n", add(a, b));
//	printf("%d\n", max(a, b));
//	return 0;
//}

//结构体类型
//struct stu
//{
//	char name[20];//描述学生的属性
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
//	struct stu s1 = { "张三", 20, "男" };
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