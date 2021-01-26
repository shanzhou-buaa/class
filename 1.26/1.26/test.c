#include "game.h"

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	//��ӡ
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