#define _CRT_SECURE_NO_WARNINGS 1
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		struct ListNode *prev = NULL, *cur = pHead, *next = pHead->next;
		while (next)
		{
			if (cur->val == next->val)
			{
				while (next&&cur->val == next->val)
				{
					next = next->next;
				}
				while (cur != next)
				{
					struct ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				if (prev == NULL)
				{
					pHead = cur;

				}
				else
				{
					prev->next = cur;
				}
				if (next)
				{
					next = next->next;
				}
			}
			else
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
		}
		return pHead;
	}
};


/*��������Ķ�����ʾ���ϡ��ӵ�һ��Ԫ�ؿ�ʼ����������Ա���Ϊ�Ѿ����������ú�ɫ��ʾ����
ÿ�ε���ʱ���������������Ƴ�һ��Ԫ�أ��ú�ɫ��ʾ������ԭ�ؽ�����뵽���ź���������С�

��Դ�����ۣ�LeetCode��
���ӣ�https ://leetcode-cn.com/problems/insertion-sort-list
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������*/
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* nhead = head, *cur = head->next, *p = NULL, *c = nhead;
	nhead->next = NULL;
	while (cur) //��ֹ����
	{
		struct ListNode*next = cur->next;//��������

		//��취�����Ƶ�ǰ��
		p = NULL;
		c = nhead;
		while (c)
		{
			if (cur->val<c->val)
			{
				break;
			}
			else
			{
				p = c;
				c = c->next;
			}
		}
		if (p == NULL)
		{
			cur->next = nhead;
			nhead = cur;
		}
		else
		{
			p->next = cur;
			cur->next = c;
		}
		cur = next;
	}
	return nhead;

}

//˫�������ɾ���

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

void ListDestroy(ListNode* pHead)
{
	ListNode*cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode*next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	printf("%d", pHead->_data);
	while (cur != pHead)
	{
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("%\n");
}
//�Լ�����һ�����
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	/*ListNode* tail = pHead->_next;
	while (tail != pHead)
	{
		tail = tail->_next;
	}
	ListNode* ad = BuyListNode(x);
	ad*/
	ListNode* newnode = BuyListNode(x);
	//phead         tail   newnode
	ListNode* tail = pHead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = pHead;
	pHead->prev = newnode;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	ListNode* tail = pHead->prev;
	ListNode* tailprev = tail->prev;
	//free(tail);����д���������Ϊ���滹Ҫ��
	tailprev->_next = pHead;
	pHead->_prev = tailprev;
	free(tail);

}