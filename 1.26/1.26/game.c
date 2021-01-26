#include "game.h"

void menu()
{
	printf("************************\n");
	printf("******   1.play   ******\n");
	printf("******   0.exit   ******\n");
	printf("************************\n");

}

void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("------------------------\n");
	int i, j;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col, int count)
{
	while (count)
	{
		int x = rand() % ROW + 1;
		int y = rand() % COL + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
		int x, y;
		int win = 0;
		while (win < row * col - EASY_COUNT)
		{
			printf("请输入坐标\n");
			scanf("%d%d", &x, &y);
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] == '1')
				{
					printf("你踩到雷了，游戏失败\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else
				{
					int i, j, sum = 0;
					for (i = x - 1; i <= x + 1; i++)
					{
						for (j = y - 1; j <= y + 1; j++)
						{
							sum += mine[i][j] - '0';
						}
					}
					show[x][y] = sum + '0';
					DisplayBoard(show, row, col);
					win++;
				}
			}
			else
			{
				printf("坐标非法，请重新输入\n");
			}
		}
		if (win == row * col - EASY_COUNT)
		{
			printf("恭喜你，排雷成功\n");
			DisplayBoard(mine, row, col);
		}
}