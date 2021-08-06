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
//��Ϊ�ӵ����ʣ����ֻ����β�ϲ��룬��û��Ҫд����
//β�壬��Ϊֻ����β�ϲ���
void QueuePush(struct Queue* st,QDataType x);
//��Ϊһ������ͷ��ɾ������ֻҪдPop������
void QueuePop(struct Queue* st);
QDataType QueueTop(struct Queue* st);
bool QueueEmpty(struct Queue* st);
int QueueSize(struct Queue* st);
void QueueDestory(struct Queue* st);