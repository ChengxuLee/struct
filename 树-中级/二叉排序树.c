#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//�ݹ�����㷨
//BSTree SearchBST(BSTree T,int key) {
//	if (!T || T->data.key == key)return T; //�ݹ��������ΪTΪ�ջ�����ؼ�����ԭ�йؼ������
//	else if (T->data.key > key) return SearchBST(T->Rchild,key); //����������
//	else return SearchBST(T->Lchild, key);	//	����������
//}
//�ǵݹ�����㷨
//BSTree SearchBST(BSTree T, int key){
//	while (!T || T->data.key == key) {
//		if (T->data.key>key) {
//			T=T->Lchild;   //С�����������ϲ��ҡ�ָ������ƶ�
//		}
//		else
//		{
//			T=T->Rchild;  //�������������ϲ��ҡ�ָ������ƶ�
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
//	if (!T) {		//�ҵ�Ҫ����ĵط�
//		s = (BSTree)malloc(sizeof(BSTNode)); //���ٿռ佫sָ������
//		s->data = e;
//		s->Lchild = s->Rchild = NULL; //�²������Ҷ�ӽ�㣬�����Ҫ�ÿ�
//		T = s;                       //���ӽ������
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
//���������������㷨
typedef struct {
	int key;    //�ؼ������Ҫ������Ĺؼ��ֽ��жԱ�
	int otherinfo; //����������
}ElemType;
typedef struct BSTNode {
	ElemType data;          //������(���԰����ؼ��ֺ���������)
	struct BSTNode* Lchild, * Rchild;  //���Һ���ָ��
}BSTNode, * BSTree;

    //ɾ��ֻ��һ���ڵ��״��
Delete(BSTree T, ElemType e) {   //Ҷ�ӽ��
	if (T->Lchild==NULL&& T->Rchild == NULL) {
		BSTree p = T;
		T = NULL;     //TΪ��ͬʱ��Ϊ�����ã����Ҳ�ı���˫�׵�ָ��Ϊ��
		free(p);		//�ͷſռ䣬��ֹ��ΪҰָ��
	}
	else if(T->Lchild == NULL){  //ֻ���Һ���
		BSTree p = T;
		T = T->Rchild;      //ָ���Һ���
		free(p);
	}
	else if (T->Rchild == NULL) { //ֻ������
		BSTree p = T;
		T = T->Lchild;       //ָ������
		free(p);
	}
	else {     //������
		BSTree parent = T;
		BSTree pre = T->Lchild;
		while (pre->Rchild) {   //����ָ����������������
			parent = pre;       //��¼˫�׽��λ��
			pre = pre->Rchild;   //ָ�����ֵλ��
		}
		T->data = pre->data;
		if (parent !=T) {     // ���ֵ���Ǹ��������ӵ����
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
	if (!T) return 0;  //����ȫ��δ�ҵ���e��ȵĹؼ���
	else if (T->data.key == e.key) { Delete(T,e); }//�����ִ��ɾ������
	else if (T->data.key > e.key) { DeleteBST(T->Lchild, e); }//ִ��������
	else { DeleteBST(T->Rchild, e); }  //ִ��������
	return T;
}

int main() {
	BSTree T=(BSTree)malloc(sizeof(BSTNode));
	ElemType e;
	DeleteBST(T,e); //ɾ���㷨
}
