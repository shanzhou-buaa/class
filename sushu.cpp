#include <stdio.h>
#include <math.h> //��Ҫ������ѧ�⺯����������math.hͷ�ļ� 
int main()
{
	int x, i;
	scanf("%d", &x);
	for(i = 2; i <= sqrt(x); i++)//������2��x-1���� 
	//sqrt(x)�ǿ�ƽ������ѧ�⺯�� 
	if(x % i == 0) 
	{
		break;
	}
	if (i >= x)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
