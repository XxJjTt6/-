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
enum  chose              // 这里用个枚举，好处一，可以一下定义好几个变量；好处二，下面case里让读者一看就明了了，是个什么意思。
{
	exit,
	Add,
    Delect,
	Search,
	Modify,
	Show,
};
//struct people   // 不能定义在这个里面，因为如果出了这个是会销毁的
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
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			Addcontact(&con);     //结构体传参是最好地址传递，因为不需要想值传递一样，创建一个临时的拷贝，而且地址的话，函数里面修改了，外面也会修改。
			break;                //记住每个后面要写个break，不然会一直执行到最后一个break的时候才停下来
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
			printf("选择错误，请重新选择");
		}
	} while (input);
	return 0;
}