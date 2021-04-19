#define _CRT_SECURE_NO_WARNINGS 1

//9.����һ�������ж��������Ƿ��л�
bool hasCycle(struct ListNode *head)
{
	struct ListNode*slow = head;
	struct ListNode*fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (fast == slow)
		{
			return true;
		}
	}
	return false;
}


//10.����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� NULL
struct ListNode *detectCycle(struct ListNode *head)
{


	struct ListNode*slow = head;
	struct ListNode*fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			struct ListNode*meet = fast;
			while (meet != head)
			{
				meet = meet->next;
				head = head->next;
			}
			return meet;
		}
	}
	return NULL;
}
