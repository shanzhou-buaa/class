#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS (ROW+2)
#define COLS (COL+2)

#define EASY_COUNT 80

//¥Ú”°≤Àµ•
void menu();
//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROWS][COLS], int row, int col, char set);
//¥Ú”°∆Â≈Ã
void DisplayBoard(char board[ROWS][COLS], int row, int col);
//¬Ò¿◊
void SetMine(char board[ROWS][COLS], int row, int col, int count);
//…®¿◊
void FindMine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col);