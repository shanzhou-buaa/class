#include <iostream>
using namespace std;

////C++11
//class B
//{
//public:
//	B(int x = 1)
//		:_x(x)
//	{
//		cout << "B()" << endl;
//	}
//public:
//	int _x;
//};
//
//class A
//{
//public:
//
//private:
//	//��������Ҳ�������Զ����ɵ�Ĭ�Ϲ��캯���ﱻ��ʼ��
//	int _a = 0;//ȱʡֵ
//	int* _p = nullptr;
//	int* arr = (int*)malloc(sizeof(int)* 4);
//	B _b = 20;
//};
//
//int main()
//{
//	A aa;
//	return 0;
//}

//typedef struct StackC
//{
//	int* a;
//	int size;
//	int capacity;
//}sc;
//
////ջ��������������������
//void f2()
//{
//	int b = 0;
//	cout << "b:"<<&b << endl;
//}
//
//void f1()
//{
//	int a = 0;
//	cout << "a:"<<&a << endl;
//	f2();
//}
//int main()
//{
//	//f1();
//	//һ������º�����ı�������Ĵ󣬵�Ҳ��һ��
//	int* c = (int*)malloc(4);
//	int* d = (int*)malloc(4);
//	cout << "c:" << &c << endl;
//	cout << "d:" << &d << endl;
//
//	return 0;
//}

//const����ı������ڳ��������г�����
//CCCAA AAADAB
//40 5 4 4 4 4


//malloc���Ͽ��ռ�
//calloc���Ͽ��ռ�+��ʼ����0
//realloc������еĿռ����ݣ�ԭ��/��أ�
//new/delete��malloc/free���**��������**û�в��
//new/delete new[]/delete[]
//int main()
//{
//	int* c1 = (int*)malloc(sizeof(int)* 10);
//	int* c2 = (int*)malloc(sizeof(int));
//	int* cpp1 = new int[10]
//	int* cpp2 = new int;
//
//	free(c1);
//	free(c2);
//	delete[] cpp1;
//	delete cpp2;
//
// 	return 0;
//}

typedef class ListNode
{
public:
	ListNode(int val = 0)
		:_val(val)
		, prev(nullptr)
		, next(nullptr)
	{}
private:
	int _val;
	ListNode* prev;
	ListNode* next;
}ln;

int main()
{
	ln* p1 = new ln;//new����Զ������ͣ����ռ�+��ʼ��
	ln* p2 = new ln(10);
	ln* arr = new ln[10]{1, 2, 3};//C++11
	delete p1;//delete����Զ������ͣ�����+�ͷſռ�
	delete p2;
	delete[] arr;

	int* a = new int[4]{1, 2, 3, 4};
	return 0;
}
//����4G�Ķ�̬�ڴ棬��x64