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

void DFS(Gragh* G, int j, int visited[]) { //找邻结点
	//起始节点
	printf("%c", G->Vertex[j]);
	visited[j] = 1;           //已访问的结点变为1
	//访问邻结点
	for (int i = 0;i < G->vernum;i++) {
		if (visited[i] = 0 && G->Edge[j][i] != 60) {  //有边且未被访问过
			DFS(G, j, visited);
		}
	}
}
void DfsGragh(Gragh* G, int n) {//深度优先遍历
	int visited[VERTEX_MAX];  //定义数组
	for (int i = 0;i < G->vernum;i++) {
		visited[i] = 0;                    //初始化
	}
	for (int j = 0;j < G->vernum;j++) {
		if (visited[j] == 0) {            //为0可以进行访问，此处循环表示跳到下一个结点
			DFS(G, j, visited);
		}
	}
	printf("\n");
	printf("*********************\n");
}