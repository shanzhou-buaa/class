#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;


//�����������ͣ�malloc��newһ����free��deleteһ��
//�����Զ������Ͳ�һ��
//class A
//{
//public:
//	A()
//	{
//		_a = 0;
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	int* p1 = new int;//new������
//	int* p2 = (int*)malloc(sizeof(int));//malloc����
//
//	A* p3 = (A*)malloc(sizeof(A));//����ռ�
//	A* p4 = new A;//����ռ�+���캯����ʼ��
//
//	free(p3);//�ͷſռ�
//	delete p4;//��������+�ͷſռ�
//
//	return 0;
//}


//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int)* 10);
//
//	free(p1);
//	free(p3);
//
//
//	int* p2 = new int(10);//����һ��int��4�ֽڿռ䣬��ʼ��Ϊ10
//	int* p4 = new int[10];//���뺬10��int��40���ֽڵĿռ�
//
//	delete p2;
//	delete[] p4;
//	return 0;
//}


void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

