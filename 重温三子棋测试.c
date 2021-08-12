//#define _CRT_SECURE_NO_WARNINGS 1
//#include"重温三子棋.h"
//void menu()
//{
//	printf("*************************\n");
//	printf("*****1.play   0.exit*****\n");
//	printf("*************************\n");
//}
//
//void game(char arr[ROW][COL])
//{
//	while (1)
//	{
//		player(arr, ROW, COL);
//		boardplay(arr, ROW, COL);
//		//check(arr, ROW, COL);
//		if (check(arr,ROW,COL)!='c')
//		{
//			break;
//		}
//		computer(arr, ROW, COL);
//		boardplay(arr, ROW, COL);
//		/*check(arr, ROW, COL);*/
//		if (check(arr, ROW, COL) != 'c')
//		{
//			break;
//		}
//	}
//	if (check(arr, ROW, COL) == '*')
//	{
//		printf("play win\n");
//	}
//	else if (check(arr, ROW, COL) == '#')
//	{
//		printf("computer win\n");
//	}
//	else
//	{
//		printf("平局\n");
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	//menu();
//	//printf("请选择->");
//	//int input = 0;
//	//scanf("%d", &input);
//	char arr[ROW][COL];
//	//boardinit(arr, ROW, COL);
//	//boardplay(arr, ROW, COL);
//	int input = 0;
//	do
//	{
//		menu();
//		boardinit(arr, ROW, COL);
//		boardplay(arr, ROW, COL);
//		printf("请选择->");
//		input = 0;
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game(arr);
//			break;
//		case 0:
//			printf("退出\n");
//			break;
//		default:
//			printf("选择错误请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}