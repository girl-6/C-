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
	ListNode *detectCycle(ListNode *head) {
		while (head) {
			if (!less<ListNode *>()(head, head->next)) {
				return head->next;
			}
			head = head->next;
		}
		return nullptr;
	}
};


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
//
//class Solution {
//public:
//	ListNode *detectCycle(ListNode *head) {
//		ListNode* slow = head;
//		ListNode* fast = head;
//		while (slow)     //找到meet点
//		{
//			slow = slow->next;
//			fast = fast->next;
//			if (fast == NULL)  return nullptr;  //只有两个节点且无环
//			fast = fast->next;
//			if (fast == NULL)  return nullptr;   //有三个节点且无环
//			if (fast == slow)  break;       //即meet
//		}
//		slow = head;   //由 l=c-x 知，slow从head开始走到a点的距离，刚好是fast走到a点的距离
//		while (slow != fast)    //找到a点
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//	}
//};

int main()
{
	Solution s;
	list<int> l;
	l.push_back(3);
	l.push_back(2);
	l.push_back(0);
	l.push_back(4);
	

	system("pause");
	return 0;
}