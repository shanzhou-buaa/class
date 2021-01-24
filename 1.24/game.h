#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//��ӡ�˵�
void menu();
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ��ʼ����
void DisplayBoard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж�ʤ��
char CheckWinner(char board[ROW][COL], int row, int col);
//�ж������Ƿ����ˣ���ȫ������' '��
int IsFull(char board[ROW][COL], int row, int col);