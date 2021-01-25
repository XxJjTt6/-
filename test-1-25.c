#define _CRT_SECURE_NO_WARNINGS   1
#include"三子棋 .h"
void menu()
{
	printf("*****************\n");
	printf("**1.play 0.quit**\n");
	printf("*****************\n");
}

void game()
{
	char ret = 0;
	char arr[ROW][COL];
	chushihuaqipan(arr, ROW, COL);
	dayinqipan(arr, ROW, COL);
	while (1)
	{
		/*chushihuaqipan(arr, ROW, COL);
		dayinqipan(arr, ROW, COL);*/
		play(arr, ROW, COL);
		ret = checkwin(arr, ROW, COL);
		if (ret != 'C')
		{
			break; 
		}
		dayinqipan(arr, ROW, COL);
		computer(arr, ROW, COL);
		ret = checkwin(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		dayinqipan(arr, ROW, COL);
	}
	if (ret == '*')
		printf("玩家赢了\n");
	else if (ret == '#')
		printf("电脑赢了\n");
	else if (ret == 'Q')
		printf("平局了\n");
	dayinqipan(arr, ROW, COL);
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
		   game();
		   break;
	   case 0:
		   printf("退出游戏");
		   break;
	   default:
		   printf("选择错误");
		   break;
	   }
   } while (input);
	return 0;	
}