#define _CRT_SECURE_NO_WARNINGS 1

//9.给定一个链表，判断链表中是否有环
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


//10.给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
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
