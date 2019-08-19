#include <iostream>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* cur = head;
		ListNode* nn = NULL;
		int count = 0;
		while (cur != NULL)
		{
			++count;
			nn = cur;
			cur = cur->next;
		}
		if (count == 0)
			return head;
		int rot = k%count;
		nn->next = head;
		cur = head;
		for (int i = 0; i<count - rot - 1; i++)
			cur = cur->next;
		head = cur->next;
		cur->next = NULL;
		return head;
	}
};