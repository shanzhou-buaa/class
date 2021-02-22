#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//相同名字的命名空间会自动合并
namespace yh
{
	int x = 0;
	int y = 1;
}
namespace yh
{
	int add(int a, int b)
	{
		return a + b;
	}
}

//展开命名空间
//using namespace yh;

//指定展开
//using yh::add;
//
//int main()
//{
//	printf("%d\n", yh::x);
//	printf("%d\n", yh::y);
//	printf("%d\n", add(1, 2b 
//	return 0;
//}

#include <iostream>//输入输出流
//把std展开
//C++库中所有的东西都放在std命名空间中
using namespace std;
//int main()
//{
//	//不用指定类型，cout可以自动识别类型
//	//endl就是换行，cout是控制台
//
//
//	//cout << "HELLO WORLD!!!" << endl;
//	//std::cout << "HELLO WORLD!!!" << std::endl;
//	int a = 1;
//	double c = 3.14;
//	cout << a << endl << c << endl << '!' << "," << endl;
//	return 0;
//}


//int main()
//{
//	int i;
//	double d;
//	//cin输入
//	cin >> i >> d;
//	cout << i << endl << d << endl;
//	return 0;
//}


//a = 50是缺省参数
//调用参数时不传参就用缺省参数
//传参就按实参用
//void f(int a = 50)
//{
//	cout << a << endl;
//}
//
//全缺省
//void f1(int a = 10, int b = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl << endl;
//
//}
//
//半缺省
//必须从右往左连续缺省
//如f3(int a =1, int b, int c = 2)不行
//void f2(int a, int b = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl << endl;
//}
//int main()
//{
//	//f(10);
//	//f();
//
//	//f1();
//	//f1(1);
//	//f1(1, 2);
//
//	f2(1);
//	f2(1, 2);
//	return 0;
//}


//函数重载(相同的函数名)
//参数不同，参数的类型或个数或顺序不同即可
//对返回值无要求，相不相同都可以
//除了返回值都一样，不能构成重载

//参数类型不同
//double add(double a, double b)
//{
//	return a + b;
//}
//int add(int a, int b)
//{
//	return a + b;
//}
//long add(long a, long b)
//{
//	return a + b;
//}

//参数个数、顺序不同
//int f1(int i, char ch)
//{}
//
//int f1(char ch)
//{}
//
//int f1(char ch, int i)
//{}

//int main()
//{
//	//加个l表示是长整型
//	add(10l,20l);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	//int&是整体，表示引用
//	//给a再取个名字是b
//	//a、b指向同一块空间
//	//一个变量可以有很多个引用 
//  //引用必须在定义的时候就初始化
//	int& b = a;
//	cout << b << endl;
//	b = 50;
//	cout << a << endl;
//	//两个变量地址一样
//	cout << &a << endl << &b << endl;
//	return 0;
//}


//int main()
//{
//	int a = 2;
//	int& c = a;//c的类型还是int
//	int d = 50;
//	c = d;//这里是赋值
//	cout << a << endl;
//	return 0;
//}


int main()
{
	const int a = 10;
	const int& b = a;


	int c = 1;
	const int& d = c;//可以
	return 0;
}


