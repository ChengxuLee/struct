#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//using namespace std;
//����һ���� �ǵݼ�˳�� ������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ�� �ǵݼ�˳�� ����
//
//
//
//ʾ�� 1��
//
//���룺nums = [-4, -1, 0, 3, 10]
//�����[0, 1, 9, 16, 100]
//���ͣ�ƽ���������Ϊ[16, 1, 0, 9, 100]
//����������Ϊ[0, 1, 9, 16, 100]
//ʾ�� 2��
//
//���룺nums = [-7, -3, 2, 3, 11]
//�����[4, 9, 9, 49, 121]


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