#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define MAXSIZE 10           //�������Ԫ�ظ���
typedef struct stack {
	int data;                  //������         
	struct stack* next;       //ָ����    
}Stack;

void CreatStack(Stack* S) {
	Stack* top = (Stack*)malloc(sizeof(Stack));  //��̬���ٿռ�,����topָ��ÿռ��׵�ַ
	top->next = NULL;                           //ָ��ͷ���
	for (int i = 0;i < 5;i++) {
		Stack* p = (Stack*)malloc(sizeof(Stack));
		p->data = i;                      //��������ֵ
		p->next = top;
		top = p;
		printf("%d ", p->data);           //���ӽڵ㣬����top�ƶ�
	}
}

void InsertStack(Stack* S) {
	Stack* top = S;
	Stack* p = (Stack*)malloc(sizeof(Stack));
	if (p) {
		p->data = 1;            //������ֵ
		p->next = top;        //�½��ָ��top
		top = p;             //topָ��ջ��
	}
}


Stack* DeleteStack(Stack* S) {
	Stack* top = S;
	if (top) {
		int x = top->data;     //������ֵ
		Stack* p = top;        //pΪɾ����ָ�룬topָ����һ��������
		top = top->next       //top�ƶ�
			free(p);             //�ͷſռ�
	}
	return S;
}