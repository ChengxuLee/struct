#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//单链表头插法创建
typedef struct node
{
    int data;
    struct node* next;
}Node, * LinkList;//数据建立

LinkList create(LinkList L, int arr[], int  n)
{
    LinkList p;
    L = (LinkList)malloc(sizeof(Node));//为头节点开辟空间，并将头指针L指向头结点
    if (L == NULL) {                  //判断空间分配是否成功（不判断会报错）
        printf("内存分配不成功！\n");
    }
    else {
        L->next = NULL;                  //头结点指针域为空，空表判断
        for (int i = 0;i < 5;i++) {
            p = (LinkList)malloc(sizeof(Node));  //为普通结点开辟空间
            if (p == NULL) {
                printf("内存分配不成功！\n");//判断空间分配是否成功（不判断会报错）
            }
            else {
                p->data = arr[i];               //为结点设置数据域
                p->next = L->next;             //第一次为尾结点 后面为当前节点的next域指向后 
                                               //  一个节点
                L->next = p;                  //将当前节点与前一个节点相连 
            }
        }
    }   //判断空间分配是否成功（不判断会报错）对应上面L开辟的if
    return L;  //返回头指针 L
}


void print(LinkList q) {   //打印链表
    LinkList p;
    p = q->next;    //设置p为头结点
    while (p) {                     // if（p）等价if（p！=NULL）
        printf("%d  ", p->data);
        p = p->next;          //跳向下一个结点
    }

}

int main() {
    LinkList L = 0;
    LinkList q = 0;
    int arr[5] = { 1,2,3,4,5 }; //链表成员
    int n = 0;   //链表总共n个
    q = create(L, arr, n);       //单链表建立
    print(q); //单链表打印/遍历
    return 0;
}