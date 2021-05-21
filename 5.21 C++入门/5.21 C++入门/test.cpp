#include <iostream>
using namespace std;

//C++库为防止命名冲突，把库里的东西都定义在std中
//要使用标准库中的东西，有三种方式
//自己定义的也一样

//using std::cout;
//using std::endl;
//
//int main()
//{
//	//1.指定命名空间，规范但麻烦
//	std::cout << "hello world" << std::endl;
//	//2.把std展开：using namespace std;相当于库里的东西到了全局域
//	//但自己定义的变量可能与库里的变量同名
//	cout << "hello world" << endl;
//	//3.对部分常用的展开
//	//using std::cout;
//	//using std::endl;
//	return 0;
//}

//C++兼容C的语法
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

#include <stdio.h>
#include <string.h>
//namespace定义的是一个域
//是为了解决C语言命名冲突的问题
//int main()
//{
//	int scanf = 20;
//	int strlen = 10;
//
//	scanf("%d", &scanf);
//	printf("%d\n", strlen);
//	return 0;
//}

//命名空间中的变量不会与库函数的名称或者已经定义过的局部变量冲突
//同一个命名空间中的变量名不能相同
//namespace N
//{
//	int scanf = 10;
//	int strlen = 20;
//	//int long 不行
//	int Add(int x, int y)//可以定义函数
//	{
//		return x + y;
//	}
//	namespace N1
//	{
//		int Sub(int x, int y)
//		{
//			return x - y;
//		}
//	}
//}
//#include "Test.h"
////同一个工程中允许存在多个相同名称的命名空间，编译器最后会把它们合并到一起
//int main()
//{
//	//用::(域作用限定符)
//	printf("%d\n", N::scanf);
//	printf("%d\n", N::strlen);
//	printf("%d\n", N::Add(1, 2));
//	printf("%d\n", N::N1::Sub(3, 2));
//	N::ListNode* head = (N::ListNode*)malloc(sizeof(N::ListNode));
//	head->data = 1;
//	head->next = NULL;
//
//	return 0;
//}

//endl换行符
//对比C语言printf scanf可以自动识别类型
//可以混着用，哪个方便用哪个
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	cout << "a:" << a << endl << "&a:" << p << endl;
//	cin >> a;//不要取地址
//	cout << a << endl;
//	return 0;
//}

//缺省参数（给默认值）
//void test1(int a = 20)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	test1(10);
//	test1(0);
//	test1();
//	return 0;
//}

//部分缺省，必须从右往左连续缺省
//缺省是给默认值的，默认值必须是常量
//建议在函数声明时给缺省值
//void test2(int a, int b = 10, int c = 20)
//{
//	cout << a << " " << b << " " << c << endl;
//}
//
//int main()
//{
//	test2(1);
//	test2(1, 2);
//	test2(1, 2, 3);
//}

//C++可以定义同名函数-》函数重载
//参数类型不同或参数个数不同
//但是无法重载按返回值类型区分的函数
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}
//
//int Add(int a, int b, int c)
//{
//	return a + b + c;
//}
//
//
//void f(int a, int b, int c = 1){}
//void f(int a, int b){}
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.5, 2.5) << endl;
//	cout << Add(1, 2, 3) << endl;
//	//f(1, 2);//是重载但编译器无法识别调用哪个
//
//	return 0;
//}

//引用
//int main()
//{
//	int a = 10;
//	int& b = a;//b是a的引用
//	cout << &a << " " << &b << endl;
//	cout << a << endl;
//	b = 20;
//	cout << a << endl;
//
//	return 0;
//}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 10, b = 20;
	cout << a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}