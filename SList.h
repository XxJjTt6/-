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


//ֵ���ݣ�����Ҫ������ͷ�����иı�
void SListPrint(SListNode* ps);
SListNode* SListFind(SListNode* phead, SLDataType x);
void SListInsertAfter(SListNode* pos, SLDataType x);
void SListEraseAfter(SListNode* pos);        
int SListSize(SListNode* ps);
bool SListEmpty(SListNode* ps);

//��ַ���ݣ�Ҫ������ͷ�����иı�
void SListPopBack(SListNode** ps);
void SListPushBack(SListNode** ps, SLDataType x);
void SListPopFront(SListNode** ps);
void SListPushFront(SListNode** ps, SLDataType x);
void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x);   //��ĳ���ڵ�֮ǰ����
void SListErase(SListNode** ps, SListNode* pos);     //ɾ��posλ��
