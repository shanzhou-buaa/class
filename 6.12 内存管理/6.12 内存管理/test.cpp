#include <iostream>
using namespace std;

//ֱ�������ڶ���ĺ������ᵱ����������
//new.delete��malloc.free�÷���ͬ
//ʧ���˴���ʽ��ͬ��mallocʧ�ܷ���null��newʧ�����쳣

//class ListNode
//{
//public:
//	ListNode(int val = 0)
//		:_val(val)
//		, _prev(nullptr)
//		, _next(nullptr)
//	{}
//
//	//��ר����operator new
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = allocator<ListNode>().allocate(1);
//		cout << "memory pool allocate" << endl;
//		return p;
//	}
//
//private:
//	ListNode* _prev;
//	ListNode* _next;
//	int _val;
//};
//
//int main()
//{
//	ListNode* p = new ListNode(1);
//	return 0;
//}


//class A
//{
//public:
//	A(int a = 1)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "A():" << this << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	//��λnew��replacement-new
//	A* p = (A*)malloc(sizeof(A));
//	new(p)A;//��ʽ�Ķ�һ���������Ŀռ��ù��캯�����г�ʼ��
//	new(p)A(0);//����Ĳ������п���
//
//	//���캯���Զ����û�λnew���ã�����ֱ����ʽ����
//	//��������������ʽ����
//	p->~A();
//	return 0;
//}

int main()
{
	void* p = malloc(1024 * 1024 * 1024);

	return 0;
}