#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
/*给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
输入：head = [1, 2, 3, 3, 4, 4, 5]
输出：[1, 2, */5]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* first = new  ListNode();
        first->next = head;
        ListNode* pre = first;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q != nullptr) {
            if (p->val != q->val) {
                q = q->next;
                p = p->next;
                pre = pre->next;
            }
            else {
                int tmp = p->val;
                while (q && q->val == tmp) {
                    q = q->next;
                }
                pre->next = q;
                p = q;
                if (q != nullptr) q = q->next;
            }
        }
        return first->next;
    }
};
int main() {


	system("pause");
	return 0;
}