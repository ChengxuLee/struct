#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//二叉树先序遍历
typedef struct BiTree { //链式建立
	char data;
	struct BiTree* Lchild;
	struct BiTree* Rchild;  //左右孩子指针
}BiTree, * TNode;

TNode CreatBinaryTree(TNode T) {   //创建
	char ch;
	printf("请输入当前结点的值");
	scanf("%c", &ch);
	getchar();
	if (ch == '#') {
		T = NULL;      //节点为空
	}
	else {
		if (T = (TNode)malloc(sizeof(BiTree))) {  //开辟空间并检测是否成功
			T->data = ch;
			T->Lchild = CreatBinaryTree(T->Lchild);
			T->Rchild = CreatBinaryTree(T->Rchild)
		}
	}
	return T;
}
void PreOrderTraverse(TNode T)//二叉树的先序遍历
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->Lchild);
	PreOrderTraverse(T->Rchild);
}
void InOrderTraverse(TNode T)//二叉树的中序遍历
{
	if (T == NULL)
		return;
	InOrderTraverse(T->Lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->Rchild);
}
void PostOrderTraverse(TNode T)//二叉树的后序遍历
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->Lchild);
	PostOrderTraverse(T->Rchild);
	printf("%c ", T->data);
}
int main() {
	TNode T = (TNode)malloc(sizeof(BiTree));
	printf("请输入构建二叉树的序列");
	T = CreatBinaryTree(T);//构建二叉树
	PreOrderTraverse(T);//先序输出
	InOrderTraverse(T);//中序输出
	PostOrderTraverse(T);//后序输出
	return 0;
}
