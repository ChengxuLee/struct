#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//输入：head = [1, 2, 3, 4, 5], n = 2
//输出：[1, 2, 3, 5]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;ListNode* slow = head;
        if (head == nullptr) return head;
        while (n) { //快指针先移动n次
            fast = fast->next;
            n--;
        }
        if (fast == nullptr) return head->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

int main() {
	system("pause");
	return 0;
}