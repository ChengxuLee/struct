#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MVnum 100    //最大定点数量
typedef struct ArcNode {   //弧
	int adjvex;
	int info;	         //顶点和权值
	struct ArcNode* nextstar;  //指向下一个结点
}ArcNode;

typedef struct VNode { //顶点数组
	char data;
	struct ArcNode* firststar;  //指针
}VNode, AdjList[MVnum];

typedef struct { //无向图
	AdjList vertices;
	int vernum, arcnum;
}ALGragh;

typedef struct Queue {   //循环队列
	char data;
	int front, rear;  //数组下标
}Queue;

//创建邻接表
ALGragh* CreatALGragh(ALGragh* G) {
	printf("请输入顶点个数和边数:");
	scanf("%d %d", &G->vernum, &G->arcnum);  //输入顶点和边数
	printf("请输入顶点内容:");
	scanf("%s", &G->vertices->data);      //顶点内容
	for (int i = 0;i < G->arcnum;i++) {	//边和对应的顶点
		int x, y, w;  //x,y是v1，v2对应位置，w是权值
		char v1, v2;
		printf("请输入第%d条边的权值及对应的顶点:", i + 1);
		scanf("%d %c %c", &w, &v1, &v2);
		x = Locate(G, v1);  //确定位置
		y = Locate(G,v2);
		ArcNode* p1 = (ArcNode*)malloc(sizeof(ArcNode));
		p1->adjvex = x;
		p1->info = w;			//第一条边
		p1->nextstar = G->vertices[i].firststar;
		G->vertices[i].firststar= p1;
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = y;
		p2->info = w;			//第二条边
		p2->nextstar = G->vertices[i].firststar;
		G->vertices[i].firststar = p1;
	}
	return G;
}
//广度优先遍历
int visited[10];
void BFS(ALGragh* G,int i) { //广度优先遍历
	ArcNode* p;
	Queue q;
	InitQueue(G); //初始化循环队列 
	printf("%c",G->vertices[i].data);  //1.打印第一个结点并入队
	visited[i] = 1;
	IntoQueue(G);    //入队
	while (!QueueEmply(&q)) {
		p = G->vertices[i].firststar;  //p指向顶点数组，后面++
		DeQueue(&q, &i);        //队列不为空则出队
		while (p) {       //数组不为空则进行遍历
			if (visited[p->adjvex] == 0) {  //未访问
				printf("%c", G->vertices[p->adjvex].data);
				visited[p->adjvex] = 1;            //访问过为1
				IntoQueue(G);    //入队
			}
			p = p->nextstar;    //指向数组下一个元素
		}
	}
}

void BFSGragh(ALGragh* G) {
	for (int i = 0;i < G->vernum;i++) {
		visited[i] = 0;      //初始化数组
	}
	for (int i = 0;i < G->vernum;i++) {
		if (visited[i] = 0) {    //未访问过则遍历
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