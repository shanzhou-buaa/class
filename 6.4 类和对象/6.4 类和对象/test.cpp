#include <iostream>
#include <string>
using namespace std;
//
//class Time
//{
//	//����λ�ö�����
//	//DateҪ����Time��Date��Time����Ԫ
//	//����ģ�Time���ܷ���Date
//	friend class Date;
//
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//	{
//		_hour = hour;
//		_minute = minute;
//		_second = second;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class A
//{
//public:
//	A(int x)
//	{
//		_x = x;
//	}
//private:
//	int _x;
//};
//
////���а������³�Ա�������ڳ�ʼ���б��ʼ��
////1.���� 2.const 3.�Զ������ͣ��Ҹ�����Ĭ�Ϲ��캯����
//class Date
//{
//	friend ostream& operator<<(ostream& out, const Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//
//public:
//	//���龡��ʹ�ó�ʼ���б��ʼ��
//	//��ʼ���б��ʼ��
//	//���Ի�����
//	Date(int year = 1970, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _n(1)
//		, ref(year)
//		, _a(1)
//	{
//		_day = day;
//		_t._hour = 1;
//		//_n = 10;//err
//		//_ref = year;//err
//		//_a(1 );
//	}
//
//	bool operator==(const Date& d) const
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//
//	//�����ڶ����ʱ���ʼ�� 
//	const int _n;
//	int& ref;//��Ա���������������Ƕ���
//	A _a;
//};
//
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day;
//
//	return in;
//}
//
//ostream& operator<<(ostream& out, const Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//
//	return out;
//}
//
//int main()
//{
//	Date d1(1970, 1, 1);
//	Date d2(2021, 5, 30);
//	cin >> d2 >> d1;
//	cout << d2 << d1;
//	return 0;
//}
//
//
//��Ա���������е�������������ڳ�ʼ���б��еĳ�ʼ��˳��
//�����ڳ�ʼ���б��е��Ⱥ�����޹�
//class A
//{
//public:
//	//_a2�ȶ���
//	A(int a)
//		: _a1(a)
//		, _a2(_a1)
//	{}
//	void Print()
//	{
//		printf("%d %d\n", _a1, _a2);
//	}
//private:
//	int _a2;
//	int _a1;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();
//
//	return 0;
//}
//
//class A
//{
//public:
//	//explicit A(int a)
//	A(int a)
//	{
//		_a = a;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//����explicit�Ͳ���д��
//	A a1 = 3;//���ڵ��������֧࣬����ʽ����ת��
//	return 0;
//}
//
//int main()
//{
//	A a1(1);//��׼�Ĺ��캯������
//	A a2 = 2;//��ʽ����ת�����������Ż���Ҳ��ֱ�ӹ���
//	A(3);//��������������������ֻ����һ��
//}

//��̬��Ա����û��thisָ�룬���ܷ��ʷǾ�̬��Ա
//��̬��Ա
class A
{
public:
	A(int a = 10)
	{
		_n++;
		_a = a;
	}
	A(const A& a)
	{
		_n++;
		_a = a._a;
	}
	static int GetN()
	{
		return _n;
	}
private:
	//n�洢�ھ�̬��������������
	static int _n;//���������ڹ��캯����ʼ��
	int _a;
};

//���������ж����˶��ٸ�����ΪA�ı���
int A::_n = 0;//��̬��Ա�����Ķ����ʼ��

int main()
{
	//cout << sizeof(A) << endl;
	A a1;
	A a2;
	A a3 = 2;
	//public������ô����
	//cout << A::_n << endl;
	//cout << a1._n << endl;
	cout << A::GetN() << endl;
	return 0;
}