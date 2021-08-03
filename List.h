#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int ListDataType;
typedef struct ListNode
{
	struct ListNode* pre ;
	struct ListNode* next;
	ListDataType data;
}ListNode;

void ListInit(struct ListNode** pphead);
void ListPrint(struct ListNode* phead);
void ListPushBack(struct ListNode* phead, ListDataType x);
struct ListNode* BuyNode(ListDataType x);
void ListPopBack(struct ListNode* phead);
void ListPushFront(struct ListNode* phead, ListDataType x);
void ListPopFront(struct ListNode* phead);
struct ListNode* ListFind(struct ListNode* phead, ListDataType x);
void ListInsert(struct ListNode* phead, struct ListNode* pos, ListDataType x);
void ListErase(struct ListNode* phead, struct ListNode* pos);
bool ListEmpty(struct ListNode* phead);
int ListSize(struct ListNode* phead);