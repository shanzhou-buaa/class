//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int n = 0;
//	int f1 = 0;
//	int f2 = 1;
//	int f3 = 0;
//	while (1)
//	{
//		if (n == f2)
//		{
//			printf("0\n");
//			break;
//		}
//		else if (n < f2)
//		{
//			if (abs(f1 - n) < abs(f2 - n))
//			{
//				printf("%d\n", abs(f1 - n));
//				break;
//			}
//			else
//			{
//				printf("%d\n", abs(f2 - n));
//				break;
//			}
//		}
//		else
//		{
//			f3 = f1 + f2;
//			f1 = f2;
//			f2 = f3;
//		}
//	}
//	return 0;
//}