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
////	//1.最左边为第0位，把数字的偶数位保留，奇数位 置为0；在整体左移一位
////	//按位或 01010101010101010101010101010101
////	//即0x55555555
////	//2.把数字的奇数位保留。偶数位 置为0；再整体右移一位
////	//按位或 10101010101010101010101010101010
////	//即0xaaaaaaaa
////	//3.将得到的两个数字按位或
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