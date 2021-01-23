#include <stdio.h>
int main()
{
	long long int a, b;
	unsigned long long c, d, x;
	scanf("%lld%lld", &a, &b);
	if((a > 0) && (b > 0))
	{
		x = a + b;	
		if(x > 9223372036854775807)
			printf("PO!");
		else
			printf("%lld", x);
	}
	else if((a < 0) && (b < 0))
	{
		c = (unsigned long long) a;
		d = (unsigned long long) b;
		x = c + d;
		if(x > 9223372036854775809)
			printf("NO!");
		else if((c == 9223372036854775808) && (d = 9223372036854775808))
			printf("NO!");
		else
			printf("%lld", x);	
	}
	else
	{
		c = (unsigned long long) a;
		d = (unsigned long long) b;
		x = c + d;
		printf("%lld", x);
	}
	return 0;
}
