#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//����ƽ�������
typedef struct AVLNode {
	int data;
	int height;        //����  �߶�   ���Һ���
	struct AVLNode* lchild;
	struct AVLNode *rchild;
}AVLNode,*AVLTree;
int getHeight(AVLTree node) {
	return node ? node->height : 0;  //��ֵ����ֵ û��ֵ������
}
int max(int a, int b) {
	return a > b ? a : b;
}
void Left_Left(AVLTree node, AVLTree*root){
	AVLTree tmp = node->lchild;
	node->lchild = tmp->rchild;
	tmp->rchild = node;
	node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1; //�����ֵ
	tmp->height = max(getHeight(tmp->lchild), getHeight(tmp->rchild)) + 1;
	*root = tmp;
}

void Right_Right(AVLTree node, AVLTree* root){
	AVLTree tmp = node->rchild; 
	node->rchild = tmp->lchild;
	tmp->lchild = node;
	node->height = max(getHeight(node->lchild), getHeight(node->rchild))+1; //�����ֵ
	tmp->height = max(getHeight(tmp->lchild), getHeight(tmp->rchild)) + 1; 
	*root = tmp;
}
void Inserte(AVLTree* T,int data){
	if (*T==NULL) {
		*T = (AVLTree)malloc(sizeof(AVLNode));
		(*T)->data = data;
		(*T)->height = 0;
		(*T)->lchild =NULL;
		(*T)->rchild = NULL;
	}
	else if(data<(*T)->data){
		Inserte(&(*T)->lchild,data);
		//�ж�ƽ�������Ƿ����
		//������������ĸ߶�
		int Lheight = getHeight((*T)->lchild); //��ȡ�������߶�
		int Rheight = getHeight((*T)->rchild); //��ȡ�������߶�
		//�жϸ߶Ȳ� LL LR
		if (Rheight- Lheight==2) {
		if (data< (*T)->lchild->data) {
			//LL����
			Left_Left(*T,T);
		}else{
			//LR����
			Right_Right((*T)->lchild,&(*T)->lchild);
			Left_Left(*T, T);
			
		}
	}
	}
	else if (data > (*T)->data) {
		Inserte(&(*T)->rchild, data);
		int Lheight = getHeight((*T)->lchild); //��ȡ�������߶�
		int Rheight = getHeight((*T)->rchild); //��ȡ�������߶�
		//�жϸ߶Ȳ� RR RL
		if (Rheight - Lheight == 2) {
			if (data > (*T)->rchild->data) {
				//RR����
				Right_Right(*T, T);
			}
			else {
				//RL����
				Left_Left((*T)->rchild, &(*T)->rchild);
				Right_Right(*T, T);
			}
		}
	}
	(*T)->height = max(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;
}
void preOrder(AVLTree T) {
	if (T) {
		printf("%d  ", T->data);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

int main (){
	AVLTree T=NULL;
	int data[6] = {1,2,3,4,6,7};
	for (int i = 0;i < 6;i++) {
		Inserte(&T,data[i]);
	}
	preOrder(T);//�������
return 0;
}