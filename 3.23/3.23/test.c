#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//��ô�
//��Ĳ����������޹�
//��Ⱥ������Ӹ�Ч

//������
//���ܵ���
//�����ĳ���̫�������볤�Ȼ�ǳ���
//����ܵ�����������ȼ�������

//#define MAX(x, y) ((x) > (y) ? (x) : (y))
//int main()
//{
//	int a = 10, b = 20;
//
//	//���ݸ���Ĳ����и�����
//	int c = MAX(a++, b++);
//	//c = MAX((a++)>(b++)?(a++):(b++))
//	printf("%d\n", c);
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//	return 0;
//}


//��Ĳ������Գ�����������
//#define MALLOC(num, type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	free(p);
//	p = NULL;
//	return 0;
//}


//#define MAX 100
//
//int main()
//{
//#undef MAX
////#define MAX 200
//	printf("%d\n", MAX);
//	return 0;
//}

//�������� - ���������ű���

//#define __DEBUG__ 1
//int main()
//{
//	int i;
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d ", i);
//#ifdef __DEBUG__
//		printf("haha\n");
//#endif
//	}
//}
 