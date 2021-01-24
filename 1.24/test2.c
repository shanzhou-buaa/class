#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);//������ÿ��Ԫ�س�ʼ��Ϊ' '
	DisplayBoard(board, ROW, COL);//��ӡ��ʼ����
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
		printf("��Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ��\n");
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
				printf("�����������������\n");
				break;
			}
		}
	} while (input);
    return 0;
}