#include <stdio.h>
#include <math.h> //想要引用数学库函数，需引入math.h头文件 
int main()
{
	int x, i;
	scanf("%d", &x);
	for(i = 2; i <= sqrt(x); i++)//产生从2到x-1的数 
	//sqrt(x)是开平方的数学库函数 
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
