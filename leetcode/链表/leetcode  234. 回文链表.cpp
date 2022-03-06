#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
//输入：head = [1, 2, 2, 1]
//输出：true
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        ListNode* first = head;
//        ListNode* second = head;
//        stack<int> s;
//        if (head->next == nullptr) return true;
//        while (first != nullptr) {
//            s.push(first->val);
//            first = first->next;
//        }
//        while (second != nullptr) {
//            if (s.top() != second->val) return false;
//            s.pop();
//            second = second->next;
//        }
//        return true;
//    }
//};
int main() {


	system("pause");
	return 0;
}