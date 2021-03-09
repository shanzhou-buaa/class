#include <stdio.h>
int main()
{
	long long int l[101]={0},r[101]={0}; 
	int n, i;
	scanf("%d", &n);
	long long int a, b, sum = 0, s;
	for (i = 0; i < n; i++)
	{
		scanf("%lld %lld", &a, &b);
		l[i] = a;
		r[i] = b;
	}
	for (i = 0; i < n - 1; i++)
	{
		s = l[i + 1] - r[i];
		if (s > 0)
			sum = sum + r[i + 1] - l[i + 1] + r[i] - l[i]; 
		else
			sum = sum + r[i + 1] - l[i + 1] + r[i] - l[i] + s;
	}
	printf("%lld", sum);
	return 0;
}

