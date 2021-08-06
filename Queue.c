#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//����д�и�С���⣬��Ϊ��һ��ʼ�ڳ�ʼ�������Ѿ�������һ���ڵ㣬���
//�������ַ���β��Ļ�������Գ�һ���ڵ���
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
	
//����д������������д����Ҫ����Ϊ��һ��ʼ��ʼ���˵��µ�
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
	//�����Խ�ֻ��һ���ڵ�Ͷ���ڵ���������һ��˵
	//��Ϊһ���ڵ��ͷ�ʱ�����tail��Ұָ��

	/*struct Node* nhead = st->phead->next;
	free(st->phead);
	st->phead = nhead;*/
	if (st->phead->next == NULL)
	{
		free(st->phead);
		//��ʱ�������tail�óɿգ��ͻ����Ұָ��
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