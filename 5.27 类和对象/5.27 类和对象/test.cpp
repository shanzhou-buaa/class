#include <iostream>
using std::cout;
using std::endl;

//内置类型支持运算符、
//自定义类型，默认不支持
//C++可以用运算符重载来让类对象支持使用某个运算符

//数组类
class Array
{
public:
	//初始化成1-9
	Array(int size = 10)
	{
		for (int i = 0; i < size; i++)
			_a[i] = i;
	}
	//[]运算符重载
	//用引用做返回值还可以修改
	int& operator[](size_t pos)
	{
		return _a[pos];
	}
private:
	int _a[10];
};

int main()
{
	Array arr;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;

	arr[0] = 300;
	arr[1] = 500;
	arr[2] = 600;
	arr[3] = 900;

	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[3] << endl;
	return 0;
}

//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	bool operator==(Date d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	bool operator<(Date d)
//	{
//		if (_year < d._year)
//			return true;
//		else if (_year == d._year)
//		{
//			if (_month < d._month)
//				return true;
//			else if (_month == d._month)
//			{
//				if (_day < d._day)
//					return true;
//				else if (_day == d._day)
//					return false;
//				else
//					return false;
//			}
//			else
//				return false;
//		}
//		else
//			return false;
//	}
//
//	Date operator-(int day)
//	{}
//
//	~Date()
//	{
//		//资源的清理，这里的析构函数无意义
//	}
//private:
//	//成员变量，命名风格区分一下
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1(2021, 5, 26);
//	Date d2(19170, 1, 1);
//	printf("%d\n",d1 == d2);
//	//printf("%d\n", d1.operator==(d2));
//	printf("%d\n", d1 < d2);
//
//	return 0;
//}