#include <iostream>
using namespace std;

//C++��Ϊ��ֹ������ͻ���ѿ���Ķ�����������std��
//Ҫʹ�ñ�׼���еĶ����������ַ�ʽ
//�Լ������Ҳһ��

//using std::cout;
//using std::endl;
//
//int main()
//{
//	//1.ָ�������ռ䣬�淶���鷳
//	std::cout << "hello world" << std::endl;
//	//2.��stdչ����using namespace std;�൱�ڿ���Ķ�������ȫ����
//	//���Լ�����ı������������ı���ͬ��
//	cout << "hello world" << endl;
//	//3.�Բ��ֳ��õ�չ��
//	//using std::cout;
//	//using std::endl;
//	return 0;
//}

//C++����C���﷨
//int main()
//{
//	cout << "hello world" << endl;
//	return 0;
//}

#include <stdio.h>
#include <string.h>
//namespace�������һ����
//��Ϊ�˽��C����������ͻ������
//int main()
//{
//	int scanf = 20;
//	int strlen = 10;
//
//	scanf("%d", &scanf);
//	printf("%d\n", strlen);
//	return 0;
//}

//�����ռ��еı���������⺯�������ƻ����Ѿ�������ľֲ�������ͻ
//ͬһ�������ռ��еı�����������ͬ
//namespace N
//{
//	int scanf = 10;
//	int strlen = 20;
//	//int long ����
//	int Add(int x, int y)//���Զ��庯��
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
////ͬһ��������������ڶ����ͬ���Ƶ������ռ䣬��������������Ǻϲ���һ��
//int main()
//{
//	//��::(�������޶���)
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

//endl���з�
//�Ա�C����printf scanf�����Զ�ʶ������
//���Ի����ã��ĸ��������ĸ�
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	cout << "a:" << a << endl << "&a:" << p << endl;
//	cin >> a;//��Ҫȡ��ַ
//	cout << a << endl;
//	return 0;
//}

//ȱʡ��������Ĭ��ֵ��
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

//����ȱʡ�����������������ȱʡ
//ȱʡ�Ǹ�Ĭ��ֵ�ģ�Ĭ��ֵ�����ǳ���
//�����ں�������ʱ��ȱʡֵ
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

//C++���Զ���ͬ������-����������
//�������Ͳ�ͬ�����������ͬ
//�����޷����ذ�����ֵ�������ֵĺ���
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
//	//f(1, 2);//�����ص��������޷�ʶ������ĸ�
//
//	return 0;
//}

//����
//int main()
//{
//	int a = 10;
//	int& b = a;//b��a������
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