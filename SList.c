#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
//��ӡ���ı�
void SListPrint(SListNode *ps)
{
	while (ps)
	{
		printf("%d->", ps->x);
		ps = ps->next;
	}
	printf("NULL\n");
}

//����һ���µĽڵ�
SListNode*  SListBuyNode(SLDataType x)
{
	struct SListNode* n1 = (SListNode*)malloc(sizeof(SListNode));
	if (n1 == NULL)
	{
		printf("creat fail\n");
		exit(-1);
	}
	n1->x = x;
	n1->next = NULL;
	return n1;
}

//������βɾ
void SListPopBack(SListNode** ps)
{
	assert(ps);
	assert(*ps);
	SListNode* tail = *ps;
	SListNode* prev =*ps;
	//������һ���ڵ�����
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	//���������нڵ�����
	else
	{
		while (tail->next)     //ע������ʹ�ӡ�ĵط���һ�������Ҫ��ôд���������Ҫ����������Լ��ټ������Ӿ�֪����
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		/*tail = NULL;*/
		prev->next = NULL;
	}
}

//������β��
void SListPushBack(SListNode** ps, SLDataType x)
{
	assert(ps);
	SListNode* tail = *ps;
	//û�нڵ�����
	if (*ps == NULL)
	{
		*ps = SListBuyNode(x);
	}
	//�нڵ�����
	else
	{
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = SListBuyNode(x);
	}
}


//ͷɾ
void SListPopFront(SListNode** ps)
{
	assert(ps);
	assert(*ps);
	//һ���ڵ�����
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	//����ڵ�����
	else
	{
		SListNode* next = (*ps)->next;
		free(*ps);
		*ps = next;
	}
}

void SListPushFront(SListNode** ps, SLDataType x)
{
	assert(ps);
	//�սڵ�����
	if (*ps == NULL)
	{
		*ps = SListBuyNode(x);
	}
	//�нڵ�����
	else
	{
		SListNode* temp = *ps;
		*ps = SListBuyNode(x);
		(*ps)->next = temp;
	}


	 //����дҲ���ԣ���Ϊif����������������else��������棬����д���Լ��ٴ�����ظ���������һ��д�����������ӵļ������
	//SListNode* temp = *ps;
	//*ps = SListBuyNode(x);
	//(*ps)->next = temp;
}

SListNode* SListFind(SListNode* phead, SLDataType x)
{
	SListNode* cur = phead;
	while (cur)                  //���һ��Ҫдcur������дcur->next����Ȼ���һ���ڵ��ǽ���ȥ��
	{
		if (cur->x == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}


//��ĳ���ڵ�֮ǰ����
void SListInsert(SListNode** ps, SListNode* pos, SLDataType x)
{
	assert(ps);
	SListNode* tail = *ps;
	SListNode* prev = *ps;
	//�սڵ�����
	if (*ps == NULL)           //ע�����ǧ����д��tail��Ȼ���tail���в���
	{
		*ps = SListBuyNode(x);
	}
	//һ���ڵ�����
	else if ((tail)->next == NULL)
	{
		struct SListNode* newnode = SListBuyNode(x);
		*ps = newnode;
		newnode->next = tail;
	}
	//����ڵ�����
	else
	{
		while ((tail) != pos)
		{
			prev = tail;
			tail = tail->next;
		}
		/*prev->next = SListBuyNode(x);
		prev->next->next = tail;      */   //��Ϊǰ���SListBuyNode�����Լ�������һ��ռ䣬���ռ䲻��ԭ����������������һ������������������

		struct SListNode* newnode = SListBuyNode(x);
		newnode->next = tail;
		prev->next = newnode;
	}
}



//void SListInsert(SListNode** pphead, SListNode* pos, SLDataType x)
//{
//	assert(pphead);
//	assert(pos);
//
//	// 1��ͷ��
//	// 2���������
//	if (*pphead == pos)
//	{
//		SListPushFront(pphead, x);
//	}
//	else
//	{
//		// �ҵ�posλ�õ�ǰһ���ڵ�
//		SListNode* prev = *pphead;
//		while (prev->next != pos)
//		{
//			prev = prev->next;
//		}
//
//		SListNode* newnode = SListBuyNode(x);
//		newnode->next = pos;
//		prev->next = newnode;
//	}
//}


//��ĳ���ڵ�֮�����
void SListInsertAfter( SListNode* pos, SLDataType x)
{
	SListNode* newnode = SListBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//��ĳ��λ��֮��ɾ��
void SListEraseAfter(SListNode* pos)
{
	SListNode*  nextnext = pos->next->next;
	free(pos->next);
	pos->next = nextnext;
}

//ɾ��pos���λ��
void SListErase(SListNode** ps, SListNode* pos)
{
	assert(ps);
	assert(*ps);
	//һ���ڵ����� ,��Ϊ���ʱ��ͷ���仯�ˣ�����Ҫ��2��ָ�봫�Σ����Ҳ�����ǰ��һ������*ps��ֵ��tailȻ���tail���в����ˣ���Ϊ����tail��Ӱ�첻�������
	if ((*ps)->next == NULL)
	{
		free(*ps);
		*ps = NULL;
	}
	//����ڵ�����
	else
	{
		SListNode* cur = *ps;              //���Ҳ�ǣ������Զ�*psֱ���ã�Ҫ������*ps��λ�ã���Ϊ�㲻��Ҫ��ͷ���иı䣬�����*ps�Ļ�����ô����Ҳ����ű��
		SListNode *prev = *ps;
		while (cur != pos)
		{
			prev = cur;
			cur = cur->next;
		}
		SListNode *next = cur->next;
		free(cur);
		prev->next = next;
	}
}


//�����ж��ٸ��ڵ�
int SListSize(SListNode* ps)
{
	int num = 0;
	while (ps != NULL)
	{
		num++;
		ps = ps->next;
	}
	return num;
}

//�ж��Ƿ�Ϊ��
bool SListEmpty(SListNode* ps)
{
	return ps == NULL;
}


