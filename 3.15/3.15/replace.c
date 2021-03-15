#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>


int main()
{
	char in[100], out[100];
	gets(in);
	gets(out);
	FILE* filein = fopen("filein.txt", "r");
	FILE* fileout = fopen("fileout.txt", "w");

	fclose(filein);
	fclose(fileout);

	return 0;
}