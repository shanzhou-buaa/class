#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;


//对于内置类型，malloc和new一样，free和delete一样
//对于自定义类型不一样
//class A
//{
//public:
//	A()
//	{
//		_a = 0;
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	int* p1 = new int;//new操作符
//	int* p2 = (int*)malloc(sizeof(int));//malloc函数
//
//	A* p3 = (A*)malloc(sizeof(A));//申请空间
//	A* p4 = new A;//申请空间+构造函数初始化
//
//	free(p3);//释放空间
//	delete p4;//析构函数+释放空间
//
//	return 0;
//}


//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)* 10);
//
//	free(p1);
//	free(p3);
//
//
//	int* p2 = new int(10);//申请一个int的4字节空间，初始化为10
//	int* p4 = new int[10];//申请含10个int的40个字节的空间
//
//	delete p2;
//	delete[] p4;
//	return 0;
//}


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

