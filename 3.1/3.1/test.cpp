#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//��̬�����޷������κηǾ�̬��Ա�������Ա����
//��Ϊ��̬�����в�����thisָ��


//class Date
//{
//public:
//	/*Date(int year)
//		:_year(year)
//	{}*/
//
//	void print()
//	{
//		cout << _year << "-" << _month << '-' << _day << endl;
//	}
//private:
//	//C++11֧��������ʱ��ȱʡֵ
//	int _year = 0;
//	int _month = 1;
//	int _day = 1;
//};

//int main()
//{ 
//	/*Date d1(2021);
//	d1.print();*/
//
//	Date d2;
//	d2.print();
//
//	return 0;
//}



//��Ԫ�����ɷ������˽�кͱ�����Ա����������ĳ�Ա����
//��Ԫ����������const����
//��Ԫ��������������κεط����������ܷ����޶�������
//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*void print()
//	{
//		cout << _year << "-" << _month << '-' << _day << endl;
//	}*/
//	
//	/*void operator<<(ostream& out)
//	{
//		out << _year << '/' << _month << "/" << _day << endl;
//	}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////void operator<<(ostream&out, const Date& d)
////{
////	out << d._year << "/" << d._month << "/" << d._day << endl;
////}
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "/" << d._month << "/" << d._day << endl;
//	return out;
//}
//
////cout �� ostream����
////cin �� istream����
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//	
//	return in;
//}
//
//int main()
//{
//	int i = 0;
//	Date d1(2021, 3, 1);
//	Date d2(2021, 3, 2);
//	//d.operator<<(cout);
//	//d << cout;//����operatorӦ������д�����ɶ��Ժܲ�
//
//	//cout << d;//����Ԫ���������������private�ڵĳ�Ա����
//	//cout << d1 << d2 << i << endl;
//	
//	Date d3;
//	Date d4;
//	cin >> d3 >> d4;
//	cout << d3;
//	cout << d4;
//
//	return 0;
//}


//class A
//{
//private:
//	//...
//
//public:
//	//...
//	class B
//	{
//	public:
//		//...
//	private:
//		//...
//	};
//};
//B��������A����Ԫ
//����BʱҪA::B