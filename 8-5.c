#define _CRT_SECURE_NO_WARNINGS 1
#include"8-5.h"
//二级指针的版本
void  StackInit(struct Stack** phead)
{
	*phead = (struct Stack*)malloc(sizeof(struct Stack));
	if (*phead == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	(*phead)->data = -1;
	(*phead)->next = NULL;
}
void StackDestory(struct Stack* phead)
{
	assert(phead);
	struct Stack* cur = phead;
	while (cur)
	{
		free(phead);
		cur = cur->next;
		phead = cur;
	}
}
void StackPush(struct Stack** phead, STDataType x)
{
	assert(*phead);
	struct Stack* newnode = (struct Stack*)malloc(sizeof(struct Stack));
	if (newnode == NULL)
	{
		printf("malloc failed\n");
	}
	else
	{
		newnode->data = x;
		newnode->next = *phead;
		*phead = newnode;
	}
}
STDataType StackTop(struct Stack** phead)
{
	assert(phead);
	return (*phead)->data;
}
void StackPop(struct Stack** phead)
{
	assert(*phead);
	struct Stack* newphead = (*phead)->next;
	free(*phead);
	*phead = newphead;
}
bool StackEmpty(struct Stack** phead)
{
	return *phead == NULL;
}
int  StackSize(struct Stack* phead)
{
	int n = 0;
	struct Stack* cur = phead;
	while (cur)
	{
		++n;
		cur = cur->next;
	}
	return n;
}


//一级指针的版本
void  StackInit(struct Stack* pphead)
{/*
	phead = (struct Stack*)malloc(sizeof(struct Stack));*/
	if (pphead == NULL)
	{
		printf("malloc failed\n");
		exit(-1);
	}
	pphead->data = -1;
	pphead->next = NULL;
}
void StackDestory(struct Stack* pphead)
{
	assert(pphead);
	struct Stack* cur = pphead;
	while (cur)
	{
		free(pphead);
		cur = cur->next;
		pphead = cur;
	}
}
void StackPush(struct Stack* pphead, STDataType x)
{
	assert(pphead);
	struct Stack* newnode = (struct Stack*)malloc(sizeof(struct Stack));
	if (newnode == NULL)
	{
		printf("malloc failed\n");
	}
	else
	{
		newnode->data = x;
		newnode->next = pphead;
		pphead = newnode;
	}
}
STDataType StackTop(struct Stack* pphead)
{
	assert(pphead);
	return pphead->data;
}
void StackPop(struct Stack* pphead)
{
	assert(pphead);
	struct Stack* newphead = pphead->next;
	free(pphead);
	pphead = newphead;
}
bool StackEmpty(struct Stack* pphead)
{
	return pphead == NULL;
}
int  StackSize(struct Stack* pphead)
{
	int n = 0;
	struct Stack* cur = pphead;
	while (cur)
	{
		++n;
		cur = cur->next;
	}
	return n;
}