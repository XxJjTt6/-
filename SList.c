#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//打印单聊表
void SListPrint(SListNode *ps)
{
	while (ps)
	{
		printf("%d->", ps->x);
		ps = ps->next;
	}
	printf("NULL\n");
}

//创建一个新的节点
SListNode*  SListBuyNode(SLDataType x)
{
	struct SListNode* n1 = (SListNode*)malloc(sizeof(SListNode));
	if (n1 == NULL)
	{
		printf("creat fail\n");
		exit(-1);
	}
	n1->x = x;
	n1->next = NULL;
	return n1;
}

//单链表尾删
void SListPopBack(SListNode** ps)
{
	assert(ps);
	assert(*ps);
	SListNode* tail = *ps;
	SListNode* prev =*ps;
	//单链表一个节点的情况
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	//单链表中有节点的情况
	else
	{
		while (tail->next)     //注意这儿和打印的地方不一样，这儿要这么写，具体情况要具体分析，自己举几个列子就知道了
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		/*tail = NULL;*/
		prev->next = NULL;
	}
}

//单链表尾插
void SListPushBack(SListNode** ps, SLDataType x)
{
	assert(ps);
	SListNode* tail = *ps;
	//没有节点的情况
	if (*ps == NULL)
	{
		*ps = SListBuyNode(x);
	}
	//有节点的情况
	else
	{
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = SListBuyNode(x);
	}
}


//头删
void SListPopFront(SListNode** ps)
{
	assert(ps);
	assert(*ps);
	//一个节点的情况
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	//多个节点的情况
	else
	{
		SListNode* next = (*ps)->next;
		free(*ps);
		*ps = next;
	}
}

void SListPushFront(SListNode** ps, SLDataType x)
{
	assert(ps);
	//空节点的情况
	if (*ps == NULL)
	{
		*ps = SListBuyNode(x);
	}
	//有节点的情况
	else
	{
		SListNode* temp = *ps;
		*ps = SListBuyNode(x);
		(*ps)->next = temp;
	}


	 //这样写也可以，因为if里面的情况包括在了else的情况里面，这样写可以减少代码的重复，但上面一种写法看起来更加的简洁明了
	//SListNode* temp = *ps;
	//*ps = SListBuyNode(x);
	//(*ps)->next = temp;
}

SListNode* SListFind(SListNode* phead, SLDataType x)
{
	SListNode* cur = phead;
	while (cur)                  //这儿一定要写cur，不能写cur->next，不然最后一个节点是进不去的
	{
		if (cur->x == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}


//在某个节点之前插入
void SListInsert(SListNode** ps, SListNode* pos, SLDataType x)
{
	assert(ps);
	SListNode* tail = *ps;
	SListNode* prev = *ps;
	//空节点的情况
	if (*ps == NULL)           //注意这儿千万不能写成tail，然后对tail进行操作
	{
		*ps = SListBuyNode(x);
	}
	//一个节点的情况
	else if ((tail)->next == NULL)
	{
		struct SListNode* newnode = SListBuyNode(x);
		*ps = newnode;
		newnode->next = tail;
	}
	//多个节点的情况
	else
	{
		while ((tail) != pos)
		{
			prev = tail;
			tail = tail->next;
		}
		/*prev->next = SListBuyNode(x);
		prev->next->next = tail;      */   //因为前面的SListBuyNode是你自己创建的一块空间，这块空间不与原链表完整的连接在一起，所以这句代码会出问题

		struct SListNode* newnode = SListBuyNode(x);
		newnode->next = tail;
		prev->next = newnode;
	}
}



//void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x)
//{
//	assert(pphead);
//	assert(pos);
//
//	// 1、头插
//	// 2、后面插入
//	if (*pphead == pos)
//	{
//		SListPushFront(pphead, x);
//	}
//	else
//	{
//		// 找到pos位置的前一个节点
//		SListNode* prev = *pphead;
//		while (prev->next != pos)
//		{
//			prev = prev->next;
//		}
//
//		SListNode* newnode = SListBuyNode(x);
//		newnode->next = pos;
//		prev->next = newnode;
//	}
//}


//在某个节点之后插入
void SListInsertAfter( SListNode* pos, SLDataType x)
{
	SListNode* newnode = SListBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//在某个位置之后删除
void SListEraseAfter(SListNode* pos)
{
	SListNode*  nextnext = pos->next->next;
	free(pos->next);
	pos->next = nextnext;
}

//删除pos这个位置
void SListErase(SListNode** ps, SListNode* pos)
{
	assert(ps);
	assert(*ps);
	//一个节点的情况 ,因为这个时候头结点变化了，所以要用2级指针传参，而且不能像前面一样，把*ps赋值给tail然后对tail进行操作了，因为那样tail是影响不到外面的
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	//多个节点的情况
	else
	{
		SListNode* cur = *ps;              //这儿也是，不可以对*ps直接用，要保护好*ps的位置，因为你不需要对头进行改变，如果用*ps的话，那么外面也会接着变的
		SListNode *prev = *ps;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		SListNode *next = cur->next;
		free(cur);
		prev->next = next;
	}
}


//计算有多少个节点
int SListSize(SListNode* ps)
{
	int num = 0;
	while (ps != NULL)
	{
		num++;
		ps = ps->next;
	}
	return num;
}

//判断是否为空
bool SListEmpty(SListNode* ps)
{
	return ps == NULL;
}


