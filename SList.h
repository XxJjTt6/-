#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType x;
	struct SListNode* next;
}SListNode;


//值传递，不需要对外面头结点进行改变
void SListPrint(SListNode* ps);
SListNode* SListFind(SListNode* phead, SLDataType x);
void SListInsertAfter(SListNode* pos, SLDataType x);
void SListEraseAfter(SListNode* pos);        
int SListSize(SListNode* ps);
bool SListEmpty(SListNode* ps);

//地址传递，要对外面头结点进行改变
void SListPopBack(SListNode** ps);
void SListPushBack(SListNode** ps, SLDataType x);
void SListPopFront(SListNode** ps);
void SListPushFront(SListNode** ps, SLDataType x);
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x);   //在某个节点之前插入
void SListErase(SListNode** ps, SListNode* pos);     //删除pos位置
