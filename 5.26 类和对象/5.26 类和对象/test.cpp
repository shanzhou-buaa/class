#include <iostream>
using namespace std;

//class Date
//{
//public: 
//	//������������һ�������Ĳ���-��void Init(Date* this, int year = 1970, int month = 1, int day = 1)
//	//�����ģ�����д���������ǿ���ֱ��ʹ��
//	void Init(int year = 1970, int month = 1, int day = 1)
//	{
//		this->_year = year;
//		_month = month;
//		_day = day;
//		printf("this:%p\n", this);
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
//	//���õ�init��ͬһ������
//	Date d1;
//	d1.Init(2021, 5, 24);//d1.Init(&d1, 2021, 5, 24);
//	printf("d1:%p\n", &d1);
//
//	Date d2;
//	d2.Init(2021, 5, 25);
//	printf("d2:%p\n", &d2);
//
//	return 0;
//}

//class Date
//{
//public:
//	//������ʲô��������д��ʱ�򣬱��������Զ�����6��������Ĭ�ϳ�Ա����
//	//1.���캯������ɶ���ĳ�ʼ��������ʵ����ʱ�Զ�����
//	//�Լ������Init���ܻ����ǵ��ã�C++Ϊ�˽��������⣬���빹�캯��
//	Date(int year = 1970, int month = 1, int day = 1)//�޷���ֵ
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//Date()//���أ�������ʱ�������
//	//{
//	//	_year = 1970;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//private:
//	//��Ա�����������������һ��
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
//	//��д���캯��,���������Զ�����һ�����캯��
//	//ԭ�����Ͳ���ʼ�����Զ������ͻ�������ǵ�Ĭ�Ϲ��캯������ʼ��
//	void Print()
//	{
//		printf("%d-%d-%d", _year, _month, _day);
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
//	Date d1;
//	d1.Print();
//	return 0;
//}

//Ĭ�Ϲ��캯�������ҽ���һ��
//1.��д��������Ĭ������
//2.�Լ�д���޲ε�
//3.�Լ�д��ȫȱʡ��
//���ǲ��ô��ξͿ��Ե��õĹ��캯��
//class Date
//{
//public:
//
//private:
//	//��Ա�����������������һ��
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	
//	return 0;
//}


//��������������ɶ�������٣�������������ɱ�������ɵ�
//�����������ǻ��Զ���������������������Դ������
//��������������ǰ��~
//�޲������޷���ֵ
//һ�������ҽ���һ��������������δ��ʽ�����ڣ���ϵͳ�Զ�����
//�����������ڽ���ʱ��C++����ϵͳ�Զ�������������
//class Date
//{
//public:
//	Date(int year = 1970, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	~Date()
//	{
//		//��Դ�������������������������
//		printf("~Date\n");
//	}
//private:
//	//��Ա�����������������һ��
//	int _year;
//	int _month;
//	int _day;
//};
//
//class Stack
//{
//public:
//	Stack(int capacity =  4)
//	{
//		_a = (int*)malloc(sizeof(int)*capacity);
//		_size = 0;
//		_capacity = capacity;
//	}
//	~Stack()
//	{
//		//������Դ���Զ�����
//		free(_a);
//		_a = nullptr;
//		_size = 0;
//		_capacity = 0;
//		printf("~Stack\n");
//	}
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//};
//
//int main()
//{
//	//s1��������main��������ջ֡��ջ֡�ж���Ĺ��������ҲҪ����ȳ�
//	Date d1;
//	Stack s1;
//	return 0;
//}