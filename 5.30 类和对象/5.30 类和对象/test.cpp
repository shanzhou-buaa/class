#include <iostream>
using namespace std;

//const Date* p1���ݲ���
//Date* const p1ָ���λ�ò���

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

	//��Ա�������Ĺ��ܣ�����Ҫ�޸ĳ�Ա����ʱ�����鶼����const
	//bool operator==(const Date* this, const Date& d)
	bool operator==(const Date& d) const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	//ȡ��ַ��������أ�����������
	//Ĭ�ϳ�Ա���������������ɵ�Ҳ����
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}

	//��һ������������������ڶ�������ʱ�Ҳ�����
	//cout�պ÷�������
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