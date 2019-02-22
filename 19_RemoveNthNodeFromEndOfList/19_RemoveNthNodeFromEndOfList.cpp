// 19_RemoveNthNodeFromEndOfList.cpp : Defines the entry point for the console application.
//

/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* p1 = nullptr;
		ListNode* p2 = head;
		ListNode* p3 = head;
		for (int i = 0; i < n; i++)
		{
			p3 = p3->next;
		}

		while (p3 != nullptr)
		{
			p3 = p3->next;
			p1 = p2;
			p2 = p2->next;
		}

		if (p1 != nullptr)
		{
			p1->next = p2->next;
			delete p2;
			return head;
		}
		else
		{
			head = p2->next;
			delete p2;
			return head;
		}
	}
};

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* tail = head;
	std::vector<int> nums = { 2, 3, 4, 5 };
	for each (int var in nums)
	{
		tail->next = new ListNode(var);
		tail = tail->next;
	}

	Solution sln;
	head = sln.removeNthFromEnd(head, 5);

	while (head != nullptr)
	{
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;

    return 0;
}

