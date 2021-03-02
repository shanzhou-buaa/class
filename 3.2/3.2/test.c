#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	//&a：写a的地址的内容
//	//4：写4个字节的数据
//	//1：写1个这样的数据
//	//pf：放到pf指向的文件夹
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");
//	if (pf == NULL)
//	{
//		printf("error\n");
//		return 0;
//	}
//	printf("success\n");
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pfWrite = fopen("test2.txt", "w");
//	if (pfWrite == NULL)
//	{
//		printf("error\n");
//		return 0;
//	}
//	//把字符放进文件
//	fputc('b', pfWrite);
//	fputc('i', pfWrite);
//	fputc('t', pfWrite);
//
//	fclose(pfWrite);
//	pfWrite = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pfRead = fopen("test2.txt", "r");
//	if (pfRead == NULL)
//	{
//		printf("error\n");
//		return 0;
//	}
//	//把字符放进文件
//	printf("%c ", fgetc(pfRead));
//	printf("%c ", fgetc(pfRead));
//	printf("%c ", fgetc(pfRead));
//
//	fclose(pfRead);
//	pfRead = NULL;
//	return 0;
//}


//stdin标准输入，包括键盘
//stdout标准输出，包括显示器
//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch, stdout);
//	return 0;;
//}


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test2.txt", "r");
//	fgets(buf, 1024, pf);
//	//printf("%s\n", buf);
//	puts(buf);
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* pf = fopen("test2.txt", "w");
//	fputs("hello\n", pf);
//	fputs("world\n", pf);
//
//	return 0;
//}

//struct S
//{
//	int n;
//	double d;
//	char arr[50];
//};
//int main()
//{
//	FILE* pf = fopen("text3.txt", "w");
//	struct S s1 = { 10, 3.14, "hello world!" };
//	fprintf(pf, "%d %f %s", s1.n, s1.d, s1.arr);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


struct S
{
	int n;
	double d;
	char arr[50];
};
int main()
{
	FILE* pf = fopen("text3.txt", "r");
	struct S s1 = {0};
	fscanf(pf, "%d %lf %s", &(s1.n), &(s1.d), s1.arr);
	printf("%d %f\n", s1.n, s1.d);
	fputs(s1.arr, pf);
	puts(s1.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}