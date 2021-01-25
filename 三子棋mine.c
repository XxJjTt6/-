#define _CRT_SECURE_NO_WARNINGS   1
#include"三子棋 .h"
/*int i;
int j;*/
void chushihuaqipan(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
} 

void dayinqipan(char arr[ROW][COL], int row,int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void play(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	/*printf("你想下的坐标");
	scanf("%d%d", &x, &y);*/
	while (1)
	{
		printf("你想下的坐标");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y<= col)
		{
			if (arr[x-1][y-1] == ' ')
			{
				arr[x-1][y-1] = '*';
				break;
			}
			else
				printf("该位置已被占用\n");
		}
		else
		{
			printf("坐标非法，请重新输入");
		}
	}
}

void computer(char arr[ROW][COL], int row, int col)
{
	/*i = rand() % row;
	j = rand() % col;*/
	printf("电脑走:>\n");
	while (1)
	{
		
		int x = rand() % row;
		int y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}
static int isfull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;		     
}

char checkwin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}
	if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[i][0] )&&arr[2][2]!=' ')
	{
		return arr[0][0];
	}
	if (isfull(arr, row, col)== 1)
	{
		return 'Q';
	}
	return 'C';
}
