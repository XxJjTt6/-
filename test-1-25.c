#define _CRT_SECURE_NO_WARNINGS   1
#include"������ .h"
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
		printf("���Ӯ��\n");
	else if (ret == '#')
		printf("����Ӯ��\n");
	else if (ret == 'Q')
		printf("ƽ����\n");
	dayinqipan(arr, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
    int input = 0;
	do
	{
	   menu();
	   printf("��ѡ��:>");
	   scanf("%d", &input);
	   switch (input)
	   {
	   case 1:
		   game();
		   break;
	   case 0:
		   printf("�˳���Ϸ");
		   break;
	   default:
		   printf("ѡ�����");
		   break;
	   }
   } while (input);
	return 0;	
}