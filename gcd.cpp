#include <stdio.h>

int main()
{
	int a ,b ,gcd;
	scanf("%d%d", &a, &b);
	
	gcd = a;
	if (b < gcd)
	    gcd = b;
	
	while(!(a % gcd == 0 && b %gcd == 0))
	{
	gcd = gcd - 1;// gcd - -
    } 
	printf("%d",gcd);
	
	return 0;
}
