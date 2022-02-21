#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
//
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//
//你可以假设除了整数 0 之外，这个整数不会以零开头。
//
//
//
//示例?1：
//
//输入：digits = [1, 2, 3]
//输出：[1, 2, 4]
//解释：输入数组表示数字 123。
//示例?2：
//
//输入：digits = [4, 3, 2, 1]
//输出：[4, 3, 2, 2]
//解释：输入数组表示数字 4321。
//示例 3：
//
//输入：digits = [0]
//输出：[1]

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        digits[index]++;
        for (index;index > 0;index--) {
            if (digits[index] >= 10) {
                digits[index] = 0;
                digits[index - 1]++;
            }
        }
        if (digits[0] == 0)
            digits.insert(digits.begin(), 1);
        else if (digits[0] >= 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        };
        return digits;
    }
};

int main() {

	system("pause");
	return  0;
}