#define _CRT_SECURE_NO_WARNINGS 1
#include"8-5.h"
//void test1()
//{
//	struct Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	printf("%d\n",StackTop(&st));
//	StackPop(&st);
//	printf("%d\n", StackTop(&st));
//	StackPop(&st);
//	StackPush(&st, 5);
//	printf("%d\n", StackTop(&st));
//	StackPop(&st);
//	while (!StackEmpty(&st))
//	{
//		printf("%d", StackTop(&st));
//		StackPop(&st);
//	}
//	printf("\n");
//	//这一步一定不能忘了，不然会出现内存泄漏
//	StackDestory(&st);
//	
//}


  void test2()
{
	/*这种是用二级指针来解决的，stack8-4的
	那种是用返回值来解决的，下面写一种用一级指针来解决的*/
	struct Stack* phead;    
	StackInit(&phead);
	StackPush(&phead, 0);
	StackPush(&phead, 1);
	StackPush(&phead, 2);
	StackPush(&phead, 3);
	StackPop(&phead);
	StackPush(&phead, 4);
	while (!StackEmpty(&phead))
	{
		printf("%d ", StackTop(&phead));
		StackPop(&phead);
	}
}
    

void test2()
{
	struct Stack phead;
	StackInit(&phead);
	StackPush(&phead, 0);
	StackPush(&phead, 1);
	StackPush(&phead, 2);
	StackPush(&phead, 3);
	//StackPop(&phead);
	StackPush(&phead, 4);
	while (!StackEmpty(&phead))
	{
		printf("%d ", StackTop(&phead));
		StackPop(&phead);
	}
}
int main()
{
	/*test1();*/
	test2();
	return 0;
}