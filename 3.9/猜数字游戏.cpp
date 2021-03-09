#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*void menu()
{
	printf("*******************************\n");
	printf("****1、开始游戏   0、退出游戏      ****\n");
	printf("*******************************\n");
} */
//void game ()
int main
{
	int ret = 0, guess;
	ret = rand () % 100 + 1;
	printf("%d\n",ret);
/*	while (1)
		{
			printf("请猜数字\n");
			scanf("%d", &guess);
			if (guess > ret)
				printf("猜大了\n");
			else if (guess < ret)
				printf("猜小了\n");
			else
			{ 
				printf("恭喜你，猜对了\n");
				break;
			}
		}*/
}
/*int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu ();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
			case 0 : 
				printf("退出游戏\n");
				break;
			case 1 :
				game ();
				break;
			default:
			printf("选择错误\n"); 
			break; 
		}
	}
	while (input); 
	return 0;
}*/
