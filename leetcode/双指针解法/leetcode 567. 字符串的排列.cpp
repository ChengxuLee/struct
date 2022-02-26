#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
//给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。
//
//换句话说，s1 的排列之一是 s2 的 子串 。
//
//
//
//示例 1：
//
//输入：s1 = "ab" s2 = "eidbaooo"
//输出：true
//解释：s2 包含 s1 的排列之一("ba").
//
#include <string>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int>v1(26, 0);
        vector<int>v2(26, 0);
        for (int i = 0;i < s1.size();i++) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        if (v1 == v2) return true;
        for (int k = s1.size();k < s2.size();k++) {
            v2[s2[k] - 'a']++;
            v2[s2[k - s1.size()] - 'a']--; //滑动窗口
            if (v1 == v2) return true;
        }
        return false;
    }
};
int main() {
	system("pause");
	return 0;
}