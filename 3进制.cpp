#include <stdio.h>
int arr[10000]={0};
int main()
{
	int n, i, a, b, c, x, j;
	while(scanf("%d", &n) != EOF) 
	{    
		if(n == 0)
			printf("0\n");
		else
		{   
	    for(i = 0; n != 0; i++)
	    {
	    	a = n / 3;		//取商 
	    	b = n % 3;		//取余 
	    	arr[i] = b;		//arr数组为数n除以3后余数的集合 
	    	n = a;
		}  
		if(i < 4)
		{
			for(j = i; j >= 1; j--)		//倒序打印arr数组得到三进制数 
				{
					printf("%d", arr[j-1]);
				}
				printf("\n");
		}
		else
			{
				printf("LONG");
				for(j = i; j >= 1; j--)
					printf("%d", arr[j-1]);
				printf("\n");
			}
		}
	}
	return 0;
}

