#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。
//
//单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
//
//
//
//示例 1：
//
//输入：s = "Hello World"
//输出：5
//示例 2：
//
//输入：s = "   fly me   to   the moon  "
//输出：4
//示例 3：
//
//输入：s = "luffy is still joyboy"
//输出：6
class Solution {
public:
	int lengthOfLastWord(string s) {
		int index = s.size() - 1;
		int count = 0;
		while (s[index] == ' ') {
			index--;
		}
		while (index >= 0 && s[index] != ' ') {
			count++;
			index--;
		}
		return count;
	}
};

int main() {

	system("pause");
	return  0;
}