#include <iostream>
using namespace std;

//�����ڶ����ʱ������ʼ��
//int main()
//{
//	int a = 10;
//	int& b = a;
//	int x = 20;
//	//������b���x�����ã����ǰ�x��ֵ��b
//	b = x;
//	return 0;
//}

//int main()
//{
//	//Ȩ����ͬ
//	const int a = 10;//ֻ���ĳ���
//	const int& b = a;//ֻ���ĳ�������
//
//	//Ȩ����С
//	int c = 10;//�ɶ���д
//	const int& d = c;//ֻ��
//
//	//Ȩ�޷Ŵ�
//	//const int e = 10;
//	//int& f = e;
//	return 0;
//}

//������
void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//������ֵ
//int& Add(int x, int y)
//{
//	static int c = x + y;
//	return c;
//}

//int main()
//{
//	int& ret = Add(1, 2);
//	cout << Add(5, 7) << endl;
//	printf("%d\n", ret);
//	return 0;
//}

//C����Ϊ�˱���С��������ջ֡���ṩ�꺯��֧�֣���Ԥ����׶ξ�չ��
//���ȱ��
//1.��֧�ֵ��� 2.�﷨���ӣ����׳��� 3.û�����͵ļ��

#define ADD(x, y) ((x) + (y))

//c++�Ƽ�Ƶ�����õ�С���������inline������������ڵ��õĵط�չ����û��ջ֡�Ŀ���
//������ȱ��
//ָ��Խ���ִ�г���ռ�õ��ڴ�Խ��
//���������������Ͷ������
inline int Add(int x, int y)
{
	return x + y;
}

//int main()
//{
//	int a = 10;
//	auto b = a;//auto�Զ��Ƶ�b������
//
//	return 0;
//}

//��Χfor c++11�����﷨�����򵥣�������Ϳ���
//�Զ�����������ȥ�������е�Ԫ�ظ�ֵ��xֱ����������

//int main()
//{
//	int a[] = { 1, 2, 3, 4, 5 };
//	for (auto x : a)
//		printf("%d ", x);
//
//	for (auto& x : a)
//		x *= 2;
//	for (auto x : a)
//		printf("%d ", x);
//	printf("\n");
//	return 0;
//}
//
//int main()
//{
//	int* a = nullptr;
//	return 0;
//}

//�ࣺ����һ���µ�����
//������
//1.��Ա���� 2.��Ա����
//class���ӷ����޶�����Ĭ��ȫ��˽�е�
//struct���ӷ����޶�����Ĭ��ȫ��˽�е�

//class Stack
//{
//public:
//	void Init(int InitCapacity = 4);
//	void Push(int x)
//	{
//		a[size++] = x;
//	}
//	void Print()
//	{
//		for (int i = 0; i < size; i++)
//			printf("%d ", a[i]);
//		printf("\n");
//	}
//private://����ֻ������
//	int* a;
//	int size;
//	int capacity;
//};
//
//void Stack::Init(int InitCapacity)
//{
//	a = (int*)malloc(sizeof(int)* InitCapacity);
//	size = 0;
//	capacity = InitCapacity;
//}
//
//int main()
//{
//	Stack st;//��Ա��������ĵط�
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Print();
//	printf("%d\n", sizeof(Stack));
//	return 0;
//}

//����(û�г�Ա����)�Ĵ�С��1
//��1���ֽڲ���Ϊ�˴洢���ݣ�����Ϊ��ռλ�ã���ʾ����������
class c1
{
	void f()
	{}
};

class c2
{};

int main()
{	
	printf("%d\n", sizeof(c1));
	printf("%d\n", sizeof(c2));
    return 0;
}
