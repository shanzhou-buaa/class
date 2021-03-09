//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//int main()
//{
//	char a[1000] = { '\0' }, c[1000] = "";//a存输入，c存运算符号 
//	int b[1000] = { 0 }, sum = 0;//b存参与运算数字 
//	int i = 0, j = 0, h = 0, flag = 0, tem = 0;
//	gets(a);
//
//	for (i = 0; i<strlen(a); i++)
//	{//去空格 按照单位存入b 
//		if (a[i] == ' ')
//		{
//			flag = 0;
//			//printf("a");
//		}
//		else if ((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/'))
//		{
//			c[h] = a[i];
//			h++;
//			flag = 0;
//			//printf("b");
//		}
//		else if ((a[i] >= '0') && (a[i] <= '9'))
//		{
//			if (flag == 0)
//			{//数组b角标从1开始 
//				j++;
//				b[j] = a[i] - '0';
//				flag = 1;
//				//printf("c1");
//			}
//			else
//			{//前面一位是数字 构成一个整体的数 
//				tem = b[j];
//				b[j] = tem * 10 + (a[i] - '0');
//				flag = 1;
//				//printf("c2");
//			}
//		}
//	}
//	sum = b[1];
//	for (i = 0; i <= h; i++)
//	{
//		if (c[i] == '+' || c[i] == '-')
//		{
//			if ((c[i + 1] != '*') && (c[i + 1] != '/'))
//			{
//				if (c[i] == '+')
//					sum = sum + b[i + 2];
//				else if (c[i] == '-') 
//					sum = sum - b[i + 2];
//			}
//			else
//			{
//				int k = 0, temsum = 0;
//				temsum = b[i + 2];
//				for (k = i + 1; k<h; k++)
//				{
//					if (c[k] == '*') 
//						temsum = temsum*b[k + 2];
//					else if (c[k] == '/') 
//						temsum = temsum / b[k + 2];
//					else if (c[i] == '+' || c[i] == '-')
//						break;
//				}
//				if (c[i] == '+') 
//					sum = sum + temsum;
//				else if (c[i] == '-') 
//					sum = sum - temsum;
//				i = k - 1;
//			}
//		}
//		else if (c[i] == '*') 
//			sum = sum*b[i + 2];
//		else if (c[i] == '/') 
//			sum = sum / b[i + 2];
//	}
//
//	printf("%d", sum);
//	return 0;
//}
//2*2*2-9=