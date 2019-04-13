//class Solution {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode* add = new ListNode(0);   //头结点
//		ListNode* l3 = add;               //头指针
//		int nret = 0;
//		while (l1 != NULL || l2 != NULL)
//		{
//			int ret = 0;
//			if (l1 != NULL)
//			{
//				ret += l1->val;
//				l1 = l1->next;
//			}
//			if (l2 != NULL)
//			{
//				ret += l2->val;
//				l2 = l2->next;
//			}
//			ret += nret;
//			if (ret>9)
//			{
//				ret -= 10;
//				nret = 1;
//			}
//			else nret = 0;
//			l3->next = new ListNode(1);
//			l3 = l3->next;
//			l3->val = ret;
//		}
//		if (nret != 0)
//			l3->next = new ListNode(1);
//		return add->next;
//	}
//};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool AlongerB(ListNode* l1, ListNode* l2)
	{
		while (l1)
		{
			l1 = l1->next;
			l2 = l2->next;
			if (l2 == NULL)
				return true;
		}
		return false;
	}
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *add = new ListNode(0);
		add->next = l1;
		if (AlongerB(l1, l2) == false)
			add->next = l2;
		ListNode *l3 = add;
		int nret = 0;
		while (l1 || l2)
		{
			int ret = 0;
			if (l1 != NULL)
			{
				ret += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				ret += l2->val;
				l2 = l2->next;
			}
			ret += nret;
			if (ret>9)
			{
				ret -= 10;
				nret = 1;
			}
			else
				nret = 0;
			l3 = l3->next;
			l3->val = ret;
		}
		if (nret != 0)
			l3->next = new ListNode(1);
		return add->next;
	}
};