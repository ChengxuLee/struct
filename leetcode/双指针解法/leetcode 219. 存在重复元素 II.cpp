#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;
//给你一个整数数组?nums 和一个整数?k ，判断数组中是否存在两个 不同的索引?i?和?j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
//
//
//
//示例?1：
//
//输入：nums = [1, 2, 3, 1], k = 3
//输出：true
//示例 2：
//
//输入：nums = [1, 0, 1, 1], k = 1
//输出：true
//示例 3：
//
//输入：nums = [1, 2, 3, 1, 2, 3], k = 2
//输出：false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2)return false;
        int j = 0; unordered_map<int, int>m;
        for (int i = 0;i < nums.size();i++) {
            if (i > j + k) {
                m.erase(nums[j]);    //这个地方不可以连写成m.erase(nums[j++])
                j++;
            }
            if (m.count(nums[i]) == 0) {
                //  m[nums[i]]=1;
                m.insert(pair<int, int>(nums[i], 1));
            }
            else if (m[nums[i]] == 1) {
                return true;
            }
        }
        return false;
    }
};

int main() {
	system("pause");
	return 0;
}