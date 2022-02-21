#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define MAXSIZE 10           //定义最大元素个数
typedef struct stack {
	int data;                  //数据域         
	struct stack* next;       //指针域    
}Stack;

void CreatStack(Stack* S) {
	Stack* top = (Stack*)malloc(sizeof(Stack));  //动态开辟空间,并将top指向该空间首地址
	top->next = NULL;                           //指向头结点
	for (int i = 0;i < 5;i++) {
		Stack* p = (Stack*)malloc(sizeof(Stack));
		p->data = i;                      //给数据域赋值
		p->next = top;
		top = p;
		printf("%d ", p->data);           //连接节点，并将top移动
	}
}

void InsertStack(Stack* S) {
	Stack* top = S;
	Stack* p = (Stack*)malloc(sizeof(Stack));
	if (p) {
		p->data = 1;            //数据域赋值
		p->next = top;        //新结点指向top
		top = p;             //top指向栈顶
	}
}


Stack* DeleteStack(Stack* S) {
	Stack* top = S;
	if (top) {
		int x = top->data;     //数据域赋值
		Stack* p = top;        //p为删除的指针，top指向下一个数据域
		top = top->next       //top移动
			free(p);             //释放空间
	}
	return S;
}