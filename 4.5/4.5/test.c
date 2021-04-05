#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("in.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("in.txt", "w");
//
//	fputc('a', pf);
//	fputc('b', pf);
//	fputc('c', pf);
//	
//	fclose(pf);
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("in.txt", "r");
//
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//	printf("%c\n", fgetc(pf));
//
//	fclose(pf);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("in.txt", "w");
//
//	char* s = "hello world";
//	fputs(s, pf);
//
//	fclose(pf);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("in.txt", "r");
//
//	char s[1024] = { 0 };
//	fgets(s, 1023, pf);
//	printf("%s\n", s);
//
//	fclose(pf);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("in.txt", "r");
//
//	fseek(pf, 4, SEEK_SET);
//	printf("%c\n", fgetc(pf));
//
//	rewind(pf);
//	printf("%c\n", fgetc(pf));
//
//	fclose(pf);
//	return 0;
//}