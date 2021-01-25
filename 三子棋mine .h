#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//初始化棋盘
void chushihuaqipan(char arr[ROW][COL], int row, int col);
//打印棋盘
void dayinqipan(char arr[ROW][COL], int row, int col);
//玩家下棋
void play(char arr[ROW][COL], int row, int col);
//电脑下棋
void computer(char arr[ROW][COL], int row, int col);
//检查输赢
char checkwin(char arr[ROW][COL], int row, int col);
