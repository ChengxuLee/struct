#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
//
//如果数组中不存在目标值 target，返回?[-1, -1]。
//
//进阶：
//
//你可以设计并实现时间复杂度为?O(log n)?的算法解决此问题吗？
//
//
//示例 1：
//
//输入：nums = [5, 7, 7, 8, 8, 10], target = 8
//输出：[3, 4]
//
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int l = 0;int r = nums.size() - 1;
//        int mid = 0;
//        vector<int> a(2, -1);
//        if (nums.empty()) { return a; };
//        //左边界
//        while (l < r) {
//            mid = l + (r - l) / 2;
//            if (nums[mid] < target) {
//                l = mid + 1;
//            }
//            else {
//                r = mid;
//            }
//        }
//        //********这个地方注意 l和r要归原******
//        if (nums[r] == target) { a[0] = r;l = 0, r = nums.size() - 1; }
//        else { return a; };
//        //查找右边界
//        while (l < r) {
//            mid = l + (r - l + 1) / 2;
//            if (nums[mid] > target) {
//                r = mid - 1;
//            }
//            else {
//                l = mid;
//            }
//        }
//        if (nums[l] == target) { a[1] = l; }
//        else { return a; };
//        return a;
//    }
//};

int main() {
	system("pause");
	return 0;
}