#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//����һ��ͷ���Ϊ head?�ķǿյ���������������м��㡣
//
//����������м��㣬�򷵻صڶ����м��㡣
//
//
//
//ʾ�� 1��
//
//���룺[1, 2, 3, 4, 5]
//��������б��еĽ�� 3 (���л���ʽ��[3, 4, 5])
//���صĽ��ֵΪ 3 ��(����ϵͳ�Ըý�����л�������[3, 4, 5])��
//ע�⣬���Ƿ�����һ�� ListNode ���͵Ķ��� ans��������
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, �Լ� ans.next.next.next = NULL.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;ListNode* q = head;
        while (q != nullptr && q->next != nullptr)//qΪ��֤���ñ�Ϊ�ձ�
        {
            q = q->next->next;
            p = p->next;
        }
        return p;
    }
};

int main() {

	system("pause");
	return 0;
}