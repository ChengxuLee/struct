#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//����һ���ַ���?s?������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
//
//
//
//ʾ�� 1��
//
//���룺s = "Let's take LeetCode contest"
//�����"s'teL ekat edoCteeL tsetnoc"
//ʾ�� 2:
//
//���룺 s = "God Ding"
//�����"doG gniD"
#include <string>
class Solution {
public:
    void myreverse(int l, int r, string& s) {
        while (l < r) {
            int tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        int len = s.size();
        for (r;r <= len;r++) {
            if (s[r] == ' ' || r == len) {
                myreverse(l, r - 1, s);
                l = r + 1;
            }
        }
        return s;
    }
};

int main() {
	system("pause");
	return 0;
}