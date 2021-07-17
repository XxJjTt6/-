#include<stdio.h>
#include<time.h>
#include<stdlib.h>  //像这儿可以在头文件中将一些后面game.c和test.c要包涵的头文件写在这，这样在game.c和test.c中只要包涵game.h就行了，因为game.h已将将game.c和test.c要包涵的头文件包涵进去了


#define ROW 3   //define 后面不需要加分号
#define COL 3   //这样做的目的是方便以后改变棋盘的大小
void initborad(char borad[ROW][COL], int row, int col); //因为char borad[][]是数组，所以申明的这个borad的写法不能为char borad [row][col]，因为[]里面要是一个常量才行
void Displayborad(char borad[ROW][COL], int row, int col);
void player(char borad[ROW][COL], int row, int col);
void computerplay(char borad[ROW][COL], int row, int col);
char check(char borad[ROW][COL], int row, int col);
char full(char borad[ROW][COL], int row, int col);