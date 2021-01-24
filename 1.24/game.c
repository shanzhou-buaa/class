#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��ӡ�˵�
void menu()
{
	printf("*************************\n");
	printf("******   1����ʼ   ******\n");
	printf("******   0���˳�   ******\n");
	printf("*************************\n");

}

//��ʼ������
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
//��ӡ��ʼ����
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

//�������,��'*'��ʾ����µ���
void PlayerMove(char board[ROW][COL], int row, int col)
{
	printf("������,����������\n");
	while (1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("��λ���ѱ�ռ�ã�����������\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

//�������壬��'#'��ʾ�����µ���
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("��������\n");
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

//�ж������Ƿ����ˣ����ȫ������' '�������̻�û����
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

//�ж�ʤ��
char CheckWinner(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][0] != ' ')
		{
			return board[i][0];//ĳһ����������ͬ
		}
	}
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];//ĳһ����������ͬ
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[3][3] && board[1][1] != ' ')
	{
		return board[1][1];//б��������������ͬ
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];//б��������������ͬ
	}
	if (IsFull(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	return 'C';
}
