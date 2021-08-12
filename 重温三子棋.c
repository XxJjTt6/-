//#define _CRT_SECURE_NO_WARNINGS 1
//#include"重温三子棋.h"
//void boardinit(char arr[ROW][COL], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			arr[i][j] = ' ';
//		}
//	}
//}
////void boardinit2(char arr[ROW][COL],int row,int col)
////{
////	int i = 0;
////	for (i = 0; i < row; i++)
////	{
////		
////		int j = 0;
////		for (j = 0; j < col; j++)
////		{
////			if (j != col - 1)
////			{
////				printf("  |");
////			}
////			else
////			{
////				printf(" ");
////			}
////		}
////		printf("\n");
////		if (i != row - 1)
////		{
////			for (j = 0; j < col; j++)
////			{
////				printf("---");
////			}
////		}
////		printf("\n");
////	}
////}
//
//void boardplay(char arr[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//
//		int j = 0;
//		for (j = 0; j < col; j++)
//		{
//			if (j != col - 1)
//			{
//				printf("%c |",arr[i][j]);
//			}
//			else
//			{
//				printf("%c",arr[i][j]);
//			}
//		}
//		printf("\n");
//		if (i != row - 1)
//		{
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//			}
//		}
//		printf("\n");
//	}
//}
//
//void player(char arr[ROW][COL], int row, int col)
//{
//	printf("请输入你要下的坐标->");
//	int x = 0;
//	int y = 0; 
//	scanf("%d %d", &x, &y);
//	while (1)
//	{
//		if (x >= 1 && x <= row&&y >= 1 && y <= col)
//		{
//			arr[x - 1][y - 1] = '*';
//			break;
//		}
//		else
//		{
//			printf("坐标非法重新输入\n");
//		}
//	}
//}
//
//void computer(char arr[ROW][COL], int row, int col)
//{
//	printf("电脑下\n");
//	int x = rand() % row ;
//	int y = rand() % row ;
//	while (1)
//	{
//		if (/*arr[x][y] != '*'&&arr[x][y]!='#'||*/arr[x][y]==' ')
//		{
//			arr[x][y] = '#';
//			break;
//		}
//		else
//		{
//			x = rand() % row ;
//			y = rand() % row ;
//		}
//	}
//}
//char checkfull(char arr[ROW][COL], int row, int col)
//{
//	int flag = 0;
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			if (arr[i][j] == ' ')
//			{
//				flag = 1;
//			}
//		}
//	}
//	if (flag == 0)
//	{
//		return 'Q';
//	}
//	else
//	{
//		return 'c';
//	}
//}
//
//char check(char arr[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
//		{
//			return arr[i][0];
//		}
//	}
//	for (i = 0; i < col; i++)
//	{
//		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
//		{
//			return arr[0][i];
//		}
//	}
//	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ' || arr[1][1] == arr[0][2] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
//	{
//		return arr[1][1];
//	}
//	/*checkfull(arr, row, col);*/
//	return checkfull(arr, row, col);
//}
