#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
//����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ��������һ�����ʵĳ��ȡ�
//
//���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����
//
//
//
//ʾ�� 1��
//
//���룺s = "Hello World"
//�����5
//ʾ�� 2��
//
//���룺s = "   fly me   to   the moon  "
//�����4
//ʾ�� 3��
//
//���룺s = "luffy is still joyboy"
//�����6
class Solution {
public:
	int lengthOfLastWord(string s) {
		int index = s.size() - 1;
		int count = 0;
		while (s[index] == ' ') {
			index--;
		}
		while (index >= 0 && s[index] != ' ') {
			count++;
			index--;
		}
		return count;
	}
};

int main() {

	system("pause");
	return  0;
}