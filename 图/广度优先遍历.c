#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MVnum 100    //��󶨵�����
typedef struct ArcNode {   //��
	int adjvex;
	int info;	         //�����Ȩֵ
	struct ArcNode* nextstar;  //ָ����һ�����
}ArcNode;

typedef struct VNode { //��������
	char data;
	struct ArcNode* firststar;  //ָ��
}VNode, AdjList[MVnum];

typedef struct { //����ͼ
	AdjList vertices;
	int vernum, arcnum;
}ALGragh;

typedef struct Queue {   //ѭ������
	char data;
	int front, rear;  //�����±�
}Queue;

//�����ڽӱ�
ALGragh* CreatALGragh(ALGragh* G) {
	printf("�����붥������ͱ���:");
	scanf("%d %d", &G->vernum, &G->arcnum);  //���붥��ͱ���
	printf("�����붥������:");
	scanf("%s", &G->vertices->data);      //��������
	for (int i = 0;i < G->arcnum;i++) {	//�ߺͶ�Ӧ�Ķ���
		int x, y, w;  //x,y��v1��v2��Ӧλ�ã�w��Ȩֵ
		char v1, v2;
		printf("�������%d���ߵ�Ȩֵ����Ӧ�Ķ���:", i + 1);
		scanf("%d %c %c", &w, &v1, &v2);
		x = Locate(G, v1);  //ȷ��λ��
		y = Locate(G,v2);
		ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = x;
		p1->info = w;			//��һ����
		p1->nextstar = G->vertices[i].firststar;
		G->vertices[i].firststar= p1;
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = y;
		p2->info = w;			//�ڶ�����
		p2->nextstar = G->vertices[i].firststar;
		G->vertices[i].firststar = p1;
	}
	return G;
}
//������ȱ���
int visited[10];
void BFS(ALGragh* G,int i) { //������ȱ���
	ArcNode* p;
	Queue q;
	InitQueue(G); //��ʼ��ѭ������ 
	printf("%c",G->vertices[i].data);  //1.��ӡ��һ����㲢���
	visited[i] = 1;
	IntoQueue(G);    //���
	while (!QueueEmply(&q)) {
		p = G->vertices[i].firststar;  //pָ�򶥵����飬����++
		DeQueue(&q, &i);        //���в�Ϊ�������
		while (p) {       //���鲻Ϊ������б���
			if (visited[p->adjvex] == 0) {  //δ����
				printf("%c", G->vertices[p->adjvex].data);
				visited[p->adjvex] = 1;            //���ʹ�Ϊ1
				IntoQueue(G);    //���
			}
			p = p->nextstar;    //ָ��������һ��Ԫ��
		}
	}
}

void BFSGragh(ALGragh* G) {
	for (int i = 0;i < G->vernum;i++) {
		visited[i] = 0;      //��ʼ������
	}
	for (int i = 0;i < G->vernum;i++) {
		if (visited[i] = 0) {    //δ���ʹ������
			BFS(G, i);
		}
	}
}


int Locate(ALGragh* G,char v) {
	for (int i = 0;i < G->vernum;i++) {
		if (G->vertices[i].data==v) {
			return i;
		}
	}
	return -1;
}
int main() {
	ALGragh* G=(ALGragh*)malloc(sizeof(ALGragh));
	CreatALGragh(G);
	BFSGragh(G);
	return 0;
}