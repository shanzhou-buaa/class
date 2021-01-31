#include <stdio.h>
int main()
{
	char c[]="TD ";
	int i, x;
    scanf("%d", &x);
	for(i=0; i<x*48; i++)
	   printf("%s",c);
	return 0;
}
