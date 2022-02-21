#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//构建平衡二叉树
typedef struct AVLNode {
	int data;
	int height;        //数据  高度   左右孩子
	struct AVLNode* lchild;
	struct AVLNode *rchild;
}AVLNode,*AVLTree;
int getHeight(AVLTree node) {
	return node ? node->height : 0;  //有值返回值 没有值返回零
}
int max(int a, int b) {
	return a > b ? a : b;
}
void Left_Left(AVLTree node, AVLTree*root){
	AVLTree tmp = node->lchild;
	node->lchild = tmp->rchild;
	tmp->rchild = node;
	node->height = max(getHeight(node->lchild), getHeight(node->rchild)) + 1; //求最大值
	tmp->height = max(getHeight(tmp->lchild), getHeight(tmp->rchild)) + 1;
	*root = tmp;
}

void Right_Right(AVLTree node, AVLTree* root){
	AVLTree tmp = node->rchild; 
	node->rchild = tmp->lchild;
	tmp->lchild = node;
	node->height = max(getHeight(node->lchild), getHeight(node->rchild))+1; //求最大值
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
		//判断平衡因子是否合理
		//求出左右子树的高度
		int Lheight = getHeight((*T)->lchild); //获取左子树高度
		int Rheight = getHeight((*T)->rchild); //获取右子树高度
		//判断高度差 LL LR
		if (Rheight- Lheight==2) {
		if (data< (*T)->lchild->data) {
			//LL调整
			Left_Left(*T,T);
		}else{
			//LR调整
			Right_Right((*T)->lchild,&(*T)->lchild);
			Left_Left(*T, T);
			
		}
	}
	}
	else if (data > (*T)->data) {
		Inserte(&(*T)->rchild, data);
		int Lheight = getHeight((*T)->lchild); //获取左子树高度
		int Rheight = getHeight((*T)->rchild); //获取右子树高度
		//判断高度差 RR RL
		if (Rheight - Lheight == 2) {
			if (data > (*T)->rchild->data) {
				//RR调整
				Right_Right(*T, T);
			}
			else {
				//RL调整
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
	preOrder(T);//先序遍历
return 0;
}