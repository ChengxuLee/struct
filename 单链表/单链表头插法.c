#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//������ͷ�巨����
typedef struct node
{
    int data;
    struct node* next;
}Node, * LinkList;//���ݽ���

LinkList create(LinkList L, int arr[], int  n)
{
    LinkList p;
    L = (LinkList)malloc(sizeof(Node));//Ϊͷ�ڵ㿪�ٿռ䣬����ͷָ��Lָ��ͷ���
    if (L == NULL) {                  //�жϿռ�����Ƿ�ɹ������жϻᱨ��
        printf("�ڴ���䲻�ɹ���\n");
    }
    else {
        L->next = NULL;                  //ͷ���ָ����Ϊ�գ��ձ��ж�
        for (int i = 0;i < 5;i++) {
            p = (LinkList)malloc(sizeof(Node));  //Ϊ��ͨ��㿪�ٿռ�
            if (p == NULL) {
                printf("�ڴ���䲻�ɹ���\n");//�жϿռ�����Ƿ�ɹ������жϻᱨ��
            }
            else {
                p->data = arr[i];               //Ϊ�������������
                p->next = L->next;             //��һ��Ϊβ��� ����Ϊ��ǰ�ڵ��next��ָ��� 
                                               //  һ���ڵ�
                L->next = p;                  //����ǰ�ڵ���ǰһ���ڵ����� 
            }
        }
    }   //�жϿռ�����Ƿ�ɹ������жϻᱨ����Ӧ����L���ٵ�if
    return L;  //����ͷָ�� L
}


void print(LinkList q) {   //��ӡ����
    LinkList p;
    p = q->next;    //����pΪͷ���
    while (p) {                     // if��p���ȼ�if��p��=NULL��
        printf("%d  ", p->data);
        p = p->next;          //������һ�����
    }

}

int main() {
    LinkList L = 0;
    LinkList q = 0;
    int arr[5] = { 1,2,3,4,5 }; //�����Ա
    int n = 0;   //�����ܹ�n��
    q = create(L, arr, n);       //��������
    print(q); //�������ӡ/����
    return 0;
}