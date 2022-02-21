#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//给定一个字符串?s?，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//
//
//示例 1：
//
//输入：s = "Let's take LeetCode contest"
//输出："s'teL ekat edoCteeL tsetnoc"
//示例 2:
//
//输入： s = "God Ding"
//输出："doG gniD"
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