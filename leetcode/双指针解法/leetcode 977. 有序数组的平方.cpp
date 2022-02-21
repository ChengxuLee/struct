#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//using namespace std;
//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
//
//
//示例 1：
//
//输入：nums = [-4, -1, 0, 3, 10]
//输出：[0, 1, 9, 16, 100]
//解释：平方后，数组变为[16, 1, 0, 9, 100]
//排序后，数组变为[0, 1, 9, 16, 100]
//示例 2：
//
//输入：nums = [-7, -3, 2, 3, 11]
//输出：[4, 9, 9, 49, 121]


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, index = nums.size() - 1;
        vector <int> a(int(nums.size()));
        if (nums.size() < 2) { nums[0] = pow(nums[0], 2);return nums; }
        while (l <= r) {
            if (pow(nums[l], 2) > pow(nums[r], 2)) {
                a[index--] = nums[l] * nums[l];
                l++;
            }
            else {
                a[index--] = nums[r] * nums[r];
                r--;
            }
        }
        return a;
    }
};

int main() {
	system("pause");
	return 0;
}