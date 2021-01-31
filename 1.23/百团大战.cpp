#include <stdio.h>
int main()
{
	int n, x = 3, num = 0, a0, a1, a2, a3, a4;
	long long int sum = 0;
	scanf("%d%d%d%d", &n, &a1, &a2, &a3); //a1a2a3前三个摊位
	a0 = a1;
	a4 = a2;
	while (x < n)
	{
			if ((a2 > a1) && (a2 > a3))
			{
				num++;
				sum = sum + a2;
			}
			a1 = a2;
			a2 = a3;
			scanf("%d", &a3);
			x++;
	}
	if ((a2 > a1) && (a2 > a3))
		{
			num++;	
			sum = sum + a2;
		}
	if ((a3 > a2) && (a3 > a0))
		{
			num++;	
			sum = sum + a3;
		}
	if ((a0 > a3) && (a0 > a4))
		{
			num++;	
			sum = sum + a0;
		}
	printf("%d %lld", num, sum);	
	return 0;
}

