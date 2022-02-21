#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
//����һ���±�� 1 ��ʼ����������?numbers ���������Ѱ� �ǵݼ�˳������? ��������������ҳ��������֮�͵���Ŀ����?target ������������������������ֱ��� numbers[index1] �� numbers[index2] ���� 1 <= index1 < index2 <= numbers.length ��
//
//    �Գ���Ϊ 2 ����������[index1, index2] ����ʽ�����������������±� index1 �� index2��
//
//    ����Լ���ÿ������ ֻ��ӦΨһ�Ĵ� �������� ������ �ظ�ʹ����ͬ��Ԫ�ء�
//
//    ������ƵĽ����������ֻʹ�ó������Ķ���ռ䡣
//
//
//    ʾ�� 1��
//
//    ���룺numbers = [2, 7, 11, 15], target = 9
//    �����[1, 2]
//    ���ͣ�2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ������[1, 2] ��



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;int r = numbers.size() - 1; int sum;
        vector <int> a;
        while (l < r) {
            sum = numbers[l] + numbers[r];
            if (sum == target) {
                a.push_back(l + 1);
                a.push_back(r + 1);
                return a;
            }
            else if (sum < target) {
                l++;
            }
            else {
                r--;
            }

        }
        return numbers;
    }
};

int main() {
	system("pause");
	return 0;
}