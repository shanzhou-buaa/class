#include <iostream>
using namespace std;

//int main()
//{
//	char ch = 0;
//	char& c = ch;
//	char* p = &ch;
//	printf("%d\n", sizeof(c));
//	printf("%d\n", ++c);
//	printf("%p\n", p);
//	printf("%p\n", ++p);
//	return 0;
//}

int main()
{
	int a = 10;
	int& ra = a;//ra��a�ı���
	
	int* pa = &a;//pa��ָ��a��ָ��

	int b = 10;
	int*& rp = pa;//rp��pa�ı�����������a�ĵ�ַ
	rp = &b;//rp�����ݸ�Ϊb�ĵ�ַ

	return 0;
}