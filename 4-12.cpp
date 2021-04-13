#define _CRT_SECURE_NO_WARNINGS 1

//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点
//struct ListNode* removeElements(struct ListNode* head, int val)
{
	/*while(head->next!=NULL)
	{
	struct ListNode* prev=head;
	if(head->val==val)
	{
	struct ListNode* nextnext=head->next;
	free(head);
	head=NULL;
	prev->next=nextnext;

	}
	else
	{
	head=head->next;
	}
	}
	return head;*/

	//没有用哨兵位的方法
	/*struct ListNode* prev=NULL;
	struct ListNode* cur=head;
	while(cur)
	{

	if(cur->val==val)
	{
	struct ListNode* next=cur->next;
	if(prev==NULL)
	{
	free(cur);
	head=next;
	cur=next;
	}
	else
	{
	prev->next=next;
	free(cur);
	cur=next;
	}
	}
	else
	{
	prev=cur;
	cur=cur->next;
	}
	}
	return head;*/
	//用哨兵位的方法
//	struct ListNode* guardhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//	guardhead->next = head;
//
//	struct ListNode* prev = guardhead;
//	struct ListNode* cur = head;
//	while (cur)
//	{
//		if (cur->val == val)
//		{
//			struct ListNode* next = cur->next;
//			//prev->next=next;
//			free(cur);
//			prev->next = next;
//			cur = next;
//		}
//		else
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//	}
//	head = guardhead->next;
//	free(guardhead);
//	return head;
//}


	//反转一个单链表。
	/*struct ListNode* reverseList(struct ListNode* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
		while (n2)
		{
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			if (n3)
				n3 = n3->next;
		}
		return n1;
	}*/


	//给定一个头结点为 head 的非空单链表，返回链表的中间结点。

	/*如果有两个中间结点，则返回第二个中间结点。*/
	/*struct ListNode* middleNode(struct ListNode* head)
	{
		struct ListNode *slow = head, *fast = head;
		while (fast != NULL&&fast->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}*/


//输入一个链表，输出该链表中倒数第k个结点。
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	// write code here
//	/*struct ListNode* count=pListHead;
//	int i=0;
//	while(count)
//	{
//	i++;
//	count=count->next;
//	}
//	count=pListHead;
//	while(i!=k)
//	{
//	i--;
//	count=count->next;
//	}
//	return count;*/
//	struct ListNode* slow = pListHead;
//	struct ListNode* fast = pListHead;
//	while (k--)
//	{
//		if (fast)
//		{
//			fast = fast->next;
//		}
//		else
//			return NULL;
//	}
//	while (fast)
//	{
//		slow = slow->next;
//		fast = fast->next;
//	}
//	return slow;
//
//}