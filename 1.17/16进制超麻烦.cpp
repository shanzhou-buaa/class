#include <stdio.h>
int main()
{
	int a;
	scanf("%x", &a);
	if ((a <= 0x1F && a >= 0x00)|| a == 0x7F)
		{
			printf("Control Character!\n");
			if (a == 0x00)
				printf("Null");
			else if (a == 0x09)
				printf("Horizontal Tab");
			else if (a == 0x0A)
				printf("Line Feed");
			else if (a == 0x0D)
				printf("Carriage Return");
			else
				printf("Other Control Character");
		}
	if ((a >= 0x20 && a <= 0x2F) || (a >= 0x5B && a <= 0x60) || (a >= 0x7B && a <= 0x7E) || (a >= 0x3A && a <= 0x40))
		{
			printf("Symbol Character!\n");
			if (a == 0x28 || a == 0x29 || a == 0x5B || a == 0x5D || a == 0x7B || a == 0x7D || a == 0x3C || a == 0x3E)
				printf("Bracket");
			else 
				printf("Other Symbol");
		}
	if(a >= 0x30 && a <= 0x39)
		{
			printf("Digit Character!\n");
			printf("%c", a);
		}
	if(a >= 0x41 && a <= 0x5A)
		{
			printf("Upper Case Alphabet!\n");
			printf("%c", a);
		}
	if(a >= 0x61 && a <= 0x7A)
		{
			printf("Lower Case Alphabet!\n");
			printf("%c", a );
		}
	return 0;
} 
