#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
//
//
//
//ʾ�� 1��
//
//���룺s = ["h", "e", "l", "l", "o"]
//�����["o", "l", "l", "e", "h"]


class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;int r = s.size() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }
};

int main() {
	system("pause");
	return 0;
}