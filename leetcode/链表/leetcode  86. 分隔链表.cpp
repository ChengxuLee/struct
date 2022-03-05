#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//
//你应当 保留 两个分区中每个节点的初始相对位置。
//输入：head = [1, 4, 3, 2, 5, 2], x = 3
//输出：[1, 2, 2, 4, 3, 5]
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* l1 = new ListNode();
        ListNode* ll1 = l1;
        ListNode* l2 = new ListNode();
        ListNode* ll2 = l2;
        ListNode* ptr = head;
        while (ptr != nullptr) {
            if (ptr->val < x) {
                l1->next = ptr;
                l1 = ptr;
            }
            else {
                l2->next = ptr;
                l2 = ptr;
            }
            ptr = ptr->next;
        }
        if (ll1->next == nullptr) {
            return ll2->next;
        }
        else if (ll2->next == nullptr) {
            return ll1->next;
        }
        else {
            l1->next = ll2->next;
            l2->next = nullptr;
        }
        return ll1->next;
    }
};
int main() {


	system("pause");
	return 0;
}