#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SQDataType; //为了方便以后，万一类型改了，那么到时候只要这么改下就行了
typedef struct SeqList
{
	SQDataType *a;
	int size;
	int capcaity;
}SLT;              //给他重新起个名字，方便下面写代码


void SeqListinit(SLT * ps1);
void SeqListDestory(SLT *ps1);   //既然代码中有动态开辟空间，自然就要销毁动态开辟的内存
void SeqListPushBack(SLT* ps1, SQDataType x);  //尾部插入
void SeqListPushFront(SLT* ps1, SQDataType x); //头部插入
void SeqListPopBack(SLT* ps1);  //尾部删除
void SeqListPopFront(SLT* ps1); //头部删除
void SeqListInsert(SLT* ps1,size_t pos, SQDataType x);  //任意位置的插入
void SeqListErase(SLT* ps1,size_t pos);  //任意位置的删除
void SeqListPrintf(SLT* ps1); //打印顺序表
