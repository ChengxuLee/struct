#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



//ɾ�Ĳ�

////������ֵΪe��jλ��

void FindList(LinkList L, int j, int e) {//������ֵΪe��jλ��
    LinkList p = L->next;j = 1;             //j��0��1��ʼȡ����p��ͷ��㻹��ͷָ�뿪ʼ
    if (p == NULL) { printf("������Ԫ��"); } //�ж������Ƿ����Ԫ��
    else {
        while (p && p->data != e) {    //p��Ϊ�������ݲ�����e
            p = p->next;                //ָ����һ�����
            j++;                       //ָ����һ�����
        }
        if (p == NULL && p->data != e) {        //���ϴ�ѭ���˳������������
            printf("�������в�����Ԫ��%d", e);    //�ߵ�β���δ����e  
        }
        else {
            printf("�ҵ���Ԫ���ڵ�%dλ��", j);   //�ҵ���Ԫ��e
        }
    }
    free(p);

}

//ɾ����ֵ����
LinkList DeleteList(LinkList q, int j) {      //ɾ������j��ֵ
    LinkList p = q;                        //����pΪͷ���
    LinkList w = p->next;                //����wΪp��ǰһ���ڵ�
    while (w && w->data != j) {             //w��Ϊ����w�����������j
        p = w;
        w = w->next;                  //������Ϊ��p��w�������������
    }
    if (w->data == j) {
        p->next = w->next;  //ǰ��pָ��w�ĺ�̽��
        free(w);           //�ͷſռ�
    }
    else {
        printf("�б��ҹ�δ����ֵ%d", j);
    }
    return q;
}

//ɾ���������

LinkList DeleteList(LinkList q, int j) {
    LinkList t = q;                        //tΪǰ����wΪ��ǰ���
    LinkList w = t->next; int count = 1;  //��count������
    if (w == NULL) {                       //�ж�ͷ����next���Ƿ�Ϊ��
        printf("�����Ѿ�����");
    }
    else {
        while (w && count < j) {        //w�ǿ��ҵ�ǰ���С��������ֵ
            t = w;
            w = w->next;             //����
            count++;
        }

        if (w && count == j) {      //��ǰλ����������ֵ�����ɾ��
            t->next = w->next;
            free(w);
        }
        else if (w == NULL) {           //��wΪ��ʱ����ǰ����next��ָ��β���  
            printf("����ֵ����ȷ");   //��ʾ�߱��б�Ϊ�ҵ���ֵ
        }

    }
    return q;
}


////�ڵ�jλ����e
LinkList AddList(LinkList q, int j, int e) { //�ڵ�jλ����e
    LinkList w = q->next;int count = 1;
    while (w && count < j) {
        w = w->next;
        count++;
    }
    if (w && count == j) {
        if (create == NULL) {
            return NULL;
        }
        LinkList create = (LinkList)malloc(sizeof(node));    //������Ҫ�����µĿռ�
        create->data = e;
        create->next = w->next;
        w->next = create;
    }
    else if (w == NULL) {
        printf("�������ݴ���");
    }
    return q;
}

//��  ��jλ��ֵ�޸�
LinkList ChangeList(LinkList q, int j, int e) { //��jλ��ֵ�޸�
    LinkList Change = q->next;int count = 1;
    while (Change && count < j) {
        Change = Change->next;
        count++;
    }
    if (Change && count == j) {
        Change->data = e;              //��data����ֵ��Ϊ������ֵ
    }
    else if (Change == NULL) {
        printf("λ�ò�����");
    }
    return q;
}