#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��ͬ���ֵ������ռ���Զ��ϲ�
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

//չ�������ռ�
//using namespace yh;

//ָ��չ��
//using yh::add;
//
//int main()
//{
//	printf("%d\n", yh::x);
//	printf("%d\n", yh::y);
//	printf("%d\n", add(1, 2b 
//	return 0;
//}

#include <iostream>//���������
//��stdչ��
//C++�������еĶ���������std�����ռ���
using namespace std;
//int main()
//{
//	//����ָ�����ͣ�cout�����Զ�ʶ������
//	//endl���ǻ��У�cout�ǿ���̨
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
//	//cin����
//	cin >> i >> d;
//	cout << i << endl << d << endl;
//	return 0;
//}


//a = 50��ȱʡ����
//���ò���ʱ�����ξ���ȱʡ����
//���ξͰ�ʵ����
//void f(int a = 50)
//{
//	cout << a << endl;
//}
//
//ȫȱʡ
//void f1(int a = 10, int b = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl << endl;
//
//}
//
//��ȱʡ
//���������������ȱʡ
//��f3(int a =1, int b, int c = 2)����
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


//��������(��ͬ�ĺ�����)
//������ͬ�����������ͻ������˳��ͬ����
//�Է���ֵ��Ҫ���಻��ͬ������
//���˷���ֵ��һ�������ܹ�������

//�������Ͳ�ͬ
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

//����������˳��ͬ
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
//	//�Ӹ�l��ʾ�ǳ�����
//	add(10l,20l);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	//int&�����壬��ʾ����
//	//��a��ȡ��������b
//	//a��bָ��ͬһ��ռ�
//	//һ�����������кܶ������ 
//  //���ñ����ڶ����ʱ��ͳ�ʼ��
//	int& b = a;
//	cout << b << endl;
//	b = 50;
//	cout << a << endl;
//	//����������ַһ��
//	cout << &a << endl << &b << endl;
//	return 0;
//}


//int main()
//{
//	int a = 2;
//	int& c = a;//c�����ͻ���int
//	int d = 50;
//	c = d;//�����Ǹ�ֵ
//	cout << a << endl;
//	return 0;
//}


int main()
{
	const int a = 10;
	const int& b = a;


	int c = 1;
	const int& d = c;//����
	return 0;
}


