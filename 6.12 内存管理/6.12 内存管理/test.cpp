#include <iostream>
using namespace std;

//直接在类内定义的函数，会当成内联函数
//new.delete和malloc.free用法相同
//失败了处理方式不同，malloc失败返回null，new失败抛异常

//class ListNode
//{
//public:
//	ListNode(int val = 0)
//		:_val(val)
//		, _prev(nullptr)
//		, _next(nullptr)
//	{}
//
//	//类专属的operator new
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
//	//定位new，replacement-new
//	A* p = (A*)malloc(sizeof(A));
//	new(p)A;//显式的对一块分配出来的空间用构造函数进行初始化
//	new(p)A(0);//后面的参数可有可无
//
//	//构造函数自动调用或定位new调用，不能直接显式调用
//	//析构函数可以显式调用
//	p->~A();
//	return 0;
//}

int main()
{
	void* p = malloc(1024 * 1024 * 1024);

	return 0;
}