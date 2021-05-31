#include <iostream>
using namespace std;

//const Date* p1内容不变
//Date* const p1指向的位置不变

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
		
public:
	Date(int year = 1970, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//成员函数中心功能，不需要修改成员变量时，建议都加上const
	//bool operator==(const Date* this, const Date& d)
	bool operator==(const Date& d) const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	//取地址运算符重载，基本无意义
	//默认成员函数，编译器生成的也够用
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}

	//第一个参数是左操作数，第二个参数时右操作数
	//cout刚好反过来了
	//void operator<<(ostream& out)
	//{
	//	out << _year << "-" << _month << "-" << _day << endl;
	//}

	void operator>>(istream& in);

private:
	int _year;
	int _month;
	int _day;
};

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;

	return in;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;

	return out;
}

int main()
{
	Date d1(1970, 1, 1);
	Date d2(2021, 5, 30);
	cin >> d2 >> d1;
	cout << d2 << d1;
	return 0;
}