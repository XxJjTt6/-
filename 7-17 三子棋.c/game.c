#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void initborad(char borad[ROW][COL],int row,int col) //��Ϊchar borad[][]�����飬���Խ��յ����borad��д������Ϊchar borad [row][col]����Ϊ[]����Ҫ��һ����������
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


//void Displayborad(char borad[ROW][COL], int row, int col)   // ����Ҫ��һ������û�е������������ŵ���һ������Ϊ��һ�������д�ӡ����������ǰ�����9���ո�
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
			printf(" %c ", borad[i][j]);   //���Ҫע��д�ķ�ʽ��Ҫʹ����������ſ��ԣ����еĻ����Զ��Լ���ƴ��
			if (j <col - 1)
			{
				printf("|");
			}
		}
		printf("\n");              //ע�⻻�к�
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
	    /*printf("����������");
	    scanf("%d%d", &x, &y);*/
		/*if ((x >= 1 && x <= row) && (y >= 1 && y <= col) && borad[x - 1][y - 1] != '#')
		{
			borad[x - 1][y - 1] = '*';

		}
		else if (borad[x - 1][y - 1] == '#')
		{
			printf("��λ���ѱ�ռ��,������ѡ��");
		}
		else
		{
			printf("���ڷ�Χ�ڣ�����������");
		}*/


		//���������Ҫд��һ��ѭ����������whileѭ������õģ�do while Ҳ����
		do         
		{
			printf("����ߣ�����������\n");          //����߾���д��ȥ�����������ʱ�򿴵ĸ������ף����к�Ҳ������Ҫ��
			scanf("%d%d", &x, &y);
			if (((x >= 1 && x <= row) && (y >= 1 && y <= col) && borad[x - 1][y - 1] != '#'))
			{
				borad[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("����������\n");
			}
		} while (x<1 || x>row || y<1 || y>col || borad[x - 1][y - 1] == '#');
}



void computerplay(char borad[ROW][COL], int row, int col)
{
	printf("������\n"); 
	int x, y = 0;
	x = rand() % row;
	y = rand() % col;  //�����������ȡ�������
	while (1)
	{
		if (/*borad[x][y] != '*'||*/  //(д��һ�����bug�ˣ���Ϊ�����Լ������ڡ�#����λ��)
			borad[x][y]==' ')
		{
			borad[x][y] = '#';
			break;
		}
		else
		{
			x = rand() % row;
			y = rand() % col;//�����������ȡ�������
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
	//����������3��
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (borad[i][0] == borad[i][1] && borad[i][1] == borad[i][2] && borad[i][0] != ' ')
		{
			return borad[i][0];
		}
	}
	//����������3��
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (borad[0][j] == borad[1][j] && borad[1][j] == borad[2][j] && borad[0][j] != ' ')
		{
			return borad[0][j];
		}
	}
	//�Խ���3�����
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



    /*�������ַ�����������⣬��Ϊ�����жϷ�������for�Ĵ�ѭ������ģ������жϵ�ʱ�������Ϊ��һ���ж��ģ����������ַ�����һ��һ���жϵģ����ַ����ڼ�������»�������⣬���Խ��ߺ���ͬʱ��Ȼ�����
	ͬʱ��ȵ����ʱ�ͻ��������*/

	//int i = 0;
	//for (i = 0; i < row; i++)      //���ַ�ʽ�����⣬�����ظ��ԣ�����Ҫ�����������Ժܷ�ʽ�ı�ʾ����c�����������         
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
