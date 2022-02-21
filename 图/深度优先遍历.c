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

void DFS(Gragh* G, int j, int visited[]) { //���ڽ��
	//��ʼ�ڵ�
	printf("%c", G->Vertex[j]);
	visited[j] = 1;           //�ѷ��ʵĽ���Ϊ1
	//�����ڽ��
	for (int i = 0;i < G->vernum;i++) {
		if (visited[i] = 0 && G->Edge[j][i] != 60) {  //�б���δ�����ʹ�
			DFS(G, j, visited);
		}
	}
}
void DfsGragh(Gragh* G, int n) {//������ȱ���
	int visited[VERTEX_MAX];  //��������
	for (int i = 0;i < G->vernum;i++) {
		visited[i] = 0;                    //��ʼ��
	}
	for (int j = 0;j < G->vernum;j++) {
		if (visited[j] == 0) {            //Ϊ0���Խ��з��ʣ��˴�ѭ����ʾ������һ�����
			DFS(G, j, visited);
		}
	}
	printf("\n");
	printf("*********************\n");
}