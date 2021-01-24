#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

//打印菜单
void menu();
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印初始棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//判断胜负
char CheckWinner(char board[ROW][COL], int row, int col);
//判断棋盘是否满了（即全部不是' '）
int IsFull(char board[ROW][COL], int row, int col);