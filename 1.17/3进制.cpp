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
	    	a = n / 3;		//ȡ�� 
	    	b = n % 3;		//ȡ�� 
	    	arr[i] = b;		//arr����Ϊ��n����3�������ļ��� 
	    	n = a;
		}  
		if(i < 4)
		{
			for(j = i; j >= 1; j--)		//�����ӡarr����õ��������� 
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

