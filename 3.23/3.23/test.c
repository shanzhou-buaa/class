#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

//宏好处
//宏的参数与类型无关
//宏比函数更加高效

//宏劣势
//不能调试
//如果宏的长度太长，代码长度会非常长
//宏可能导致运算符优先级的问题

//#define MAX(x, y) ((x) > (y) ? (x) : (y))
//int main()
//{
//	int a = 10, b = 20;
//
//	//传递给宏的参数有副作用
//	int c = MAX(a++, b++);
//	//c = MAX((a++)>(b++)?(a++):(b++))
//	printf("%d\n", c);
//	printf("%d\n", a);
//	printf("%d\n", b);
//
//	return 0;
//}


//宏的参数可以出现内置类型
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

//条件编译 - 满足条件才编译

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
 