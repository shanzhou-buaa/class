#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;


//��װ
//1.�����ݺͷ���������һ��
//2.������㿴�ĸ��㿴��������㿴�ķ�װ����(�÷����޶���private,publicʵ��)
//class Stack
//{
//public:
//	//1.��Ա����
//	void Push(int x)
//	{
//		;//��һ�ֶ��巽��
//	}
//	void Pop();
//	bool Empty();
//	//2.��Ա����
//private:
//	int* _a;
//	int _size;
//	int _capacity;
//
//};
////�ڶ��ֶ��巽��
//void Stack::Pop()
//{
//	;
//}
//
////C++��structҲ�ɵ�����
//struct ListNode_CPP
//{
//	int val;
//	ListNode_CPP* prev;
//	struct ListNode_CPP* next;
//	//C++������д������
//};
//
////C++��classĬ��˽�У�structĬ�Ϲ���
//
//class A1
//{};
//
//class A2
//{
//	void f();
//};
//int main()
//{
//	//ֻ�����Ա�����Ĵ�С
//	//���Ӻ���
//	cout << sizeof(Stack) << endl;//12
//	//һ����ʵ���������ɸ�����ÿ�����󶼿ɴ洢��ͬ��ֵ
//	//�����õĳ�Ա������ͬ
//	//���ÿ�����󶼷ų�Ա����
//	//�ͺ��˷ѿռ䣬���Է�����Щ�������⹫���Ŀռ�
//
//
//	//û�г�Ա��������Ĵ�С��1
//	cout << sizeof(A1) << endl;//1
//	cout << sizeof(A2) << endl;//1
//	//��С��1������Ϊ�˴�����
//	//����Ϊ��ռ��λ�ã�ȡ��ַʱ����Ψһ�ĵ�ַ��������������
//
//	return 0;
//}


class date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << '-' << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	date d1;
	d1.Init(2021, 2, 24);
	d1.Print();

	date d2;
	d2.Init(2021, 2, 22);
	d2.Print();
	return 0;
}