#define _CRT_SECURE_NO_WARNINGS 1
   //letcoode21. �ϲ�������������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	/* �����ڱ�λ�ķ���
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



	//���ڱ�λ�ķ��������ַ�������Ҫ�ҵ�һ���ŵ�tail��
	//struct ListNode* head = NULL, *tail = NULL;
	//head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));

	//tail->next = NULL;   ���𽫴�ʱ��tail��Ϊ�ǿ�ָ�룬��ʱָ��ָ��malloc���ٵĿռ�ĵ�ַ�����Կ��Խ�tail�����next��Ϊ��
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
	////free(tail); ����tail���ܽ����ͷţ���Ϊ�����ж���ͨ��tail���νӵģ�����ͷţ�����ͱ�����

	//return node;
}


//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣(ţ�ͣ�




//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//}; */
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x)
//	{
//		//�����ڱ�λ���ý��
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