#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//
//
//
//ʾ��?1��
//
//���룺digits = [1, 2, 3]
//�����[1, 2, 4]
//���ͣ����������ʾ���� 123��
//ʾ��?2��
//
//���룺digits = [4, 3, 2, 1]
//�����[4, 3, 2, 2]
//���ͣ����������ʾ���� 4321��
//ʾ�� 3��
//
//���룺digits = [0]
//�����[1]

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