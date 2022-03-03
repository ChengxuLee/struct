#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//输入：head = [1, 2, 3, 4]
//输出：[2, 1, 4, 3]
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p0 = new ListNode(0);
        p0->next = head;
        ListNode* prev = p0;
        ListNode* p1 = head;
        while (p1 != nullptr && p1->next != nullptr) {
            ListNode* p2 = p1->next;
            p1->next = p2->next;
            p2->next = p1;
            prev->next = p2;
            prev = p1;
            p1 = p1->next;
        }
        return p0->next;
    }
};
int main() {


	system("pause");
	return 0;
}