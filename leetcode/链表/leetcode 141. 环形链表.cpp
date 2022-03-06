#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你一个链表的头节点 head ，判断链表中是否有环。
//输入：head = [3, 2, 0, -4], pos = 1
//输出：true
//解释：链表中有一个环，其尾部连接到第二个节点。
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* l1 = head;
        ListNode* l2 = head;
        while (l2 != nullptr) {
            l1 = l1->next;
            l2 = l2->next->next;
            if (l1 == l2) return true;
        }
        return false;
    }
};
int main() {


	system("pause");
	return 0;
}