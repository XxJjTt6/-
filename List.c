#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//初始化
void ListInit(struct ListNode** pphead)
{
	/*(*pphead)->data = 1;              //第一个节点的空间还没有创建了，所以不能这么写
	(*pphead)->pre = NULL;
	(*pphead)->next = NULL;
	(*pphead)->next = *pphead;
	(*pphead)->pre = *pphead;*/
	*pphead = BuyNode(-1);
	(*pphead)->next = *pphead;
	(*pphead)->pre = *pphead;
}

//打印
void ListPrint(struct ListNode* phead)
{
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//创建一个节点
struct ListNode* BuyNode(ListDataType x)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}

//尾插
void ListPushBack(struct ListNode* phead,ListDataType x)
{
	assert(phead);   //写这一步主要是怕忘了外面的ListInit这个初始化没写，那样会导致phead为空，双向带头循环链表里面必须要有头节点，
	                 //不然任何功能都谈不起来，所以这边必须要断言一下
	struct ListNode* tail = phead->pre;
	struct ListNode* newnode=BuyNode(x);
	tail->next = newnode;
	newnode->pre = tail;
	newnode->next = phead;
	phead->pre = newnode;
}


//尾删
void ListPopBack(struct ListNode* phead)
{
	assert(phead->next!=phead);    //不这样写断言的话，它会把第一个的头节点也给他删除了
	struct ListNode* tail = phead->pre;
	struct ListNode* tailpre = tail->pre;
	free(tail);
	tailpre->next = phead;
	phead->pre = tailpre;
}

//头插
void ListPushFront(struct ListNode* phead,ListDataType x)
{
	assert(phead);
	struct ListNode* newnode = BuyNode(x);
	newnode->next = phead->next;
	phead->next->pre = newnode;
	phead->next = newnode;
	newnode->pre = phead;
	//newnode->next=phead->next   头插的话这个必须要写在前面，写在后面的话，phead->next已经被你前面改变过了，而不是原来的值了
}

//头删
void ListPopFront(struct ListNode* phead)
{
	assert(phead->next != phead);    // //不这样写断言的话，它会把第一个的头节点也给他删除了
	struct ListNode* headnext = phead->next->next;
	free(phead->next);
	phead->next = headnext;
	headnext->pre = phead;
}

//找某一个节点的位置
struct ListNode* ListFind(struct ListNode* phead, ListDataType x)
{
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
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

//在任意位置之前插入
void ListInsert(struct ListNode* phead, struct ListNode* pos, ListDataType x)
{
	assert(phead->next != phead);          //防止这个链表为空时还插入，已经此时已经没有节点给你寻找了
	struct ListNode* newnode = BuyNode(x);
	newnode->pre = pos->pre;   //要注意这儿的顺序
	pos->pre->next = newnode;
	newnode->next = pos;
	pos->pre = newnode;
	//newnode->pre = pos->pre->pre;    写错了，这是前面的前面一个节点了，不需要，只需要pos前面一个节点就行了
	//pos->pre->pre->next = newnode;
}


//删除任意位置
void ListErase(struct ListNode* phead, struct ListNode* pos)
{
	assert(phead->next != phead);
	struct ListNode* next = pos->next;
	struct ListNode* pre = pos->pre;
	free(pos);
	pre->next = next;
	next->pre = pre;
}

//判断链表是否为空
bool ListEmpty(struct ListNode* phead)
{
	return phead->next == phead ? true : false;
}

//链表有几个节点
int ListSize(struct ListNode* phead)
{
	struct ListNode* cur = phead->next;
	int n = 0;
	while (cur != phead)
	{
		++n;  //这种情况就让它立即生效，直接前置加加
		cur = cur->next;
	}
	return n;
}

