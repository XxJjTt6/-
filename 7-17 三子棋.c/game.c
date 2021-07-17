#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initborad(char borad[ROW][COL],int row,int col) //因为char borad[][]是数组，所以接收的这个borad的写法不能为char borad [row][col]，因为[]里面要是一个常量才行
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{   
		for (j = 0; j < col; j++)
		{
			borad[i][j] = ' ';
		}
	}
}


//void Displayborad(char borad[ROW][COL], int row, int col)   // 不需要这一步，还没有到向棋盘填充符号的那一步，因为这一步，所有打印出来的棋盘前面会多出9个空格
//{
//	int i, j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			printf("%c", borad[i][j]);
//		}
//	}
//}


void Displayborad(char borad[ROW][COL], int row, int col)
{
	int i, j = 0;


	/*for (i = 0; i < row; i++)
	{   
		if (i == row - 1)
		{
			printf(" %c | %c | %c ");
		}
		for (j = 0; j < col; j++)
		{   
			if (j == col - 1)
			{
				printf(" %c ");
			}
			printf(" %c |");
		}
		printf("\n");
	}*/

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", borad[i][j]);   //这边要注意写的方式，要使其正好满足才可以，不行的话可以多试几种拼法
			if (j <col - 1)
			{
				printf("|");
			}
		}
		printf("\n");              //注意换行号
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
			}
			printf("\n");
		}
	
	}
}

void player(char borad[ROW][COL], int row, int col)
{
	    int x, y = 0;
	    /*printf("请输入坐标");
	    scanf("%d%d", &x, &y);*/
		/*if ((x >= 1 && x <= row) && (y >= 1 && y <= col) && borad[x - 1][y - 1] != '#')
		{
			borad[x - 1][y - 1] = '*';

		}
		else if (borad[x - 1][y - 1] == '#')
		{
			printf("该位置已被占用,请重新选择");
		}
		else
		{
			printf("不在范围内，请重新输入");
		}*/


		//很明显这边要写成一个循环，但是用while循环是最好的，do while 也可以
		do         
		{
			printf("玩家走，请输入坐标\n");          //玩家走尽量写上去，这样下棋的时候看的更加明白，换行号也尽量不要少
			scanf("%d%d", &x, &y);
			if (((x >= 1 && x <= row) && (y >= 1 && y <= col) && borad[x - 1][y - 1] != '#'))
			{
				borad[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("请重新输入\n");
			}
		} while (x<1 || x>row || y<1 || y>col || borad[x - 1][y - 1] == '#');
}



void computerplay(char borad[ROW][COL], int row, int col)
{
	printf("电脑走\n"); 
	int x, y = 0;
	x = rand() % row;
	y = rand() % col;  //巧妙的利用了取余的性质
	while (1)
	{
		if (/*borad[x][y] != '*'||*/  //(写这一句就有bug了，因为他可以继续下在‘#’的位置)
			borad[x][y]==' ')
		{
			borad[x][y] = '#';
			break;
		}
		else
		{
			x = rand() % row;
			y = rand() % col;//巧妙的利用了取余的性质
		}

	}
}

char full(char borad[ROW][COL], int row, int col)
{
	int i, j = 0;
	int flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (borad[i][j] == ' ')
			{
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		return 'c';
	}
	else
	{
		return 'q';
	}
}

char check(char borad[ROW][COL], int row, int col)
{
	//行里面连续3个
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][0] != ' ')
		{
			return borad[i][0];
		}
	}
	//列里面连续3个
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (borad[0][j] == borad[1][j] && borad[1][j] == borad[2][j] && borad[0][j] != ' ')
		{
			return borad[0][j];
		}
	}
	//对角线3个相等
	//for ((borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ') || (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[1][1] != ' '))
	//{
	//	return borad[1][1];
	//}
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (full(borad, row, col) == 'q')
	{
		return 'q';
	}
	return 'c';



    /*下面这种方法会出现问题，因为几种判断方法是在for的大循环里面的，所以判断的时候可以认为是一起判读的，而上面那种方法是一个一个判断的，这种方法在极端情况下会出现问题，他对角线和行同时相等或行列
	同时相等等情况时就会出现问题*/

	//int i = 0;
	//for (i = 0; i < row; i++)      //这种方式更见解，减少重复性，更重要的是这样可以很方式的表示出‘c’的这种情况         
	//{
	//	if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][0] != ' ')
	//	{
	//		return borad[i][0];

	//	}
	//	else if (borad[0][i] == borad[1][i] && borad[1][i] == borad[2][i] && borad[0][i] != ' ')
	//	{
	//		return borad[0][i];

	//	}
	//	else if ((borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ') || (borad[0][2] == borad[1][1] && borad[1][1] == borad[2][0] && borad[1][1] != ' '))
	//	{
	//		return borad[1][1];

	//	}
	//	else if ('q' == full(borad, row, col))
	//	{
	//		return 'q';

	//	}
	//	else
	//	{
	//		return 'c';
	//	}
	//}
}
