#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct 
{
	char vertex[20];         //定点向量
	int arcs[20][20];        //邻接矩阵
	int vexnum;              //顶点数
	int arcnum;              //弧数
}AdjMatrix;

int LocateVertex(AdjMatrix *G, char v)            //找顶点位置
{
	int k;
	for (k = 0; k < G->vexnum; k++)
	{
		if (G->vertex[k] == v)
		{
			return k;
		}
	}
	if (k = G->vexnum)
	{
		printf("不存在该顶点！");
		return 0;
	}
}
void CreatGraph(AdjMatrix *G)
{
	char v1, v2;
	printf("请输入顶点数和弧数：");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for (int i = 0; i < G->vexnum; i++)            //将邻接矩阵初始化为0
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	
	for (int i = 0; i < G->vexnum; i++)           //将顶点存入定点向量
	{
		printf("请输入顶点:");
		scanf(" %c",&G->vertex[i]);
	}
	
	for (int k = 0; k < G->arcnum; k++)           //输入一条弧的两个顶点
	{
		printf("请输入一条弧的两个顶点：");
		scanf(" %c %c",&v1,&v2);
		int i = LocateVertex(G, v1);              //找该顶点在定点向量中的位置
		int j = LocateVertex(G, v2);
		G->arcs[i][j] = 1;                        //将邻接矩阵中对应的位置修改
		G->arcs[j][i] = 1;                        //无向图邻接矩阵为对称矩阵
	}
}
void DepthFirstSearch(AdjMatrix G,int i,int visited[])
{
	printf(" %c",G.vertex[i]);
	visited[i] = 1;
	for (int j = 0; j < G.vexnum; j++)
	{
		if (!visited[j]&&G.arcs[i][j]==1)
		{
			DepthFirstSearch(G, j, visited);
		}
	}

}
void TraverseGraph(AdjMatrix G)
{
	int visited[20];
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}
	for(int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			DepthFirstSearch(G,i,visited);
		}
	}
}
int main()
{
	AdjMatrix G;
	CreatGraph(&G);
	TraverseGraph(G);
	system("pause");
	return 0;
}