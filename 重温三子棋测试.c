//#define _CRT_SECURE_NO_WARNINGS 1
//#include"����������.h"
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
//		printf("ƽ��\n");
//	}
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	//menu();
//	//printf("��ѡ��->");
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
//		printf("��ѡ��->");
//		input = 0;
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game(arr);
//			break;
//		case 0:
//			printf("�˳�\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}