#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"
#include"Queue.h"
void TestStack()     // ����������ΪTest.c���ļ�һ�㶼�����������õ�
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	while (!StackEmpty(&st))
	{
		printf("%d", StackTop(&st));
		StackPop(&st);
	}
	StackDestroy(&st);
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
}

int main()
{
	//TestStack();
	TestQueue(); 
	return 0;
}