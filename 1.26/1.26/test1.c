#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

//int main()
//{
//	int *p = NULL;
//	int a[100];
//	printf("%d\n",sizeof(p));//��ֵ�Ƕ��٣�
//	printf("%d\n", sizeof(*p));
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(a[100]));
//	printf("%d\n", sizeof(&a));
//	printf("%d\n", sizeof(&a[0]));
//    return 0;
//}


//int main()
//{
//	int a = 0;
//	//00000000 00000000 00000000 00000000	a
//	int b = ~a;
//	//11111111 11111111 11111111 11111111	b�Ĳ���
//	//bԭ����-1
//	printf("%d\n", b);
//	return 0;
//}


//int main()
//{
//	char a = 3;
//	//00000101	a
//	char b = 127;
//	char c = a + b;
//	//01111111	b
//	//a,b��char�ͣ�����ʱ�������������int������
//	//�з�����ֱ����ǰ�油ԭ���ķ���λ
//	//�޷�����ֱ�Ӳ�0
//	//00000000 00000000 00000000 00000011	�����������a
//	//00000000 00000000 00000000 01111111	�����������b
//	//a+b
//	//00000000 00000000 00000000 10000010	�����������c
//	//10000010	�ضϺ��c
//	//11111111 11111111 11111111 10000010	�����������c�Ĳ���
//	//11111111 11111111 11111111 10000001	�����������c�ķ���
//	//10000000 00000000 00000000 01111110	-126
//	printf("%d\n", c);
//}