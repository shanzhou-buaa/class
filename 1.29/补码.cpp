#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#define min -2147483648
int main()
{
	int n, i, a[40]={0};
	scanf("%d", &n);
	if(n == min)
	{
		
	}
	else if(n < 0)
	{
		n = -n;
	}
	for(i = 1; i <= 32; i++)
	{
		a[i] = n % 2;
		n /= 2;
		printf("%d", a[i]);
	}
	
	return 0;
}

