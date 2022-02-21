#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
typedef struct Qnode {
	int data[5];               //存放指针front，rear
	struct Qnode *next;          //与链表相似 
}Qnode, * QueuePtr;
typedef struct {
	QueuePtr front;        //头指针
	QueuePtr rear;        //尾指针
}LinkQueue;

//初始化
LinkQueue InitQueue(LinkQueue Q) {
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(Qnode));
	Q.front->next = NULL;
	return Q;
}

//创建
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


//删除
void DeleteQueue(LinkQueue Q) {
	if (Q.front==Q.rear) {
		printf("空了");
	}
	else {
		QueuePtr p = Q.front->next;   //p为首元结点 即要删除的节点
		int e = *p->data;              //存下要删除的地址
		Q.front->next = p->next;      
		if (Q.rear==p) { Q.front = Q.rear; }  //如果只有尾结点一个元素
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