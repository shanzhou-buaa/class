#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <ctype.h>



//switch�������������������ͱ��ʽ
//case������������ͳ������ʽ�����͡�������
//�ַ��ͱ��������ͣ�Ҳ���Է�

 
int main()
{
	int i = 1;
	int sum = 0;
	int mul = 1;
	for (i = 1; i <= 10; i++)
	{
		mul *= i;
		sum += mul;
	}
	printf("%d", sum);
	return 0;
}


//int main()
//{
//	char password[50];
//	printf("��������:");
//	scanf("%s", password);
//	int ch = 0;
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	printf("��ȷ��(Y/N):");
//	ch = getchar();
//	if ('Y' == ch)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("0\n");
//	}
//	return 0;
//}


//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//		{
//			continue;//��������ѭ��continue����Ĵ��룬ֱ�ӷ���ѭ����ڽ�����һ��ѭ����ڵ��ж�
//		}
//		printf("%d ", i);//��ӡ1 2 3 4 Ȼ����ѭ��
//		i++;
//	}
//}


//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//		case 1:
//		case 2:
//		case 3:
//		case 4:
//		case 5:
//			printf("������\n");
//			break;
//	    case 6:
//	    case 7:
//			printf("��Ϣ��\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//	}
//}


//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)//i+=2Ч�ʸ�
//	{
//		if (1 == i % 2)
//		{
//			printf("%d ", i);
//		}
//		if (99 == i)
//		{
//			printf("\n");
//		}
//	}
//    return 0;
//}