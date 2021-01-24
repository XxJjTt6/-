#define _CRT_SECURE_NO_WARNINGS   1
//int main()
//{
//	int a = 12;
//	int arr[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//	int *p = &arr[0][0];
//	while (*p != 12)
//	{
//
//		printf("%d\n", *p);
//		p++;
//	}
//	printf("12");
//	return 0;
//}


#include "三子棋.h"

void menu()
{
	printf("**************************\n");
	printf("******   1. play     *****\n");
	printf("******   0. exit     *****\n");
	printf("**************************\n");
}

void game()
{
	char ret = 0;
	//数据的存储是二位数组
	char board[ROW][COL];
	//初始化棋盘-初始化为空格
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		//电脑下棋
		ComputerMove(board, ROW, COL);//随机下棋的
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
		printf("玩家赢了\n");
	else if (ret == '#')
		printf("电脑赢了\n");
	else if (ret == 'Q')
		printf("平局\n");
	DisplayBoard(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//三子棋的游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}