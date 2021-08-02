#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//void test1()
//{
//	SListNode *n1 = (SListNode*)malloc(sizeof(SListNode));
//	n1->x = 1;
//	SListNode *n2 = (SListNode*)malloc(sizeof(SListNode));
//	n2->x = 2;
//	SListNode *n3= (SListNode*)malloc(sizeof(SListNode));
//	n3->x =3;
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = NULL;
//	SListPrint(n1);
//	SListPopBack(&n1);
//	SListPrint(n1);
//	SListPopBack(&n1);
//	SListPrint(n1);
//}

void test2()
{
	struct SListNode* ps = NULL;
	SListPushBack(&ps, 1);
	SListPushBack(&ps, 2);
	SListPushBack(&ps, 3);
	SListPushBack(&ps, 4);
	SListPrint(ps);
	SListPopBack(&ps);
	SListPrint(ps);
	SListPopBack(&ps);
	SListPrint(ps);
	SListPopFront(&ps);
	SListPrint(ps);
	SListPushFront(&ps, 1);
	SListPrint(ps);
	SListNode* pos = SListFind(ps, 2);
	SListInsert(&ps,pos,4);
	SListPrint(ps);
	pos = SListFind(ps, 2);
	SListInsertAfter(pos, 4);
	SListPrint(ps);
	pos = SListFind(ps, 2);
	SListEraseAfter(pos);
	SListPrint(ps);
	pos = SListFind(ps, 4);
	SListErase(&ps,pos);
	SListPrint(ps);
	printf("%d\n", SListSize(ps));
	printf("%d\n", SListEmpty(ps));
}


int main()
{
	/*test1();*/
	test2();
	return 0;
}