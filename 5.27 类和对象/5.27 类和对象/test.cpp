#include <iostream>
using std::cout;
using std::endl;

//��������֧���������
//�Զ������ͣ�Ĭ�ϲ�֧��
//C++������������������������֧��ʹ��ĳ�������

//������
class Array
{
public:
	//��ʼ����1-9
	Array(int size = 10)
	{
		for (int i = 0; i < size; i++)
			_a[i] = i;
	}
	//[]���������
	//������������ֵ�������޸�
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
//		//��Դ�������������������������
//	}
//private:
//	//��Ա�����������������һ��
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