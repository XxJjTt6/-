#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("****0 exit       1 paly    ***\n");
	printf("******************************\n");
}

void game()  //game 这个函数并不是三子棋这个游戏各个功能的实现，所以没必要写在game.c（用来写三子棋各个功能实现的函数）里面
{    
	char ret = 0;//用来检查结果谁赢得
	char borad[ROW][COL] = { 0 };//这个数组必须要在外面创建，如果在各个函数里面创建的话，那他出函数就会销毁了，无用
	initborad(borad,ROW,COL); //初始化棋盘
	Displayborad(borad, ROW, COL);//打印棋盘，方便看到下棋的情况
	while (1)
	{
		player(borad, ROW, COL);
		Displayborad(borad, ROW, COL);
		ret = check(borad, ROW, COL);
		if (ret == '*')
		{
			printf("player win\n");
			break;
		}
		if (ret == 'q')   //玩家走完之后也同样要判断一下，因为玩家也有可能是平局
		{
			printf("平局\n");
			break;
		}
		computerplay(borad, ROW, COL);
		Displayborad(borad, ROW, COL);
		ret = check(borad, ROW, COL);
		if (ret == '#')
		{
			printf("computer win\n");
			break;
		}
		if (ret == 'q')
		{
			printf("平局\n");
			break;
		}
		/*ret=check(borad, ROW, COL);*/
	}
}
int main()
{   
	srand((unsigned int)time(NULL));//时间戳的写法
	menu();
	int input = 0;
	do
	{
		printf("请选择->");
		scanf("%d", &input);     //忘了switch case用得时的标点和注意项，因此此处选择用if语句了
		if (1 == input)
		{
			game();
		}
		else if (0 == input)
		{
			break;
		}
		else
		{
			printf("选择错误，请重新选择");
		}
	} while (input);
}