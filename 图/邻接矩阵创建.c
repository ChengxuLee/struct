#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
//�ڽӾ��󴴽�������
#define Maxint 32767		//��ʾ����󼴡�
#define VertexMax 100		//�������ֵ
typedef struct Gragh {
	char Vertex[VertexMax]; //��������
	int Edge[VertexMax][VertexMax];  //�߱�
	int vernum, arcnum;     //��ǰ����ͱ���Ŀ
} Gragh;
Gragh* CreatGragh( Gragh* G ) {
	printf("�����붥��������߸���:>");
	scanf("%d %d",&G->vernum,&G->arcnum);    
	for (int i = 0;i < G->Vertex;i++) {  //�������붥����Ϣ������Vertex
		printf("�����붥����Ϣ��>");
		scanf("%c",&G->Vertex[i]);
	}
	for (int j = 0;j < G->Vertex;j++) {      //��ʼ���ڽӱ�
		for (int i = 0;i < G->Vertex;i++)  
		{
			G->Edge[i][j] = Maxint;       //��ʼȨֵ���������
		}
	}
	//������
	for (int k = 0;k < G->arcnum;k++) {
		char v1, v2; int w; //v1��v2 Ϊ���㣬wΪȨֵ
		int x,y; //xyΪ�����±꣬�����е�λ��
		printf("�������k���߶�Ӧ���������㼰Ȩֵ:>");
		scanf("%c %c %d",&v1,&v2,&w);
		x = LocateVex(G,v1);
		y = LocateVex(G,v2);  //ȷ��v1��v2�ڱ��е�λ��
		G->Edge[x][y] = w;
		G->Edge[y][x] = w;  //�ڽӾ����ضԽ��߶Գ�
	}
	return G;
}
int LocateVex(Gragh *G,char v) {   //ȷ��v1��v2�ڱ��е�λ��
	for (int i = 0;i < G->vernum;i++) {
		if (G->Vertex[i]==v) {      // �������� �ҵ��붥����ȵ��������±�
			return i;
		}
	}
}
