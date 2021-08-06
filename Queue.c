#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//这样写有个小问题，因为你一开始在初始化里面已经创建了一个节点，如果
//按我这种方法尾插的话，最后会对出一个节点来
//void QueueInit(struct Queue* st)
//{
//	assert(st);
//	st->phead = st->tail = (struct Node*)malloc(sizeof(struct Node));
//	st->tail->next = NULL;
//}
//
//
//void QueuePush(struct Queue* st, QDataType x)        
//{
//	assert(st);
//	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//	st->tail->data = x;
//	st->tail->next = newnode;
//	newnode->next = NULL;
//	st->tail = newnode;
//}
	
//换种写法，上面那种写法主要是因为你一开始初始化了导致的
void QueueInit(struct Queue* st)
{
	assert(st);
	st->phead = st->tail = NULL;
}

void QueuePush(struct Queue* st, QDataType x)
{
	assert(st);
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = x;
	newnode->next = NULL;
	if (st->phead == NULL)
	{
		st->phead = st->tail = newnode;
	}
	else
	{
		st->tail->next = newnode;
		st->tail = newnode;
	}
}

void QueuePop(struct Queue* st)
{
	assert(st);
	assert(!QueueEmpty(st));
	//不可以将只有一个节点和多个节点的情况放在一起说
	//因为一个节点释放时会造成tail的野指针

	/*struct Node* nhead = st->phead->next;
	free(st->phead);
	st->phead = nhead;*/
	if (st->phead->next == NULL)
	{
		free(st->phead);
		//此时如果不把tail置成空，就会造成野指针
		st->phead = st->tail = NULL;
	}
	else
	{
		struct Node* nhead = st->phead->next;
		free(st->phead);
		st->phead = nhead;
	}
}

QDataType QueueTop(struct Queue* st)
{
	assert(st);
	assert(!QueueEmpty(st));
	return st->phead->data;
}

void QueuePop(struct Queue* st)
{
	assert(st);
	assert(!QueueEmpty(st));
	struct Node* nhead = st->phead->next;
	free(st->phead);
	st->phead = nhead;
}

bool QueueEmpty(struct Queue* st)
{
	assert(st);
	return st->phead == NULL;
}

int QueueSize(struct Queue* st)
{
	assert(st);
	int n = 0;
	struct Node* cur = st->phead;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

void QueueDestory(struct Queue* st)
{
	assert(st);
	struct Node* cur = st->phead;
	struct Node* next;
	while (cur)
	{
		next= cur->next;
		free(cur);
		cur = next; 
	}
	st->phead = st->tail = NULL;
}