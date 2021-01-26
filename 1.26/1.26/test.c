#include "game.h"

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	//打印
	//DisplayBoard(mine, ROW, COL);

	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL, EASY_COUNT);
	DisplayBoard(mine, ROW, COL);

	FindMine(show, mine, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				game();
			}
			case 0:
			{
				break;
			}
			default:
			{
				printf("输入错误，请重新输入\n");
				break;
			}
		}
	} while (input);
	return 0;
}