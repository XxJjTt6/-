#pragma once                            //一些.c文件中的定义和函数声明都是在头文件中写入的
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

// 初始化栈 
void StackInit(Stack* ps);
// 入栈 
void StackPush(Stack* ps, STDataType data);
// 出栈 
void StackPop(Stack* ps);
// 获取栈顶元素 
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数 
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);