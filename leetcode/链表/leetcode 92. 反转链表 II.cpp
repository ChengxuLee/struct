#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
//输入：head = [1, 2, 3, 4, 5], left = 2, right = 4
//输出：[1, 4, 3, 2, 5]

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr || right == left) return head;
        ListNode* first = new ListNode(-1, head);
        ListNode* pre = first; int count = 1;
        ListNode* n1 = head;
        ListNode* n2 = head;
        while (count < left) {
            pre = pre->next;
            n1 = n1->next;
            count++; //count=2
        }

        while (count < right) {
            n2 = n1->next;
            n1->next = n2->next;
            n2->next = pre->next;
            pre->next = n2;
            count++;
        }
        return first->next;
    }
};
int main() {


	system("pause");
	return 0;
}