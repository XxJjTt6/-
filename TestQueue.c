#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

int main()
{
	Queue st;
	QueueInit(&st);
	QueuePush(&st,1);
	QueuePush(&st,2);
	QueuePush(&st,3);
	printf("%d\n", QueueTop(&st));
	QueuePop(&st);
	printf("%d\n", QueueTop(&st));
	QueuePop(&st);
	printf("%d\n", QueueSize(&st));
	QueueDestory(&st);
	return 0;
}