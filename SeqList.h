#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int SQDataType; //Ϊ�˷����Ժ���һ���͸��ˣ���ô��ʱ��ֻҪ��ô���¾�����
typedef struct SeqList
{
	SQDataType *a;
	int size;
	int capcaity;
}SLT;              //��������������֣���������д����


void SeqListinit(SLT * ps1);
void SeqListDestory(SLT *ps1);   //��Ȼ�������ж�̬���ٿռ䣬��Ȼ��Ҫ���ٶ�̬���ٵ��ڴ�
void SeqListPushBack(SLT* ps1, SQDataType x);  //β������
void SeqListPushFront(SLT* ps1, SQDataType x); //ͷ������
void SeqListPopBack(SLT* ps1);  //β��ɾ��
void SeqListPopFront(SLT* ps1); //ͷ��ɾ��
void SeqListInsert(SLT* ps1,size_t pos, SQDataType x);  //����λ�õĲ���
void SeqListErase(SLT* ps1,size_t pos);  //����λ�õ�ɾ��
void SeqListPrintf(SLT* ps1); //��ӡ˳���
