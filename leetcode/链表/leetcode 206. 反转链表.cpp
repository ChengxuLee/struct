#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//输入：head = [1, 2, 3, 4, 5]
//输出：[5, 4, 3, 2, 1]
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* value = new ListNode();
        value->next = head;
        ListNode* pre = value;
        ListNode* n1 = head;
        while (n1 != nullptr && n1->next != nullptr) {
            ListNode* n2 = n1->next;
            n1->next = n2->next;
            n2->next = pre->next;
            pre->next = n2;
        }

        return value->next;
    }

};
int main() {


	system("pause");
	return 0;
}