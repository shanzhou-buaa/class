#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d%d",&a,&b);
	c = b - a;
	if(a<b)
	printf("%d",c);
	if(a>b)
	printf("0");
	if(a == b)
	{
	printf("0\n");
	printf("Indifferentiable Point");
	}
	return 0;
}

