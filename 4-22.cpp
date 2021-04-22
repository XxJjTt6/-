#define _CRT_SECURE_NO_WARNINGS 1
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
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


/*插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	struct ListNode* nhead = head, *cur = head->next, *p = NULL, *c = nhead;
	nhead->next = NULL;
	while (cur) //终止条件
	{
		struct ListNode*next = cur->next;//迭代条件

		//想办法将其移到前面
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

//双链表的增删查改

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
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

// 双向链表打印
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
//自己创建一个结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

// 双向链表尾插
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

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	ListNode* tail = pHead->prev;
	ListNode* tailprev = tail->prev;
	//free(tail);不能写在这儿，因为下面还要用
	tailprev->_next = pHead;
	pHead->_prev = tailprev;
	free(tail);

}