#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int weight;  //Ȩֵ
	int parent; // ˫�׽��λ��
	int rchild, lchild;
}TreeNode;
typedef struct HFTree {
	TreeNode* data;
	int length;    //��ǰ����
}HFTree;
HFTree* InitTree(int* weight, int length) {
	HFTree* T = (HFTree*)malloc(sizeof(HFTree));
	T->data = (TreeNode*)malloc(sizeof(TreeNode) * (2 * length - 1));
	T->length = length;
	for (int i = 0; i < length; i++) {
		T->data[i].weight = weight[i];
		T->data[i].parent = 0;
		T->data[i].lchild = -1;
		T->data[i].rchild = -1;
	}
	return T;
}

int* SelectMin(HFTree*T) {
	int min = 10000;
	int secondMin = 10000;
	int IndexMin;
	int SecondIndex;
	for (int i = 0;i < T->length;i++) {
		if (T->data[i].parent==0) {    //parent=0 �Ž��бȽ�
			if (T->data[i].weight<min) {  //ѡ��Ȩֵ��С��
				min = T->data[i].weight;
				IndexMin = i;
			}
		}
	}
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0 && i != IndexMin) { //ѡ��Ȩֵ�ڶ�С��
			if (T->data[i].weight < secondMin) {
				secondMin = T->data[i].weight;
				SecondIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = IndexMin;  //������Сֵ
	res[1] = SecondIndex;  //������ڶ�Сֵ
	return res;  
}
void CreatHFTree(HFTree* T) {
	int Min;
	int secondMin;
	int lenthMax = T->length * 2 - 1;  //�����������ֵ
	for (int i = T->length;i < lenthMax;i++) {
		int* res = SelectMin(T);
		Min = res[0];
		secondMin = res[1];
		T->data[i].weight = T->data[Min].weight + T->data[secondMin].weight; //���ڵ�Ȩֵ
		T->data[i].lchild = Min;  T->data[i].rchild = secondMin; //���ڵ�� ���Һ���ֵ
		T->data[Min].parent = i; T->data[secondMin].parent = i;  //���ӽ��parentֵ
		T->length++;
	}
}
int main() {
	int weight[4] = {1,2,3,4};
	HFTree* T = InitTree(weight,4);
	int* res = SelectMin(T);
	return 0;
}