#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

//用顺序表来实现栈
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void StackInit(struct Stack* st);
//void StackDestory(struct Stack* st);
//void StackPush(struct Stack* st,STDataType x);
//STDataType StackTop(struct Stack* st);
//void StackPop(struct Stack* st);
//bool StackEmpty(struct Stack* st);
//int  StackSize(struct Stack* st);

//用单链表的方式来实现栈
typedef int STDataType;
typedef struct Stack
{
	STDataType data;
	struct Stack* next;
}ST;

//二级指针的传法
//void StackInit(struct Stack** phead);
//void StackDestory(struct Stack* phead);
//void StackPush(struct Stack** phead, STDataType x);
//STDataType StackTop(struct Stack** phead);
//void StackPop(struct Stack** phead);
//bool StackEmpty(struct Stack** phead);
//int  StackSize(struct Stack* phead);

//一级指针的传法
void StackInit(struct Stack* pphead);
void StackDestory(struct Stack* pphead);
void StackPush(struct Stack* pphead, STDataType x);
STDataType StackTop(struct Stack* pphead);
void StackPop(struct Stack* pphead);
bool StackEmpty(struct Stack* pphead);
int  StackSize(struct Stack* pphead);