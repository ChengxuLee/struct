#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//给你一个数组，将数组中的元素向右轮转 k?个位置，其中?k?是非负数。
//
//
//
//示例 1:
//
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//    向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//    向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//    向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]


class Solution {
public:
    void reservev(int l, int r, vector<int>& nums) {
        while (l <= r) {
            int tmp = nums[r];
            nums[r] = nums[l];
            nums[l] = tmp;
            l++;r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (nums.size() >= 2) {
            reservev(0, nums.size() - k - 1, nums);
            reservev(nums.size() - k, nums.size() - 1, nums);
            reservev(0, nums.size() - 1, nums);
        }

    }
};
int main() {
	system("pause");
	return 0;
}