#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define rand_max 2147483647
int main()
{
	int a, b, i;
	srand((unsigned int)time(NULL));
	for(i = 0; i < 100; i++)
	{
		if(rand()>32767)
			printf("%d\n", rand());
	}
	return 0;
}
