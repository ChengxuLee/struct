#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



//删改查

////查找数值为e在j位置

void FindList(LinkList L, int j, int e) {//查找数值为e在j位置
    LinkList p = L->next;j = 1;             //j从0或1开始取决于p从头结点还是头指针开始
    if (p == NULL) { printf("链表无元素"); } //判断链表是否包含元素
    else {
        while (p && p->data != e) {    //p不为空且数据不等于e
            p = p->next;                //指向下一个结点
            j++;                       //指向下一个结点
        }
        if (p == NULL && p->data != e) {        //经上次循环退出后有两个结果
            printf("该链表中不包含元素%d", e);    //走到尾结点未发现e  
        }
        else {
            printf("找到了元素在第%d位置", j);   //找到了元素e
        }
    }
    free(p);

}

//删除按值查找
LinkList DeleteList(LinkList q, int j) {      //删除等于j的值
    LinkList p = q;                        //设置p为头结点
    LinkList w = p->next;                //设置w为p的前一个节点
    while (w && w->data != j) {             //w不为空且w的数据域等于j
        p = w;
        w = w->next;                  //此两步为将p和w跳向下两个结点
    }
    if (w->data == j) {
        p->next = w->next;  //前驱p指向w的后继结点
        free(w);           //释放空间
    }
    else {
        printf("列表找过未发现值%d", j);
    }
    return q;
}

//删除按序查找

LinkList DeleteList(LinkList q, int j) {
    LinkList t = q;                        //t为前驱，w为当前结点
    LinkList w = t->next; int count = 1;  //以count来计数
    if (w == NULL) {                       //判断头结点的next域是否为空
        printf("链表已经空了");
    }
    else {
        while (w && count < j) {        //w非空且当前结点小于输入数值
            t = w;
            w = w->next;             //后移
            count++;
        }

        if (w && count == j) {      //当前位置与输入数值相等则删除
            t->next = w->next;
            free(w);
        }
        else if (w == NULL) {           //当w为空时代表前驱的next域指向尾结点  
            printf("输入值不正确");   //表示走遍列表并为找到数值
        }

    }
    return q;
}


////在第j位插入e
LinkList AddList(LinkList q, int j, int e) { //在第j位插入e
    LinkList w = q->next;int count = 1;
    while (w && count < j) {
        w = w->next;
        count++;
    }
    if (w && count == j) {
        if (create == NULL) {
            return NULL;
        }
        LinkList create = (LinkList)malloc(sizeof(node));    //插入需要创建新的空间
        create->data = e;
        create->next = w->next;
        w->next = create;
    }
    else if (w == NULL) {
        printf("输入数据错误");
    }
    return q;
}

//改  第j位的值修改
LinkList ChangeList(LinkList q, int j, int e) { //第j位的值修改
    LinkList Change = q->next;int count = 1;
    while (Change && count < j) {
        Change = Change->next;
        count++;
    }
    if (Change && count == j) {
        Change->data = e;              //将data域数值改为输入数值
    }
    else if (Change == NULL) {
        printf("位置不合理");
    }
    return q;
}