#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int weight;  //权值
	int parent; // 双亲结点位置
	int rchild, lchild;
}TreeNode;
typedef struct HFTree {
	TreeNode* data;
	int length;    //当前长度
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
		if (T->data[i].parent==0) {    //parent=0 才进行比较
			if (T->data[i].weight<min) {  //选出权值最小的
				min = T->data[i].weight;
				IndexMin = i;
			}
		}
	}
	for (int i = 0; i < T->length; i++) {
		if (T->data[i].parent == 0 && i != IndexMin) { //选出权值第二小的
			if (T->data[i].weight < secondMin) {
				secondMin = T->data[i].weight;
				SecondIndex = i;
			}
		}
	}
	int* res = (int*)malloc(sizeof(int) * 2);
	res[0] = IndexMin;  //返回最小值
	res[1] = SecondIndex;  //返回最第二小值
	return res;  
}
void CreatHFTree(HFTree* T) {
	int Min;
	int secondMin;
	int lenthMax = T->length * 2 - 1;  //哈夫曼树最大值
	for (int i = T->length;i < lenthMax;i++) {
		int* res = SelectMin(T);
		Min = res[0];
		secondMin = res[1];
		T->data[i].weight = T->data[Min].weight + T->data[secondMin].weight; //父节点权值
		T->data[i].lchild = Min;  T->data[i].rchild = secondMin; //父节点的 左右孩子值
		T->data[Min].parent = i; T->data[secondMin].parent = i;  //孩子结点parent值
		T->length++;
	}
}
int main() {
	int weight[4] = {1,2,3,4};
	HFTree* T = InitTree(weight,4);
	int* res = SelectMin(T);
	return 0;
}