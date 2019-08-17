#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* cur = head;
		while (cur&&cur->next)
		{
			if (cur->val == cur->next->val)
			{
				ListNode* del = cur->next;
				cur->next = cur->next->next;
				delete del;
			}
			else
				cur = cur->next;
		}
		return head;
	}
};

int main()
{
	ListNode* liss;
	
	system("pause");
	return 0;
}