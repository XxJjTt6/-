#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
void menu()
{
	printf("\n**************************************\n");
	printf("****1.尾部插入          2.头部插入****\n");
	printf("****3.尾部删除          4.头部删除****\n");
	printf("****5.指定位置插入  6.指定位置删除****\n");
	printf("****7.打印              0.退出    ****\n");
}

void SeqListTest1(SLT *ps1)            //像这种函数很多的项目，最好先不要急着写菜单，因为如果先写菜单的话，首先你不知道怎么写，该有什么东西，很散乱，而且最重要的是那种的话很不
                                       //方便调试，因此写这种项目时，最好先写好测试的部分，写一部分就调试一部分，这样还容易发现自己哪儿错了，之前写三子棋的时候就犯了这个错误，
									   //所以当时写菜单的时候就一顿顿的，而且就光写个菜单细节上都出现了错误.
{
	SeqListinit(ps1);
	SeqListPushBack(ps1,1);
	SeqListPushBack(ps1,2);
	SeqListPushBack(ps1, 3);
	SeqListPushBack(ps1, 4);
	SeqListPushBack(ps1, 5);
	SeqListPushFront(ps1, 0);
	SeqListPushFront(ps1, -1);
	SeqListPopBack(ps1);
	SeqListPopFront(ps1);
	SeqListInsert(ps1, 0, -1);    // 当pos=0，相当于头插，当pos=size-1时，相当于尾插，因此可以复用
	SeqListErase(ps1,5);          //当pos=0，相当于头删，当pos=size-1时，相当于尾删，因此可以复用
	SeqListPrintf(ps1);
	SeqListDestory(ps1);
}

int main()
{
	SLT ps1;
	/*SeqListTest1(&ps1);  */     //当测试完所有函数后，要写菜单时，这时就不需要这部分测试的内容了，因为你已经测试并验证了所有需要用得函数了，不注释掉，不方便下面菜单里的选择
	SeqListinit(&ps1);
	int input = 0;
	/*int a = 0;*/
	int pos = 0;
	do
	{
		int a = 0;
		menu();
		printf("请选择->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			/*int a = 0;*/
			printf("请输入要插入的数\n");
			scanf("%d", &a);
			SeqListPushBack(&ps1,a);
			break;
		case 2:
			printf("请输入要插入的数\n");
			scanf("%d", &a);
			SeqListPushFront(&ps1,a);
			break;
		case 3:
			SeqListPopBack(&ps1);
			break;
		case 4:
			SeqListPopFront(&ps1);
			break;
		case 5:
			printf("请输入要插入的位置,以及要插入的数据\n");
			scanf("%d %d", &pos, &a);
			SeqListInsert(&ps1, pos, a);
			break;
		case 6:
			printf("请输入要删除的位置\n");
			scanf("%d", &pos);
			SeqListErase(&ps1, pos);
			break;
		case 7:
			SeqListPrintf(&ps1);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}