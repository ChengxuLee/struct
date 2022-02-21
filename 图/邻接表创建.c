#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
//邻接表创建无向网
typedef struct ArcNode {
	int adjvex;               //该边指向顶点的位置
	struct ArcNode* nextarc; //只需向下一条边的指针
	int info;
}ArcNode; //和边相关的信息，权值
#define MVnum 100  //最大顶点数
typedef struct VNode {  //顶点数组
	char data; //顶点信息
	ArcNode* firstar;  //指向第一条依附在该顶点的边的指针
}VNode, AdjList[MVnum];
typedef struct {
	AdjList vertices;  
	int vexnum,arcnum; //图的当前顶点和边数
}ALGraph;

//建立邻接表
ALGraph* Creat(ALGraph* G ){
	printf("请输入顶点数和边数：>");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for (int i = 0;i < G->vexnum;i++) {   //构建顶点数组
		printf("请输入顶点信息：>");
		scanf("%c",&G->vertices[i].data);
		G->vertices[i].firstar = NULL;    //初始化指针域
	}
	for (int k = 0;k < G->arcnum;k++) {
		char v1, v2; int w; //v1，v2 为顶点，w为权值
		int x, y; //xy为数组下标，即表中的位置
		printf("请输入第k条边对应的两个顶点及权值:>");
		scanf("%c %c %d", &v1, &v2, &w);
		x = LocateVex(G, v1);
		y = LocateVex(G, v2);  //确定v1，v2在表中的位置
		ArcNode*p1= (ArcNode*)malloc(sizeof(ArcNode));  //插入p1
		p1->adjvex = x;
		p1->info = w;
		p1->nextarc = G->vertices[k].firstar;  //头插法
		G->vertices[k].firstar = p1;
		ArcNode* p2= (ArcNode*)malloc(sizeof(ArcNode));  //插入p2
		p2->adjvex = y;
		p2->info = w;
		p2->nextarc = G->vertices[k].firstar;  //头插法
		G->vertices[k].firstar = p2;
	}
	return G;
}
int LocateVex(ALGraph* G, char v) {   //确定v1，v2在表中的位置
	for (int i = 0;i < G->arcnum;i++) {
		if (G->vertices[i].data == v) {      // 遍历数组 找到与顶点相等的数组中下标
			return i;
		}
	}
}
int main() {
	ALGraph* G=(ALGraph*)malloc(sizeof(ALGraph));
	Creat(G);
	return 0;
}