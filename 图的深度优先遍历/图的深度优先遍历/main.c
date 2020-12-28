#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct 
{
	char vertex[20];         //��������
	int arcs[20][20];        //�ڽӾ���
	int vexnum;              //������
	int arcnum;              //����
}AdjMatrix;

int LocateVertex(AdjMatrix *G, char v)            //�Ҷ���λ��
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
		printf("�����ڸö��㣡");
		return 0;
	}
}
void CreatGraph(AdjMatrix *G)
{
	char v1, v2;
	printf("�����붥�����ͻ�����");
	scanf("%d %d",&G->vexnum,&G->arcnum);
	for (int i = 0; i < G->vexnum; i++)            //���ڽӾ����ʼ��Ϊ0
	{
		for (int j = 0; j < G->vexnum; j++)
		{
			G->arcs[i][j] = 0;
		}
	}
	
	for (int i = 0; i < G->vexnum; i++)           //��������붨������
	{
		printf("�����붥��:");
		scanf(" %c",&G->vertex[i]);
	}
	
	for (int k = 0; k < G->arcnum; k++)           //����һ��������������
	{
		printf("������һ�������������㣺");
		scanf(" %c %c",&v1,&v2);
		int i = LocateVertex(G, v1);              //�Ҹö����ڶ��������е�λ��
		int j = LocateVertex(G, v2);
		G->arcs[i][j] = 1;                        //���ڽӾ����ж�Ӧ��λ���޸�
		G->arcs[j][i] = 1;                        //����ͼ�ڽӾ���Ϊ�Գƾ���
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