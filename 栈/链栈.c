//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#define MAXSIZE 10           //�������Ԫ�ظ���
//typedef struct Stack {
//	int * top;        //ջ��ָ�� 
//	int * base;       //ջ��ָ��
//	int stacksize;         //ջ�����ռ�
//}Stack;
//
//void InitStack(Stack S) {  //��ʼ��
//	S.base = (Stack*)malloc(MAXSIZE * sizeof(int));//���ٿռ�Ϊ MAXSIZE
//	if (!S.base) {                    //ȷ�����ٿռ�ɹ�
//		printf("���ٿռ�ʧ��");
//	}
//	else {
//		S.base == S.top;
//	}
//}
//
////����
//Stack InsertStack(Stack S, int e) {
//	if (S.top - S.base == MAXSIZE) { //�ж�ջ�ռ��Ƿ���
//		printf("ջ�ռ���");
//	}
//	{
//		*S.top = e;           //ջ��ֵΪe
//		S.top++;             //ջ��ָ��+1  �ȼ���*S.top++=e;
//		return	 S;
//	}
//}
//
//	//ɾ��
//Stack DeletStack (Stack S) {
//		if (S.top == S.base) {    //�ж�ջΪ��
//			printf("ջΪ��");
//		}
//		else {
//			int e = 0;
//			S.top--;
//			e = *S.top;   //�ȼ��� e==*S.top--; �ȸ�ֵ��--		
//		}
//	}
//
//
//
//int main(){
//	Stack Q;
//	InitStack (Q); //��ʼ��ջ
//	DeletStack(Q);
//	return 0;
//}

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