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
	int& ra = a;//ra是a的别名
	
	int* pa = &a;//pa是指向a的指针

	int b = 10;
	int*& rp = pa;//rp是pa的别名，内容是a的地址
	rp = &b;//rp的内容改为b的地址

	return 0;
}