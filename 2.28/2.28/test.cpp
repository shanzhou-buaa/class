#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
 
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void print() const//void print(const Date* this);
//	{
//		//_year = 30;����ָ������ݲ��ܸı�
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	
//	//void print()//void print(Date* this);
//	//{
//	//	cout << _year << "-" << _month << "-" << _day << endl;  
//	//}
//
//	//const Date* p1 -->>*p1ָ�������
//	//Date* const p2 -->>*p2ָ�������
//	//Date* const p3 -->>p3ָ�뱾��
//	//const��*֮ǰ��ָ���������const
//	//const��*֮��ָ��ָ��ĵ�ַ��const
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//��������ȡ��ַ�������Լ���д��������Ҳ���Զ�����
//	//���������ɵľ��㹻��
//	Date* operator&()
//	{
//		cout << "Date* operator&()" << endl;
//
//		return this;
//	}
//
//	const Date* operator&() const
//	{
//		cout << "const Date* operator&() const" << endl;
//
//		return this;
//	}
//
//	//�ɣ��ɶ���д-��ֻ����Ȩ����С
//	/*void f1()
//	{
//		f2();
//	}
//
//	void f2() const
//	{}*/
//
//	//���ɣ�ֻ��-���ɶ���д��Ȩ�ޱ��
//	/*void f3()
//	{}
//
//	void f4() const
//	{
//		f3();
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 2, 28);
//	Date d2;
//	const Date d3;
//
//	cout << &d1 << endl;
//	cout << &d2 << endl;
//	cout << &d3 << endl;
//
//
//	return 0;
//}


//class Date
//{
//public:
//	//�������ڸ�ֵ
//	/*Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//��ʼ���б�
//	//�̶���ʽ���ԣ���ʼ���м��ö��ŷָ�
//	//������(),������=
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	//�����{}
//
//	void print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 2, 28);
//	d1.print();
//	return 0 ;
//}


//class A
//{
//public :
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//
//class B
//{
//public:
//public:
//	//����ĳ�Ա�����Ķ���
//	//��ʼ����˳���private������˳����ͬ
//	B(int a, int ref)
//		:_aobj(1)
//		, _ref(ref)
//		, _n(10)
//		//�ȳ�ʼ��_n����_aobj�����_ref
//	{}
//private:
//	//�������ֳ�Ա�����ڳ�ʼ���б��ʼ��
//	const int _n;//const
//	A _aobj;//û��Ĭ�Ϲ��캯��
//	//Ĭ�Ϲ��캯�����ô���
//	int& _ref;//����
//	//����ĳ�Ա����������
//};
//
//int main()
//{
//	B b(1, 2);//����Ķ���
//	return 0;
//}


//class Date
//{
//public:
//	explicit Date(int year)
//		:_year(year)
//	{}
//private:
//	int _year;
//};
//
//
//int main()
//{
//	Date d1(1);//ֱ�ӹ���
//
//	//���	explicit Date(int year)������һ�в��Ϸ�	
//	//Date d2 = 2;//�ȹ���tmp(2), ��Date(tmp)(����������)
//	//ʵ�ʹ������ϣ�������Ż�Ϊ��d1һ����ֱ�ӹ���
//	
//	Date d3 = d1;//��������
//	return 0;
//}

