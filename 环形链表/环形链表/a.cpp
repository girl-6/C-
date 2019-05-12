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
//		while (slow)     //�ҵ�meet��
//		{
//			slow = slow->next;
//			fast = fast->next;
//			if (fast == NULL)  return nullptr;  //ֻ�������ڵ����޻�
//			fast = fast->next;
//			if (fast == NULL)  return nullptr;   //�������ڵ����޻�
//			if (fast == slow)  break;       //��meet
//		}
//		slow = head;   //�� l=c-x ֪��slow��head��ʼ�ߵ�a��ľ��룬�պ���fast�ߵ�a��ľ���
//		while (slow != fast)    //�ҵ�a��
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