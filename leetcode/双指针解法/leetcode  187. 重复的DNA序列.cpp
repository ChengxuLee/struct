#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>

//DNA序列?由一系列核苷酸组成，缩写为?'A', 'C', 'G'?和?'T'.。
//
//例如，"ACGAATTCCG"?是一个 DNA序列 。
//在研究 DNA 时，识别 DNA 中的重复序列非常有用。
//
//给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的?长度为?10?的序列(子字符串)。你可以按 任意顺序 返回答案。
//
//
//
//示例 1：
//
//输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//输出：["AAAAACCCCC", "CCCCCAAAAA"]

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> a;
        map<string, int> m;
        string str1;
        if (s.size() < 10)return a;
        for (int i = 0;i + 9 < s.size();i++) {
            str1 = s.substr(i, 10);
            if (m.count(str1) == 0) {
                m.insert(pair<string, int>(str1, 1));
            }
            else if (m[str1] == 1) {
                m[str1] = 2;
                a.push_back(str1);
            }
        }
        return a;
    }
};


int main() {
  
    system("pause");
    return 0;
}