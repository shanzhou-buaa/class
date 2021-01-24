#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//打印菜单
void menu()
{
	printf("*************************\n");
	printf("******   1、开始   ******\n");
	printf("******   0、退出   ******\n");
	printf("*************************\n");

}

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印初始棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---", board[i][j]);
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}

//玩家下棋,用'*'表示玩家下的棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("您下棋,请输入坐标\n");
	while (1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("该位置已被占用，请重新输入\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("输入非法，请重新输入\n");
		}
	}
}

//电脑下棋，用'#'表示电脑下的棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	int x, y;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//判断棋盘是否满了（如果全部不是' '，则棋盘还没满）
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//判断胜负
char CheckWinner(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != ' ')
		{
			return board[i][0];//某一行三个棋相同
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];//某一列三个棋相同
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[3][3] && board[1][1] != ' ')
	{
		return board[1][1];//斜向右下三个棋相同
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];//斜向左下三个棋相同
	}
	if (IsFull(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}
