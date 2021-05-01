#pragma once                            //һЩ.c�ļ��еĶ���ͺ�������������ͷ�ļ���д���
#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef int STDataType;
struct Stack
{
	STDataType* a;
	int top;
	int capacity;
};

typedef struct Stack Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, STDataType data);
// ��ջ 
void StackPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);