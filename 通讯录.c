#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"contact.h"
void menu()
{
	printf("*********************************\n");
	printf("*****1.Add      2.Delect*********\n");
	printf("*****3.Search   4.Modify*********\n");
	printf("*****5.Show     0.exit  *********\n");
	printf("*********************************\n");
}
enum  chose              // �����ø�ö�٣��ô�һ������һ�¶���ü����������ô���������case���ö���һ���������ˣ��Ǹ�ʲô��˼��
{
	exit,
	Add,
    Delect,
	Search,
	Modify,
	Show,
};
//struct people   // ���ܶ�����������棬��Ϊ�����������ǻ����ٵ�
//{
//	char name[20];
//	int age;
//	int tele[14];
//	char address[15];
//};
//struct contact
//{
//	struct people data[max];
//	int sz;
//};
int main()
{
	int input = 0;
	struct contact con;
	init(&con);
	do
	{   
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			Addcontact(&con);     //�ṹ�崫������õ�ַ���ݣ���Ϊ����Ҫ��ֵ����һ��������һ����ʱ�Ŀ��������ҵ�ַ�Ļ������������޸��ˣ�����Ҳ���޸ġ�
			break;                //��סÿ������Ҫд��break����Ȼ��һֱִ�е����һ��break��ʱ���ͣ����
		case Delect:
			Delectcontact(&con);
			break;
		case Search:
			Searchcontact(&con);
			break;
		case Modify:
			Modifycontact(&con);
			break;
		case Show:
			Showcontact(&con);
			break;
		case exit:
			break;
		default:
			printf("ѡ�����������ѡ��");
		}
	} while (input);
	return 0;
}