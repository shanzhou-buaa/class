#include <stdio.h>
int arr[10000001] = {0};
int main()
{
	int n, k = 0, i, j;
	long long int a, max = 0, min = 10e8;
	double sum = 0.0, average;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		{
			scanf("%d", &a);
			arr[i] = a;
		}
	for (i = 0; i < n; i++)
	{
		if(arr[i] < min) 
			min = arr[i];
		if(arr[i] > max) 
			max = arr[i];
	}
	for (i = 0; i < n; i++)
	{
		if ((arr[i] != max) && (arr[i] != min))
			{
				k++;  
				sum = sum + arr[i];
			}
	}
	if (k == 0)
		printf("#DIV/0!");
	else
	{
		average = sum / k;
		printf("%.2f", average);
	}
	return 0;
}

