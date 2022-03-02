#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
//输入：head = [1, 1, 2, 3, 3]
//输出：[1, 2, 3]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = head;
        ListNode* p1 = head->next;
        while (p1 != nullptr) {
            if (p1->val == p->val) {
                p1 = p1->next;
                p->next = p1;
            }
            else {
                p = p1;
                p1 = p1->next;
            }
        }
        return head;
    }
};
int main() {


	system("pause");
	return 0;
}