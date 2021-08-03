#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
//��ʼ��
void ListInit(struct ListNode** pphead)
{
	/*(*pphead)->data = 1;              //��һ���ڵ�Ŀռ仹û�д����ˣ����Բ�����ôд
	(*pphead)->pre = NULL;
	(*pphead)->next = NULL;
	(*pphead)->next = *pphead;
	(*pphead)->pre = *pphead;*/
	*pphead = BuyNode(-1);
	(*pphead)->next = *pphead;
	(*pphead)->pre = *pphead;
}

//��ӡ
void ListPrint(struct ListNode* phead)
{
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//����һ���ڵ�
struct ListNode* BuyNode(ListDataType x)
{
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}

//β��
void ListPushBack(struct ListNode* phead,ListDataType x)
{
	assert(phead);   //д��һ����Ҫ�������������ListInit�����ʼ��ûд�������ᵼ��pheadΪ�գ�˫���ͷѭ�������������Ҫ��ͷ�ڵ㣬
	                 //��Ȼ�κι��ܶ�̸��������������߱���Ҫ����һ��
	struct ListNode* tail = phead->pre;
	struct ListNode* newnode=BuyNode(x);
	tail->next = newnode;
	newnode->pre = tail;
	newnode->next = phead;
	phead->pre = newnode;
}


//βɾ
void ListPopBack(struct ListNode* phead)
{
	assert(phead->next!=phead);    //������д���ԵĻ�������ѵ�һ����ͷ�ڵ�Ҳ����ɾ����
	struct ListNode* tail = phead->pre;
	struct ListNode* tailpre = tail->pre;
	free(tail);
	tailpre->next = phead;
	phead->pre = tailpre;
}

//ͷ��
void ListPushFront(struct ListNode* phead,ListDataType x)
{
	assert(phead);
	struct ListNode* newnode = BuyNode(x);
	newnode->next = phead->next;
	phead->next->pre = newnode;
	phead->next = newnode;
	newnode->pre = phead;
	//newnode->next=phead->next   ͷ��Ļ��������Ҫд��ǰ�棬д�ں���Ļ���phead->next�Ѿ�����ǰ��ı���ˣ�������ԭ����ֵ��
}

//ͷɾ
void ListPopFront(struct ListNode* phead)
{
	assert(phead->next != phead);    // //������д���ԵĻ�������ѵ�һ����ͷ�ڵ�Ҳ����ɾ����
	struct ListNode* headnext = phead->next->next;
	free(phead->next);
	phead->next = headnext;
	headnext->pre = phead;
}

//��ĳһ���ڵ��λ��
struct ListNode* ListFind(struct ListNode* phead, ListDataType x)
{
	struct ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
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

//������λ��֮ǰ����
void ListInsert(struct ListNode* phead, struct ListNode* pos, ListDataType x)
{
	assert(phead->next != phead);          //��ֹ�������Ϊ��ʱ�����룬�Ѿ���ʱ�Ѿ�û�нڵ����Ѱ����
	struct ListNode* newnode = BuyNode(x);
	newnode->pre = pos->pre;   //Ҫע�������˳��
	pos->pre->next = newnode;
	newnode->next = pos;
	pos->pre = newnode;
	//newnode->pre = pos->pre->pre;    д���ˣ�����ǰ���ǰ��һ���ڵ��ˣ�����Ҫ��ֻ��Ҫposǰ��һ���ڵ������
	//pos->pre->pre->next = newnode;
}


//ɾ������λ��
void ListErase(struct ListNode* phead, struct ListNode* pos)
{
	assert(phead->next != phead);
	struct ListNode* next = pos->next;
	struct ListNode* pre = pos->pre;
	free(pos);
	pre->next = next;
	next->pre = pre;
}

//�ж������Ƿ�Ϊ��
bool ListEmpty(struct ListNode* phead)
{
	return phead->next == phead ? true : false;
}

//�����м����ڵ�
int ListSize(struct ListNode* phead)
{
	struct ListNode* cur = phead->next;
	int n = 0;
	while (cur != phead)
	{
		++n;  //�������������������Ч��ֱ��ǰ�üӼ�
		cur = cur->next;
	}
	return n;
}

