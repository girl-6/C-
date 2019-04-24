#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <list>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL || head->next->next == NULL)
			return head;
		ListNode* l1 = head;
		ListNode* next = l1->next;
		ListNode* l2 = next;
		while (l1->next&&l2->next)
		{
			l1->next = l2->next;
			l1 = l2->next;
			l2->next = l1->next;
			l2 = l1->next;
		}
		l1->next = next;
		return head;
	}
};

int main()
{
	Solution s;
	list<ListNode> l = { 1, 2, 3, 4, 5 };
	list<ListNode>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	

	system("pause");
	return 0;
}