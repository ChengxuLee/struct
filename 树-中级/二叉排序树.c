#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//递归查找算法
//BSTree SearchBST(BSTree T,int key) {
//	if (!T || T->data.key == key)return T; //递归结束条件为T为空或给定关键字与原有关键字相等
//	else if (T->data.key > key) return SearchBST(T->Rchild,key); //右子树查找
//	else return SearchBST(T->Lchild, key);	//	左子树查找
//}
//非递归查找算法
//BSTree SearchBST(BSTree T, int key){
//	while (!T || T->data.key == key) {
//		if (T->data.key>key) {
//			T=T->Lchild;   //小于在左子树上查找。指针向后移动
//		}
//		else
//		{
//			T=T->Rchild;  //大于在又子树上查找。指针向后移动
//		}
//	}
//	return T;
//}
// 
// 
// 
// BSTree InsertBST(BSTree T, ElemType e) {
//	BSTree s;
//	/*if (T->data == e) { return T; };*/
//	if (!T) {		//找到要插入的地方
//		s = (BSTree)malloc(sizeof(BSTNode)); //开辟空间将s指向这里
//		s->data = e;
//		s->Lchild = s->Rchild = NULL; //新插入的是叶子结点，因此需要置空
//		T = s;                       //连接结点与树
//	}
//	else if(T->data.key>e.key)
//	{
//		T->Lchild=InsertBST(T->Lchild,e);
//	}
//	else  {
//		T->Rchild=InsertBST(T->Rchild,e);
//	}
//	return T;
//}
//二叉排序树插入算法
typedef struct {
	int key;    //关键字项，需要与给定的关键字进行对比
	int otherinfo; //其他数据项
}ElemType;
typedef struct BSTNode {
	ElemType data;          //数据域(可以包含关键字和其他数据)
	struct BSTNode* Lchild, * Rchild;  //左右孩子指针
}BSTNode, * BSTree;

    //删除只有一个节点的状况
Delete(BSTree T, ElemType e) {   //叶子结点
	if (T->Lchild==NULL&& T->Rchild == NULL) {
		BSTree p = T;
		T = NULL;     //T为空同时因为是引用，因此也改变了双亲的指针为空
		free(p);		//释放空间，防止成为野指针
	}
	else if(T->Lchild == NULL){  //只有右孩子
		BSTree p = T;
		T = T->Rchild;      //指向右孩子
		free(p);
	}
	else if (T->Rchild == NULL) { //只有左孩子
		BSTree p = T;
		T = T->Lchild;       //指向左孩子
		free(p);
	}
	else {     //俩孩子
		BSTree parent = T;
		BSTree pre = T->Lchild;
		while (pre->Rchild) {   //不断指向右子树的右子树
			parent = pre;       //记录双亲结点位置
			pre = pre->Rchild;   //指向最大值位置
		}
		T->data = pre->data;
		if (parent !=T) {     // 最大值就是根结点的左孩子的情况
			parent->Rchild = pre->Lchild;
		}
		else
		{
			parent->Lchild = pre->Lchild;
			free(pre);
		}
	}
}









BSTree DeleteBST(BSTree T, ElemType e) {
	if (!T) return 0;  //遍历全部未找到与e相等的关键字
	else if (T->data.key == e.key) { Delete(T,e); }//相等则执行删除函数
	else if (T->data.key > e.key) { DeleteBST(T->Lchild, e); }//执行左子树
	else { DeleteBST(T->Rchild, e); }  //执行右子树
	return T;
}

int main() {
	BSTree T=(BSTree)malloc(sizeof(BSTNode));
	ElemType e;
	DeleteBST(T,e); //删除算法
}
