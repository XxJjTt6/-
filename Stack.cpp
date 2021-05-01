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
			exit(-1);//�����������򣬶�return�ǽ�����ǰ����
		}
		ps->a = array;
		ps->capacity *= 2;
	}
}

void StackInit(Stack* ps)
{ 
	//����1,�������������ݣ���Ϊ0*2=0��
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;

	//����2��һ����ֱ���ȿ��ټ����ռ䣬������������
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
	assert(!StackEmpty(ps));//��������Ժ�Ͳ��ܵ�������ӿ��ˣ���Ϊ���top�ڼ��Ļ��ͻ��ɸ���
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//��������Ժ�Ͳ��ܵ�������ӿ��ˣ���Ϊ���top�ڼ��Ļ��ͻ��ɸ���
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