#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>
#include <errno.h>
#include <stdio.h>

//一个程序打开文件的个数是有限的
//所以要记得fclose 
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//
//	fputc('b', pf);
//	fputc('i', pf);
//	fputc('t', pf);
//	fputc(' ', pf);
//	fputc('!', pf);
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//stdout标准输出流，即屏幕
//int main()
//{
//	fputc('a', stdout);
//	fputc('b', stdout);
//	fputc('c', stdout);
//	fputc('d', stdout);
//
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//
//	/*printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));*/
//
//	char ch;
//	ch = fgetc(pf);
//	printf("%c ", ch);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//	{
//		return 1;
//	}
//
//	printf("%c", fgetc(stdin));
//	printf("%c", fgetc(stdin));
//	printf("%c", fgetc(stdin));
//	printf("%c", fgetc(stdin));
//
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//		return 1;
//	
//	fputs("hello bit\t", pf);
//	fputs("hello world\n", pf);
//	fputs("hello world\n", stdout);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (pf == NULL)
//		return 1;
//
//	char str[100] = { 0 };
//	while (fgets(str, 20, pf) != NULL)
//		printf("%s", str);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//struct s
//{
//	char name[20];
//	int age;
//	double score;
//};
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//		return 1;
//
//	struct s s1 = { "zhangsan", 20, 60.5 };
//	fprintf(pf, "%s %d %f", s1.name, s1.age, s1.score);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


