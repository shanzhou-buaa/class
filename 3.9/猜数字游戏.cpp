#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*void menu()
{
	printf("*******************************\n");
	printf("****1����ʼ��Ϸ   0���˳���Ϸ      ****\n");
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
			printf("�������\n");
			scanf("%d", &guess);
			if (guess > ret)
				printf("�´���\n");
			else if (guess < ret)
				printf("��С��\n");
			else
			{ 
				printf("��ϲ�㣬�¶���\n");
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
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
			case 0 : 
				printf("�˳���Ϸ\n");
				break;
			case 1 :
				game ();
				break;
			default:
			printf("ѡ�����\n"); 
			break; 
		}
	}
	while (input); 
	return 0;
}*/
