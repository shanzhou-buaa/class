#define _CRT_SECURE_NO_WARNINGS 1

////全排列的非递归实现
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void Swap(char *a, char *b)
//{
//	char t = *a;
//	*a = *b;
//	*b = t;
//}
////反转区间
//void Reverse(char *a, char *b)
//{
//	while (a < b)
//		Swap(a++, b--);
//}
////下一个排列
//int Next_permutation(char a[])
//{
//	char *pEnd = a + strlen(a);
//	if (a == pEnd)
//		return 0;
//	char *p, *q, *pFind;
//	pEnd--;
//	p = pEnd;
//	while (p != a)
//	{
//		q = p;
//		--p;
//		if (*p < *q) //找降序的相邻2数,前一个数即替换数
//		{
//			//从后向前找比替换点大的第一个数
//			pFind = pEnd;
//			while (*pFind <= *p)
//				--pFind;
//			//替换
//			Swap(pFind, p);
//			//替换点后的数全部反转
//			Reverse(q, pEnd);
//			return 1;
//		}
//	}
//	Reverse(p, pEnd);//如果没有下一个排列,全部反转后返回true
//	return 0;
//}
//int QsortCmp(const void *pa, const void *pb)
//{
//	return *(char*)pa - *(char*)pb;
//}
//int main()
//{
//	printf("         全排列的非递归实现\n");
//	printf("  --by MoreWindows( http://blog.csdn.net/MoreWindows )--\n\n");
//	char szTextStr[] = "12345678910";
//	printf("%s的全排列如下:\n", szTextStr);
//	//加上排序
//	qsort(szTextStr, strlen(szTextStr), sizeof(szTextStr[0]), QsortCmp);
//	int i = 1;
//	do{
//		printf("第%3d个排列\t%s\n", i++, szTextStr);
//	} while (Next_permutation(szTextStr));
//	return 0;
//}


#include<stdio.h>
int N;
int i, j;
int jiecheng[11];
int output[10];

int factorial(){
	jiecheng[0] = 1;
	int i;
	for (i = 1; i<=10; i++){
		jiecheng[i] = i*jiecheng[i - 1];
	}
}

void print(){
	int i = 0;
	for (i = 0; i<N - 1; i++)
		printf("%d ", output[i]);
	printf("%d\n", output[i]);
}

void find(){
	for (i = N - 2; i >= 0; i--){
		if (output[i]<output[i + 1])
			break;
	}
	int k1 = i;
	int temp_low = i + 1;
	for (i = k1 + 1; i<N; i++){
		if (output[i]>output[k1] && output[i]<output[temp_low])
			temp_low = i;
	}
	int temp;
	temp = output[k1];
	output[k1] = output[temp_low];
	output[temp_low] = temp;
	for (j = k1 + 1, i = N - 1; i>j; i--, j++){
		temp = output[i];
		output[i] = output[j];
		output[j] = temp;
	}
}

int main(){
	factorial();
	scanf("%d", &N);
	int i;
	for (i = 0; i<N; i++){
		output[i] = i + 1;
	}
	print();
	for (i = 1; i<jiecheng[N]; i++){
		find();
		print();
	}
}