#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//输入：head = [1, 2, 3, 4, 5], k = 2
//输出：[4, 5, 1, 2, 3]
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;
        //环形链表解决  先连接再断开 
        int len = 1;
        ListNode* p = head;
        while (p->next != nullptr) {
            len++;    //计算总长度
            p = p->next;  //p移动
        }
        p->next = head;//形成环
        //断开连接  连接的位置是 (len-k)%len 
        k = k % len;
        int count = (len - k) % len;

        while (count > 0) {
            p = p->next;
            count--;
        }
        ListNode* newhead = p->next;
        p->next = nullptr;
        return newhead;
    }
};
int main() {


	system("pause");
	return 0;
}