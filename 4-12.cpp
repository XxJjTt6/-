#define _CRT_SECURE_NO_WARNINGS 1

//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ�
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

	//û�����ڱ�λ�ķ���
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
	//���ڱ�λ�ķ���
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


	//��תһ��������
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


	//����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

	/*����������м��㣬�򷵻صڶ����м��㡣*/
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


//����һ����������������е�����k����㡣
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