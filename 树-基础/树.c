#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//�������������
typedef struct BiTree { //��ʽ����
	char data;
	struct BiTree* Lchild;
	struct BiTree* Rchild;  //���Һ���ָ��
}BiTree, * TNode;

TNode CreatBinaryTree(TNode T) {   //����
	char ch;
	printf("�����뵱ǰ����ֵ");
	scanf("%c", &ch);
	getchar();
	if (ch == '#') {
		T = NULL;      //�ڵ�Ϊ��
	}
	else {
		if (T = (TNode)malloc(sizeof(BiTree))) {  //���ٿռ䲢����Ƿ�ɹ�
			T->data = ch;
			T->Lchild = CreatBinaryTree(T->Lchild);
			T->Rchild = CreatBinaryTree(T->Rchild)
		}
	}
	return T;
}
void PreOrderTraverse(TNode T)//���������������
{
	if (T == NULL)
		return;
	printf("%c ", T->data);
	PreOrderTraverse(T->Lchild);
	PreOrderTraverse(T->Rchild);
}
void InOrderTraverse(TNode T)//���������������
{
	if (T == NULL)
		return;
	InOrderTraverse(T->Lchild);
	printf("%c ", T->data);
	InOrderTraverse(T->Rchild);
}
void PostOrderTraverse(TNode T)//�������ĺ������
{
	if (T == NULL)
		return;
	PostOrderTraverse(T->Lchild);
	PostOrderTraverse(T->Rchild);
	printf("%c ", T->data);
}
int main() {
	TNode T = (TNode)malloc(sizeof(BiTree));
	printf("�����빹��������������");
	T = CreatBinaryTree(T);//����������
	PreOrderTraverse(T);//�������
	InOrderTraverse(T);//�������
	PostOrderTraverse(T);//�������
	return 0;
}
