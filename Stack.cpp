#define _CRT_SECURE_NO_WARNINGS 1



#include "stack.h"
#define DEFSTACKSIZE 100

void CheckCapacity(Stack* ps)
{
	assert(ps);
	if(ps->top >= ps->capacity)
	{
		STDataType *array = (STDataType *)realloc(ps->a, ps->capacity * sizeof(STDataType));
		if (array = NULL)
		{
			printf("realloc fail\n");
			exit(-1);//结束整个程序，而return是结束当前函数
		}
		ps->a = array;
		ps->capacity *= 2;
	}
}

void StackInit(Stack* ps)
{ 
	//方法1,不方便后面的增容，因为0*2=0；
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;

	//方法2，一上来直接先开辟几个空间，方便后面的增容
	ps->a = (STDataType *)malloc(DEFSTACKSIZE*sizeof(STDataType));
	ps->capacity = DEFSTACKSIZE;
	ps->top= 0;
}

void StackPush(Stack* ps, STDataType x)
{  
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//如果空了以后就不能调用这个接口了，因为如果top在减的话就会变成负数
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//如果空了以后就不能调用这个接口了，因为如果top在减的话就会变成负数
	return ps->a[ps->top-1];
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}