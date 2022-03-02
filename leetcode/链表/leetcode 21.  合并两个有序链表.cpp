#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(0);
        ListNode* p = list3;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                p->next = list1;
                p = p->next;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                p = p->next;
                list2 = list2->next;
            }

        }
        if (list1 == nullptr) {
            p->next = list2;
        }
        else if (list2 == nullptr) {
            p->next = list1;
        }
        return list3->next;
    }
};
int main() {


	system("pause");
	return 0;
}