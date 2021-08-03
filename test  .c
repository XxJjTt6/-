#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void Listtest1()
{
	struct ListNode* phead = NULL;
	ListInit(&phead);
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	ListPopBack(phead);
	ListPrint(phead);
	/*ListPopBack(phead);         //为了测试ListPopBack里面的断言写的
	ListPrint(phead);*/
	ListPushFront(phead, 1);
	ListPrint(phead);
	ListPushFront(phead, 2);
	ListPrint(phead);
	ListPushFront(phead, 3);
	ListPrint(phead);
	/*ListPushFront(phead, 4);*/
	struct ListNode* pos = ListFind(phead, 3);   //ListInsert的复用，他也可以用来实现头插
	ListInsert(phead, pos, 4);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	ListPopFront(phead);
	ListPrint(phead);
	//ListPopFront(phead);
	//ListPrint(phead);
	/*ListPopFront(phead);
	ListPrint(phead);*/
	//ListPopFront(phead);
	//ListPrint(phead);
	 /*struct ListNode* */pos = ListFind(phead, 1);
	 ListInsert(phead, pos, 2);
	 ListPrint(phead);
	 ListErase(phead, pos);
	 ListPrint(phead);
	 printf("%d\n", ListSize(phead));
}



int main()
{
	Listtest1();
	return 0;
}