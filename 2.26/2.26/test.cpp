#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//��������
//1.������������ǰ����~
//2.�޲������޷���ֵ
//3.һ�������ҽ���һ��������������ϵͳ���Զ�����Ĭ�ϵ���������
//4.�����������ڽ���ʱ��C++����ϵͳ�Զ�������������


//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////�Զ������Ͳ�����������Ƚϴ�С
////Ҫ�ȽϾ�Ҫ����������غ���ʵ��
////������м�����������operator�������м�������
//bool operator == (const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}
//
//
//int main()
//{
//	Date d1(2021, 2, 26);
//	Date d2 = d1;
//	Date d3(d1);
//	//�������죬���������ã���Ȼ������ݹ�
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	//d1 == d2 �� operator==(d1, d2)һ������ǰ�߼���ҿɶ���ǿ
//	int x = (d1 == d2) ? 1 : 0;//�������Զ�ת������һ�е�����
//	int y = (operator==(d1, d2)) ? 1 : 0;
//	cout << "x = " << x << endl;
//	cout << "y = " << y << endl;
//
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
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//������private�͵�����д
//	//dǰ������thisָ��
//	bool operator==(const Date& d)//bool operator==(Date* this, const Date& d)
//	{
//		//ǰ������this->_month,this->_day
//		return this->_year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	bool operator>(const Date&d)
//	{
//		if (_year > d._year)
//			return true;
//		else if (_year == d._year && _month > d._month)
//			return true;
//		else if (_year == d._year && _month == d._month&&_day > d._day)
//			return true;
//		else
//			return false;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2021, 2, 26);
//	Date d2 = d1;
//	Date d3(2021,2,28);
//	//�������죬���������ã���Ȼ������ݹ�
//
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	//d1 == d2 �� operator==(d1, d2)һ������ǰ�߼���ҿɶ���ǿ
//	//int x = (d1 == d2) ? 1 : 0;//�������Զ�ת������һ�е�����
//	//int y = (d1.operator==(d2)) ? 1 : 0;
//	//cout << "x = " << x << endl;
//	//cout << "y = " << y << endl; 
//	
//
//	int z = (d1 > d3) ? 1 : 0;
//	cout << "z = " << z << endl;
//
//	return 0;
//}


class stack
{
public:
	stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)* n);
		_size = 0;
		_capacity = n;
	}

	~stack()
	{
		free(_a);
		_a = nullptr;
		_size = 0;
		_capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};


int main()
{
	stack s1;
	stack s2(s1);
	//������s1��s2ָ��ͬһ��ռ�
	//ͬһ��ռ�����free����

	stack s3(30);
	//st1 = st3;
	return 0;
}