//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#define MAXSIZE 10           //定义最大元素个数
//typedef struct Stack {
//	int * top;        //栈顶指针 
//	int * base;       //栈底指针
//	int stacksize;         //栈的最大空间
//}Stack;
//
//void InitStack(Stack S) {  //初始化
//	S.base = (Stack*)malloc(MAXSIZE * sizeof(int));//开辟空间为 MAXSIZE
//	if (!S.base) {                    //确定开辟空间成功
//		printf("开辟空间失败");
//	}
//	else {
//		S.base == S.top;
//	}
//}
//
////插入
//Stack InsertStack(Stack S, int e) {
//	if (S.top - S.base == MAXSIZE) { //判断栈空间是否满
//		printf("栈空间满");
//	}
//	{
//		*S.top = e;           //栈顶值为e
//		S.top++;             //栈顶指针+1  等价于*S.top++=e;
//		return	 S;
//	}
//}
//
//	//删除
//Stack DeletStack (Stack S) {
//		if (S.top == S.base) {    //判断栈为空
//			printf("栈为空");
//		}
//		else {
//			int e = 0;
//			S.top--;
//			e = *S.top;   //等价于 e==*S.top--; 先赋值再--		
//		}
//	}
//
//
//
//int main(){
//	Stack Q;
//	InitStack (Q); //初始化栈
//	DeletStack(Q);
//	return 0;
//}

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