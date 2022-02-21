#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
typedef struct Qnode {
	int data[5];               //���ָ��front��rear
	struct Qnode *next;          //���������� 
}Qnode, * QueuePtr;
typedef struct {
	QueuePtr front;        //ͷָ��
	QueuePtr rear;        //βָ��
}LinkQueue;

//��ʼ��
LinkQueue InitQueue(LinkQueue Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Qnode));
	Q.front->next = NULL;
	return Q;
}

//����
LinkQueue CreatQueue(LinkQueue Q,int arr[]) {
	for (int i = 0;i <5;i++) {
		QueuePtr p = (QueuePtr)malloc(sizeof(Qnode));
		p->data[i] = arr[i];
		p->next = NULL;
		Q.rear->next= p;
		Q.rear = p;
		printf("%d ",p->data[i]);
	}
	return Q;
}


//ɾ��
void DeleteQueue(LinkQueue Q) {
	if (Q.front==Q.rear) {
		printf("����");
	}
	else {
		QueuePtr p = Q.front->next;   //pΪ��Ԫ��� ��Ҫɾ���Ľڵ�
		int e = *p->data;              //����Ҫɾ���ĵ�ַ
		Q.front->next = p->next;      
		if (Q.rear==p) { Q.front = Q.rear; }  //���ֻ��β���һ��Ԫ��
	}
}

int main() {
	int arr[5] = { 1,2,3,5,9 };
	LinkQueue Q = { 0 };
	LinkQueue Q1 = InitQueue(Q);
	LinkQueue Q2= CreatQueue(Q1,arr);
	DeleteQueue(Q2);

	return 0;
}