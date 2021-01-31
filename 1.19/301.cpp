#include <stdio.h>
int main()
{
	freopen("301.txt", "w", stdout);
	int n, i, a, b, c;
	long long int d, e;
	double f, g;
	scanf("%d", &n);
	for(i = 0; i < n; i = i + 1)
	{
		scanf("%d", &a);
		if(i == n - 1)
		{
			if(a == 1)
			{
				scanf("%d%d", &b, &c);
				printf("%d", b + c);
			}
			else if(a == 2)
			{
				scanf("%lld%lld", &d, &e);
				printf("%lld", d + e);
			}
			else if(a == 3)
			{
				scanf("%lf%lf", &f, &g);
				printf("%.4lf", f + g);
			}
		}
		else
		{
			if(a == 1)
			{
				scanf("%d%d", &b, &c);
				printf("%d\n", b + c);
			}
			else if(a == 2)
			{
				scanf("%lld%lld", &d, &e);
				printf("%lld\n", d + e);
			}
			else if(a == 3)
			{
				scanf("%lf%lf", &f, &g);
				printf("%.4lf\n", f + g);
			}
		}
	}
	fclose(stdout);
	return 0;
}

