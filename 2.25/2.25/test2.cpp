#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//C++Ĭ�ϵĳ�Ա����
//1.���캯��
//(1)�ڶ�����ʱ�Զ����ã���ɳ�ʼ��
//(2)�޷���ֵ��ע�ⲻ��void����ɶҲ��д
//class Date
//{
//public:
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//�������أ���������ʱ����ʼ��
//	Date()
//	{
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
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
//	//���ù��캯��ʱд���ر�
//	//�ڶ������д�������������ں���������д
//	Date d1(2021,2,23);
//	d1.Print();
//	d1.Init(2021,2,24);
//	d1.Print();
//
//
//	Date d2;//d2����ǧ���ܼ�()
//	d2.Print();
//	return 0;
//}

//3.�������û����ʽ���庯��
//��������Զ�����һ���޲ε�Ĭ�Ϲ��캯��

//class Date
//{
//public:
//	//һ������ʽ���캯�����Ͳ�������
//	//û����ʽ���庯��������������Զ������޲ε�Ĭ�Ϲ��캯��
//	//���������ͣ�int��char...���ĳ�Ա������������
//	//���Զ���ĳ�Ա�������������ǵĹ��캯����ʼ��
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
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
//	//���ñ��������ɵĹ��캯��
//	Date d1;
//	d1.Print();
//	return 0;
//}



//Ĭ�Ϲ��캯��
//1.�Լ�ʵ�ֵ��޲ι��캯��
//2.�Լ�ʵ�ֵ�ȫȱʡ����
//3.�������Զ����ɵ�
//class Date
//{
//public:
//	//��ȫȱʡ�ܷ���
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	Date d2(2021);
//	d2.Print();
//
//	Date d3(2021,2);
//	d3.Print();
//	
//	Date d4(2021,2,24);
//	d4.Print();
//
//	return 0;
//}

//��������
//�ڶ�����������ڵ����Ժ��Զ�����
//�����������������������Դ�������������ٱ���
//����free��δfree��malloc
//class Date
//{
//public:
//	Date(int year = 0, int month = 0, int day = 0)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		printf("%d-%d-%d\n", _year, _month, _day);
//	}
//
//	~Date()//���������ǰ�Ӹ�~
//	{
//		cout << "~Date()" << endl;
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
//	Date d1;
//	d1.Print();
//
//	Date d2(2021);
//	d2.Print();
//
//	Date d3(2021, 2);
//	d3.Print();
//
//	Date d4(2021, 2, 24);
//	d4.Print();
//
//	return 0;
//}


class stack
{
public:
	stack(int n = 0)
	{
		_a = (int*)malloc(sizeof(int)* n);
	}
	~stack()
	{
		if (_a != nullptr)
		{
			free(_a);
			_a = nullptr;
			_size = 0;
			_capacity = 0;
			cout << "~stack()" << endl;
		}
	}
private:
	int* _a;
	int _size;
	int _capacity;
};


int main()
{
	stack s1;
	stack s2;
	//�ȴ���s1���ڴ���s2
	//������s2��������s1
	//�Ƚ����
	
	return 0;
}