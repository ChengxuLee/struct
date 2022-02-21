#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
using namespace std;
//����һ����������?nums ��һ������?k ���ж��������Ƿ�������� ��ͬ������?i?��?j ������ nums[i] == nums[j] �� abs(i - j) <= k ��������ڣ����� true �����򣬷��� false ��
//
//
//
//ʾ��?1��
//
//���룺nums = [1, 2, 3, 1], k = 3
//�����true
//ʾ�� 2��
//
//���룺nums = [1, 0, 1, 1], k = 1
//�����true
//ʾ�� 3��
//
//���룺nums = [1, 2, 3, 1, 2, 3], k = 2
//�����false

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2)return false;
        int j = 0; unordered_map<int, int>m;
        for (int i = 0;i < nums.size();i++) {
            if (i > j + k) {
                m.erase(nums[j]);    //����ط���������д��m.erase(nums[j++])
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