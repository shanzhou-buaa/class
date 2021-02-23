#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <iostream>
using namespace std;


//void swap_cpp(int& r1, int& r2)
//{
//	int tmp = r1;
//	r1 = r2;
//	r2 = tmp;
//}
//
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	cout << a << " " << b << endl;
//	swap_cpp(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}


//int& count2()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int& a = count2();
//	cout << a << endl;
//
//	a = count2();
//	cout << a << endl;
//}


//int& add2(int a, int b)
//{
//	//int c = a + b;//这样的写法不安全，执行其他程序后有可能被改变
//	static int c = 1;//加上static后安全
//	//static修饰的变量定义只执行一次，所以第二次进来不执行
//	c = a + b;//加上后变成7
//	
//	return c;
//}
//
//
//int main()
//{
//	int& ret = add2(1, 2);
//	cout << ret << endl;
//
//	add2(3, 4);
//	cout << ret << endl;
//}



//调用函数需要建立栈帧，频繁调用有消耗
//C语言用宏，C++用内联函数
//内联适用于代码少的函数
//内联函数声明和定义一定不能分开
//函数较长或者含有递归不适用于内联
//inline void Swap(int& a, int& b)
////在函数名前加个inline就行了
////空间换时间
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	 //调用的时候不用写inline
//	int a = 0, b = 2;
//	cout << a << " " << b << endl;
//
//	Swap(a, b);
//	cout << a << " " << b << endl;
//}


//int main()
//{
//	int a = 0;
//	auto b = a;//根据a推导b的类型
//	int& c = a;
//	auto d = &a;
//	auto& e = a;
//	//打印变量的类型
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	//注意name后面有()
//
//	return 0;
//}
//auto不能用作形参
//auto不能用来定义数组



//int main()
//{
//	/*int a[] = { 1, 2, 3, 4, 5 };
//	for (auto x : a)
//	{
//		x = x * 2;
//	}
//	for (auto x : a)
//	{
//		cout << x << " ";
//	}
//	cout << endl;*/
//	//上面改变的是x，而不是数组a
//	int a[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : a)
//	{
//		e *= 2;
//	}
//	for (int& e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}


//库中
//#define NULL 0
//#define nullptr (void*)0
//void fun(int n)
//{
//	cout << "整型" << endl;
//}
//
//void fun(int* n)
//{
//	cout << "整型指针" << endl;
//}
//
//int main()
//{
//	fun(0);
//	fun(NULL);
//	fun(nullptr);
//	return 0;
//}


//类包含：成员变量、成员方法
//			变量		函数

//class啥也不加默认是私有的
//struct默认是公有的
class student
{
public:
	void _show()
	{
		cout << _name << endl;
		cout << _age << endl;
		cout << _id << endl;
	}
	int GetAge()
	{
		return _age;
	}
private:
	char _name[10];
	int  _age;
	char _id[20];
};


int main()
{
	student s1;
	student s2;

	//int a = s1.age;
	//编译不过，不能访问private内的东西

}