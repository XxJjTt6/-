#define _CRT_SECURE_NO_WARNINGS 1

//class PalindromeList {
//public:
//	/*struct ListNode* middlenode(struct ListNode* head)
//	{
//	struct ListNode*slow,*quick;
//	slow=quick=head;
//	while(quick&&quick->next)
//	{
//	slow=slow->next;
//	quick=quick->next->next;
//	}
//	return slow;
//	}
//	struct ListNode* reverse(struct ListNode* head)
//	{
//	struct ListNode* cur=head;
//	struct ListNode* prev=NULL;
//	while(cur)
//	{
//	struct ListNode* next=cur->next;
//	cur->next=prev;
//	prev=cur;
//	cur=next;
//	}
//	return prev;
//	}
//	bool chkPalindrome(ListNode* A)
//	{
//	struct ListNode*mid=middlenode(A);
//	struct ListNode*rhead=reverse(mid);
//	while(A&&rhead)
//	{
//	if(A->val!=rhead->val)
//	{
//	return false;
//	}
//	else
//	{
//	A=A->next;
//	rhead=rhead->next;
//	}
//	}
//	return true;
//	}*/
//	/* ����Ҳ�����Ȱ������е�Ԫ��ֵȫ�����浽�����У�Ȼ�����ж������Ƿ�Ϊ���ġ�������ʹ�����ֽⷨ��
//	��Ϊ���û�и���������󳤶ȣ�����ͬ�˽ⷨ*/
//	bool chkPalindrome(ListNode* A)
//	{
//		int a[900] = { 0 };
//		int n = 0;
//		while (A)
//		{
//			a[n++] = A->val;
//			A = A->next;
//		}
//		int begin = 0, end = n - 1;
//		while (begin<end)
//		{
//			if (a[begin] != a[end])
//			{
//				return false;
//			}
//			else
//			{
//				begin++;
//				end--;
//			}
//		}
//		return true;
//	}
//};

//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//	if (headB == NULL || headA == NULL)
//	{
//		return NULL;
//	}
//	struct ListNode*p1 = headA;
//	struct ListNode*p2 = headB;
//	int n1 = 0, n2 = 0;
//	while (p1->next)
//	{
//		p1 = p1->next;
//		n1++;
//	}
//	while (p2->next)
//	{
//		p2 = p2->next;
//		n2++;
//		if (p1 != p2)
//		{
//			return NULL;
//		}
//		struct ListNode* long = headA, *dou = headB;
//		if (n2>n1)
//		{
//			long = headB;
//			dou = headA;
//		}
//		int gap = abs(n1 - n2);
//		while (gap--)
//		{
//			long = long->next;
//		}
//		while (long&&dou)
//		{
//			if (long == dou)
//			{
//				return long;
//			}
//			else
//			{
//				long = long->next;
//				dou = dou->next;
//			}
//		}
//	}