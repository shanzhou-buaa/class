#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//泛型编程
//模板：相似的代码，只有类型不同,逻辑相同

//template<class T>
//void Swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main()
//{
//	int a = 0, b = 1;
//	cout << a << " " << b << endl;
//	Swap(a, b);
//	cout << a <<" "<< b << endl;
//
//	double c = 5.02, d = 10.5;
//	cout << c << " " << d << endl;
//	Swap(c, d);
//	cout << c << " " << d << endl;
//
//	char e = 'e', f = 'f';
//	cout << e << " " << f << endl;
//	Swap(e, f);
//	cout << e << " " << f << endl;
//	return 0;
//}