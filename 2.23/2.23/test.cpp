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
//	//int c = a + b;//������д������ȫ��ִ������������п��ܱ��ı�
//	static int c = 1;//����static��ȫ
//	//static���εı�������ִֻ��һ�Σ����Եڶ��ν�����ִ��
//	c = a + b;//���Ϻ���7
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



//���ú�����Ҫ����ջ֡��Ƶ������������
//C�����ú꣬C++����������
//���������ڴ����ٵĺ���
//�������������Ͷ���һ�����ֿܷ�
//�����ϳ����ߺ��еݹ鲻����������
//inline void Swap(int& a, int& b)
////�ں�����ǰ�Ӹ�inline������
////�ռ任ʱ��
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	 //���õ�ʱ����дinline
//	int a = 0, b = 2;
//	cout << a << " " << b << endl;
//
//	Swap(a, b);
//	cout << a << " " << b << endl;
//}


//int main()
//{
//	int a = 0;
//	auto b = a;//����a�Ƶ�b������
//	int& c = a;
//	auto d = &a;
//	auto& e = a;
//	//��ӡ����������
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	//ע��name������()
//
//	return 0;
//}
//auto���������β�
//auto����������������



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
//	//����ı����x������������a
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


//����
//#define NULL 0
//#define nullptr (void*)0
//void fun(int n)
//{
//	cout << "����" << endl;
//}
//
//void fun(int* n)
//{
//	cout << "����ָ��" << endl;
//}
//
//int main()
//{
//	fun(0);
//	fun(NULL);
//	fun(nullptr);
//	return 0;
//}


//���������Ա��������Ա����
//			����		����

//classɶҲ����Ĭ����˽�е�
//structĬ���ǹ��е�
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
	//���벻�������ܷ���private�ڵĶ���

}