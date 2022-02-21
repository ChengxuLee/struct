#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
//邻接矩阵创建无向网
#define Maxint 32767		//表示无穷大即∞
#define VertexMax 100		//顶点最大值
typedef struct Gragh {
	char Vertex[VertexMax]; //顶点数组
	int Edge[VertexMax][VertexMax];  //边表
	int vernum, arcnum;     //当前顶点和边数目
} Gragh;
Gragh* CreatGragh( Gragh* G ) {
	printf("请输入顶点个数，边个数:>");
	scanf("%d %d",&G->vernum,&G->arcnum);    
	for (int i = 0;i < G->Vertex;i++) {  //依次输入顶点信息即数组Vertex
		printf("请输入顶点信息：>");
		scanf("%c",&G->Vertex[i]);
	}
	for (int j = 0;j < G->Vertex;j++) {      //初始化邻接表
		for (int i = 0;i < G->Vertex;i++)  
		{
			G->Edge[i][j] = Maxint;       //起始权值都是无穷大
		}
	}
	//构建网
	for (int k = 0;k < G->arcnum;k++) {
		char v1, v2; int w; //v1，v2 为顶点，w为权值
		int x,y; //xy为数组下标，即表中的位置
		printf("请输入第k条边对应的两个顶点及权值:>");
		scanf("%c %c %d",&v1,&v2,&w);
		x = LocateVex(G,v1);
		y = LocateVex(G,v2);  //确定v1，v2在表中的位置
		G->Edge[x][y] = w;
		G->Edge[y][x] = w;  //邻接矩阵沿对角线对称
	}
	return G;
}
int LocateVex(Gragh *G,char v) {   //确定v1，v2在表中的位置
	for (int i = 0;i < G->vernum;i++) {
		if (G->Vertex[i]==v) {      // 遍历数组 找到与顶点相等的数组中下标
			return i;
		}
	}
}
