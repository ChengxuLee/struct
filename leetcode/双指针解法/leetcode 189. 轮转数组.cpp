#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//����һ�����飬�������е�Ԫ��������ת k?��λ�ã�����?k?�ǷǸ�����
//
//
//
//ʾ�� 1:
//
//����: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//��� : [5, 6, 7, 1, 2, 3, 4]
//���� :
//    ������ת 1 �� : [7, 1, 2, 3, 4, 5, 6]
//    ������ת 2 �� : [6, 7, 1, 2, 3, 4, 5]
//    ������ת 3 �� : [5, 6, 7, 1, 2, 3, 4]


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