#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);//将棋盘每个元素初始化为' '
	DisplayBoard(board, ROW, COL);//打印初始棋盘
	while (1)
	{
		PlayerMove(board, ROW, COL);
		ret = CheckWinner(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret = CheckWinner(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("你赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
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