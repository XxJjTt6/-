#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

//˳���ʵ�ֵķ�ʽ

void StackInit(struct Stack* st)
{
	assert(st);
	st->a = NULL;
	st->top = 0;
	st->capacity = 0;
	
}
void StackDestory(struct Stack* st)
{
	assert(st);
	//while (st->top!=0)
	//{
	//	//st->a�����һ�������Ŀռ䣬�ͷ�ʱӦ��д
	//	//��free(st->a)��Ӧ�����ռ��������ģ�����
	//	//����д�����Ǵ����
	//	free(st->a[st->top-1]);      
	//	st->top--;
	//}
	if (st->a)
	{
		free(st->a);
	}
	st->a = NULL;
	st->top = 0;
	st->capacity = 0;
}
void StackPush(struct Stack* st, STDataType x)
{
	assert(st);
	if (st->top == st->capacity)
	{
		if (st->top == 0)
		{
			st->capacity += 4;
		}
		else
		{
			st->capacity *= 2;
		}
/*		//��ò�Ҫ����д����һ����ʧ���ˣ�����ʧ��
		//�Ͳ���ֱ�Ӹ�st->a�ˣ���������и���ʱ����
		//������һ��
		st->a = (STDataType*)realloc(st->a, sizeof(STDataType)* 4);
		//ϸ�ڷ��棬��ü��ϣ���ֹ����ʧ��
		if (st->a == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
*/
		//�Ϻõ�д��
		STDataType* temp = (STDataType*)realloc(st->a, sizeof(STDataType)* 4);
		if (temp == NULL)
		{
			printf("realloc failed\n");
			exit(-1);
		}
		else
		{
			st->a = temp;
		}
	}
	st->a[st->top] = x;
	st->top++;
}
STDataType StackTop(struct Stack* st)
{
	assert(st);
	//��һջΪ���ˣ������������ҲҪ����һ��
	assert(!StackEmpty(st));
	return st->a[st->top - 1];
}
void StackPop(struct Stack* st)
{
	assert(st);
	//��һջΪ���ˣ������������ҲҪ����һ��
	assert(!StackEmpty(st));
	--st->top;
}
bool StackEmpty(struct Stack* st)
{
	assert(st);
	return st->top == 0;
}
int  StackSize(struct Stack* st)
{
	assert(st);
	return st->top;
}


//�õ�����ķ�ʽ��ʵ��ջ
//struct Stack* StackInit()   
//{
//	struct Stack* phead = (struct Stack*)malloc(sizeof(struct Stack));
//	if (phead == NULL)
//	{
//		printf("malloc failed\n");
//		exit(-1);
//	}
//	phead->data = -1;
//	phead->next = NULL;
//	return phead;
//}
//void StackDestory(struct Stack* phead)
//{
//	assert(phead);
//	struct Stack* cur = phead;
//	while (cur)
//	{
//		free(phead);
//		cur = cur->next;
//		phead = cur;
//	}
//}
//void StackPush(struct Stack** phead, STDataType x)
//{
//	assert(*phead);
//	struct Stack* newnode = (struct Stack*)malloc(sizeof(struct Stack));
//	if (newnode == NULL)
//	{
//		printf("malloc failed\n");
//	}
//	else
//	{
//		newnode->data = x;
//		newnode->next = *phead;
//		*phead = newnode;
//	}
//}
//STDataType StackTop(struct Stack** phead)
//{
//	assert(phead);
//	return (*phead)->data;
//}
//void StackPop(struct Stack** phead)
//{
//	assert(*phead);
//	struct Stack* newphead = (*phead)->next;
//	free(*phead);
//	*phead = newphead;
//}
//bool StackEmpty(struct Stack** phead)
//{
//	return *phead == NULL;
//}
//int  StackSize(struct Stack* phead)
//{
//	int n = 0;
//	struct Stack* cur = phead;
//	while (cur)
//	{
//		++n;
//		cur = cur->next;
//	}
//	return n;
//}