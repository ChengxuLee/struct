#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>

//DNA����?��һϵ�к�������ɣ���дΪ?'A', 'C', 'G'?��?'T'.��
//
//���磬"ACGAATTCCG"?��һ�� DNA���� ��
//���о� DNA ʱ��ʶ�� DNA �е��ظ����зǳ����á�
//
//����һ����ʾ DNA���� ���ַ��� s ������������ DNA �����г��ֲ�ֹһ�ε�?����Ϊ?10?������(���ַ���)������԰� ����˳�� ���ش𰸡�
//
//
//
//ʾ�� 1��
//
//���룺s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//�����["AAAAACCCCC", "CCCCCAAAAA"]

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