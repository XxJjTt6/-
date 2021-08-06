#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct Node
{
	QDataType data;
	struct Node* next;
}Node;
typedef struct Queue
{
	Node* phead;
	Node* tail;
}Queue;

void QueueInit(struct Queue* st);
//因为队的性质，这儿只能在尾上插入，故没必要写明是
//尾插，因为只能在尾上插入
void QueuePush(struct Queue* st,QDataType x);
//因为一定是在头上删除，故只要写Pop就行了
void QueuePop(struct Queue* st);
QDataType QueueTop(struct Queue* st);
bool QueueEmpty(struct Queue* st);
int QueueSize(struct Queue* st);
void QueueDestory(struct Queue* st);