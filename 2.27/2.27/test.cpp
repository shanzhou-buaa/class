#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//ʵ��һ�����Ƶ�������
class Date
{
public:
	/*int GetMonthDay(int year, int month)
	{
	//����static��ֹÿ�ν���������
	static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 400 != 0)))
	return 28;
	return monthDays[month];
	}*/
	int GetMonthDay(int year, int month) const
	{
		if (month == 1 || month == 3 || month == 5 || month == 7
			|| month == 8 || month == 10 || month == 12)
			return 31;
		else if (month == 4 || month == 6 || month == 9 || month == 11)
			return 30;
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0 && year % 400 != 0))
				return 29;
			else
				return 28;
		}
	}

	int GetYearDay(int year) const
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 400 != 0))
			return 366;
		else
			return 365;
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
			cout << "false" << endl;
	}

	//Date d2(d1);����Date d2 = d1;
	//d2�������ڣ�����d2ʱ��d1������d2
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//Date d2;
	//d2 = d1;-->>������ת���d2.operator=(d1)
	//���Ǹ�ֵ
	//d2��d1�����ڣ���d1��ֵ��d2
	Date& operator=(const Date& d)
	{
		if (this != &d)//d2 = d2ʱ����ȥ
		{
			//d2       d1
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		//this�ǵ�ַ
		return *this;//d2
	}

	//Date(const Date& d)��Date& operator=(const Date& d)
	//���ε��������������������д���Կ���
	//1.���Լ���ʵ������������ʱ�����������Զ�����Ĭ�Ϲ��캯������������
	//�������͵ĳ�Ա������������
	//�Զ������͵ĳ�Ա�������й��������
	//2.���Լ���ʵ������������ʱ�������������ɿ��������operator=
	//�Ұ����ֽ���һ���ֽ�һ���ֽڽ��п�����ǳ������


	void Print() const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	inline bool operator>(const Date&d) const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month&&_day > d._day)
			return true;
		else
			return false;
	}

	inline bool operator==(const Date& d) const
	{
		return ((_year == d._year) && (_month == d._month) && (_day == d._day));
	}

	//��������ؾ������Զ�����������������һ�����������������
	//������this 
	bool operator>=(const Date& d) const
	{
		return ((*this > d) || (*this == d));
	}

	//<����>=ȡ��
	bool operator<(const Date& d) const
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d) const
	{
		return !(*this > d);
	}

	//!=����==ȡ!
	bool operator!=(const Date& d) const
	{
		return !(*this == d);
	}

	Date operator+(int day) const
	//������+������+=
	{
		//Date ret = *this;//ret(*this)
		//ret._day += day;
		//while (ret._day > GetMonthDay(ret._year, ret._month))
		//{
		//	ret._day -= GetMonthDay(ret._year, ret._month);
		//	ret._month++;
		//	if (ret._month > 12)
		//	{
		//		ret._month -= 12;
		//		ret._year++;
		//	}
		//}
		//return ret;
		Date ret = *this;
		ret += day;//ret.operator += (day);
		return ret;
	}

	Date& operator+=(int day)
	//������+=������+
	{
		if (day < 0)
			return *this -= -day;
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_month -= 12;
				_year++;
			}
		}
		return *this;
	}

	Date operator-(int day) const
	{
		/*Date ret = *this;
		ret._day -= day;
		while (ret._day <= 0)
		{
			ret._month--;
			if (ret._month <= 0)
			{
				ret._year--;
				ret._month += 12;
			}
			ret._day += GetMonthDay(ret._year, ret._month);
		}
		return ret;*/
		Date ret = *this;
		ret -= day;
		return ret;
	} 

	//d1 -= 10 -->> d1.operator-=(&d1, 10)
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month <= 0)
			{
				_year--;
				_month += 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	//Լ������ ++d1
	Date& operator++()
	{
		*this += 1;

		//����++֮���ֵ
		return *this;
	}

	//Լ������ d1++
	Date operator++(int)
	//�����intû�ã�Ҳ����Ҫ����
	//ֻ��Ϊ�˺������ǰ��++����
	//���ɺ�������
	{
		Date tmp(*this);
		*this += 1;

		//����++֮ǰ��ֵ
		return tmp;
	}

	int operator-(const Date& d) const
	{
		Date small = *this;
		Date large = d;
		int flag = -1;
		if (*this > d)
		{
			small = d;
			large = *this;
			flag = 1;
		}
		int sum = 0;
		while (small != large)
		{
			++sum;
			++small;
		}
		return sum * flag;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2021, 3, 10);
	Date d2(2021, 2, 24);
	cout << "d1 - d2 = " << (d1 - d2) << endl;
	cout << "d2 - d1 = " << (d2 - d1) << endl;
	return 0;
}


//int main()
//{
//	Date d1(2021, 2, 27);
//	Date d2 = d1;
//	d2.Print();
//
//	d1 -= 30;
//	d1.Print();
//
//	d2 += -30;
//	d2.Print();
//
//	d1 += -60;
//	d2 -= 60;
//	d1.Print();
//	d2.Print();
//
//
//	/*d1++;
//	d1.Print();
//
//	++d1;
//	d1.Print();*/
//
//	return 0;
//}


//int main()
//{
//	Date d1(2020, 4, 11);
//	//Date d2(-1, 0, 1);
//	//Date d3(-2, 13, 1);
//	//Date d4(2021, 2, 30);
//	Date d5(2000, 2, 29);
//
//	d1.Print();
//	d5.Print();
//	cout << (d1 > d5) << endl;
//
//
//	Date d6 = d1 + 10;
//	d6.Print();
//
//
//	Date d7 = d1 + 1000;
//	d7.Print();
//
//
//	d1 += 100; 
//	d1.Print();
//
//
//	//Date d8;
//	//d8.Print();
//	//d8 = d1;
//	//d8.Print();
//
//
//	return 0;
//}