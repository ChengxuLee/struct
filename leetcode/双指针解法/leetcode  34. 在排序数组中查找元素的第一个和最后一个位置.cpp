#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
//
//��������в�����Ŀ��ֵ target������?[-1, -1]��
//
//���ף�
//
//�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ?O(log n)?���㷨�����������
//
//
//ʾ�� 1��
//
//���룺nums = [5, 7, 7, 8, 8, 10], target = 8
//�����[3, 4]
//
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int l = 0;int r = nums.size() - 1;
//        int mid = 0;
//        vector<int> a(2, -1);
//        if (nums.empty()) { return a; };
//        //��߽�
//        while (l < r) {
//            mid = l + (r - l) / 2;
//            if (nums[mid] < target) {
//                l = mid + 1;
//            }
//            else {
//                r = mid;
//            }
//        }
//        //********����ط�ע�� l��rҪ��ԭ******
//        if (nums[r] == target) { a[0] = r;l = 0, r = nums.size() - 1; }
//        else { return a; };
//        //�����ұ߽�
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