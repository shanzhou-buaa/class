//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <string.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <ctype.h>
//
////#define SWAP(X) X=(((X&0x55555555)<<1)|((X&0xaaaaaaaa)>>1))
////
////int main()
////{
////	int a = 10;
////	//1.�����Ϊ��0λ�������ֵ�ż��λ����������λ ��Ϊ0������������һλ
////	//��λ�� 01010101010101010101010101010101
////	//��0x55555555
////	//2.�����ֵ�����λ������ż��λ ��Ϊ0������������һλ
////	//��λ�� 10101010101010101010101010101010
////	//��0xaaaaaaaa
////	//3.���õ����������ְ�λ��
////	SWAP(a);
////	printf("%d\n", a);
////	return 0;
////}
//
//
//
//#define OFFSETOF(struct_name, mem_name) (int)&(((struct_name*)0)->mem_name)
//
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", OFFSETOF(struct S, c));
//	printf("%d\n", OFFSETOF(struct S, i));
//	printf("%d\n", OFFSETOF(struct S, d));
//
//}