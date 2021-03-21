#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int n;
//int a[20], book[20];
//
//void dfs(int step)
//{
//	int i = 0;
//	if (step == n + 1)
//	{
//		for (i = 1; i <= n; i++)
//		{
//			printf("%d ", a[i]);
//		}
//		printf("\n");
//		return;
//	}
//	for (i = 1; i <= n; i++)
//	{
//		if (book[i] == 0)
//		{
//			a[step] = i;
//			book[i] = 1;
//			dfs(step + 1);
//			book[i] = 0;
//		}
//	}
//	return;
//}
//
//int main()
//{
//	scanf("%d", &n);
//	dfs(1);
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		printf("%s %d %d\n", __FILE__, __LINE__, i);
//	}
//	printf("%s\n%s\n", __DATE__, __TIME__);
//	return 0;
//}

#define print(data, format) printf("the value of "#data" is " format"\n", data)
int main()
{
	float f = 4.5f;
	int a = 10;
	double d = 15.1;
	print(f, "%f");
	print(a, "%d");
	print(d, "%lf");
}