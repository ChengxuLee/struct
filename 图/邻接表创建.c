#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//�ڽӱ���������
typedef struct ArcNode {
	int adjvex;               //�ñ�ָ�򶥵��λ��
	struct ArcNode* nextarc; //ֻ������һ���ߵ�ָ��
	int info;
}ArcNode; //�ͱ���ص���Ϣ��Ȩֵ
#define MVnum 100  //��󶥵���
typedef struct VNode {  //��������
	char data; //������Ϣ
	ArcNode* firstar;  //ָ���һ�������ڸö���ıߵ�ָ��
}VNode, AdjList[MVnum];
typedef struct {
	AdjList vertices;  
	int vexnum,arcnum; //ͼ�ĵ�ǰ����ͱ���
}ALGraph;

//�����ڽӱ�
ALGraph* Creat(ALGraph* G ){
	printf("�����붥�����ͱ�����>");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for (int i = 0;i < G->vexnum;i++) {   //������������
		printf("�����붥����Ϣ��>");
		scanf("%c",&G->vertices[i].data);
		G->vertices[i].firstar = NULL;    //��ʼ��ָ����
	}
	for (int k = 0;k < G->arcnum;k++) {
		char v1, v2; int w; //v1��v2 Ϊ���㣬wΪȨֵ
		int x, y; //xyΪ�����±꣬�����е�λ��
		printf("�������k���߶�Ӧ���������㼰Ȩֵ:>");
		scanf("%c %c %d", &v1, &v2, &w);
		x = LocateVex(G, v1);
		y = LocateVex(G, v2);  //ȷ��v1��v2�ڱ��е�λ��
		ArcNode*p1= (ArcNode*)malloc(sizeof(ArcNode));  //����p1
		p1->adjvex = x;
		p1->info = w;
		p1->nextarc = G->vertices[k].firstar;  //ͷ�巨
		G->vertices[k].firstar = p1;
		ArcNode* p2= (ArcNode*)malloc(sizeof(ArcNode));  //����p2
		p2->adjvex = y;
		p2->info = w;
		p2->nextarc = G->vertices[k].firstar;  //ͷ�巨
		G->vertices[k].firstar = p2;
	}
	return G;
}
int LocateVex(ALGraph* G, char v) {   //ȷ��v1��v2�ڱ��е�λ��
	for (int i = 0;i < G->arcnum;i++) {
		if (G->vertices[i].data == v) {      // �������� �ҵ��붥����ȵ��������±�
			return i;
		}
	}
}
int main() {
	ALGraph* G=(ALGraph*)malloc(sizeof(ALGraph));
	Creat(G);
	return 0;
}