#define _CRT_SECURE_NO_WARNINGS 1
   //letcoode21. 合并两个有序链表
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	/* 不带哨兵位的方法
	struct ListNode* head=NULL,*tail=NULL;
	if(l1==NULL)
	{
	return l2;
	}
	if(l2==NULL)
	{
	return l1;
	}
	if(l1->val<l2->val)
	{
	head=tail=l1;
	l1=l1->next;
	}
	else
	{
	head=tail=l2;
	l2=l2->next;
	}
	while(l1!=NULL&&l2!=NULL)
	{
	if(l1->val<l2->val)
	{
	tail->next=l1;
	l1=l1->next;
	}
	else
	{
	tail->next=l2;
	l2=l2->next;
	}
	tail=tail->next;
	}
	if(l1)
	{
	tail->next=l1;
	}
	if(l2)
	{
	tail->next=l2;
	}
	return head;*/



	//带哨兵位的方法，这种方法不需要找第一个放到tail中
	//struct ListNode* head = NULL, *tail = NULL;
	//head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

	//tail->next = NULL;   切勿将此时的tail认为是空指针，此时指针指向malloc开辟的空间的地址，所以可以将tail里面的next置为空
	//if (l1 == NULL)
	//{
	//	return l2;
	//}
	//if (l2 == NULL)
	//{
	//	return l1;
	//}
	//while (l1 != NULL&&l2 != NULL)
	//{
	//	if (l1->val<l2->val)
	//	{
	//		tail->next = l1;
	//		l1 = l1->next;
	//	}
	//	else
	//	{
	//		tail->next = l2;
	//		l2 = l2->next;
	//	}
	//	tail = tail->next;
	//}
	//if (l1)
	//{
	//	tail->next = l1;
	//}
	//if (l2)
	//{
	//	tail->next = l2;
	//}
	//struct ListNode* node = head->next;
	//free(head);
	////free(tail); 这里tail不能将其释放，因为链表中都是通过tail来衔接的，如果释放，程序就崩溃了

	//return node;
}


//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。(牛客）




//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//}; */
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x)
//	{
//		//不带哨兵位不好解决
//		/*struct ListNode *less=NULL,*great=NULL,*ltail=NULL,*gtail=NULL;
//		if(pHead==NULL)
//		{
//		return NULL;
//		}
//		struct ListNode *cur=pHead;
//		while(cur)
//		{
//		less=pHead;
//		great=
//		if(cur->val<x)
//		{
//		ltail=cur;
//		cur=cur->next;
//		ltail=ltail->next;
//		}
//		else
//		{
//		gtail=cur;
//		cur=cur->next;
//		gtail=gtail->next;
//		}
//		}
//		ltail->next=*/
//		struct ListNode *less, *great, *ltail, *gtail;
//		less = ltail = (struct ListNode *)malloc(sizeof(struct ListNode));
//		great = gtail = (struct ListNode *)malloc(sizeof(struct ListNode));
//		struct ListNode*cur = pHead;
//		if (pHead == NULL)
//		{
//			return NULL;
//		}
//		while (cur)
//		{
//			if (cur->val<x)
//			{
//				ltail->next = cur;
//				cur = cur->next;
//				ltail = ltail->next;
//			}
//			else
//			{
//				gtail->next = cur;
//				cur = cur->next;
//				gtail = gtail->next;
//			}
//		}
//		ltail->next = great->next;
//		gtail->next = NULL;
//		pHead = less->next;
//		free(less);
//		free(great);
//		return pHead;
//	}
//};