#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("****0 exit       1 paly    ***\n");
	printf("******************************\n");
}

void game()  //game ������������������������Ϸ�������ܵ�ʵ�֣�����û��Ҫд��game.c������д�������������ʵ�ֵĺ���������
{    
	char ret = 0;//���������˭Ӯ��
	char borad[ROW][COL] = { 0 };//����������Ҫ�����洴��������ڸ����������洴���Ļ��������������ͻ������ˣ�����
	initborad(borad,ROW,COL); //��ʼ������
	Displayborad(borad, ROW, COL);//��ӡ���̣����㿴����������
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
		if (ret == 'q')   //�������֮��Ҳͬ��Ҫ�ж�һ�£���Ϊ���Ҳ�п�����ƽ��
		{
			printf("ƽ��\n");
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
			printf("ƽ��\n");
			break;
		}
		/*ret=check(borad, ROW, COL);*/
	}
}
int main()
{   
	srand((unsigned int)time(NULL));//ʱ�����д��
	menu();
	int input = 0;
	do
	{
		printf("��ѡ��->");
		scanf("%d", &input);     //����switch case�õ�ʱ�ı���ע�����˴˴�ѡ����if�����
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
			printf("ѡ�����������ѡ��");
		}
	} while (input);
}