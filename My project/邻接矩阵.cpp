#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
typedef int ElemType;
#define OK 1
#define ERROR 0
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int Status;
typedef struct
{
	ElemType **a;
	int n;
	int e;
	ElemType noEdge;
}mGraph;
Status Init(mGraph *mg, int nSize, ElemType noEdgeValue)
{
	int i, j;
	mg->n = nSize;
	mg->e = 0;
	mg->noEdge = noEdgeValue;
	mg->a = (ElemType**)malloc(nSize * sizeof(ElemType*));
	if (!mg->a)
		return ERROR;
	for (i = 0; i<mg->n; i++)
	{
		mg->a[i] = (ElemType*)malloc(nSize * sizeof(ElemType));
		for (j = 0; j<mg->n; j++) mg->a[i][j] = mg->noEdge;
		mg->a[i][j] = 0;
	}
	return OK;
}
void Destroy(mGraph *mg)
{
	int i;
	for (i = 0; i<mg->n; i++)free(mg->a[i]);
	free(mg->a);
}
Status Exist(mGraph *mg, int u, int v)
{
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v || mg->a[u][v] == mg->noEdge)
		return ERROR;
	return OK;
}
Status Insert(mGraph *mg, int u, int v,int w)
{
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)return ERROR;
	if (mg->a[u][v] != mg->noEdge)return Duplicate;
	mg->a[u][v] = w;
	mg->e++;
	return OK;
}
Status Remove(mGraph *mg, int u, int v)
{
	if (u<0 || v<0 || u>mg->n - 1 || v>mg->n - 1 || u == v)return ERROR;
	if (mg->a[u][v] == mg->noEdge)return NotPresent;
	mg->a[u][v] = mg->noEdge;
	mg->e--;
	return OK;
}
void DFS(int i, int visited[], mGraph *g)
{
    printf("%d", i);
	visited[i] = 1;
	for (int j=0; j < g->n; j++)
		if (g->a[i][j] != g->noEdge && !visited[j])
			DFS(j, visited, g);
}
void DFSmGraph(mGraph *g)
{
	int i;
	int *visited = (int*)malloc(g->n * sizeof(int));
	for (i = 0; i<g->n; i++)
		visited[i] = 0;
	for (i = 0; i<g->n; i++)
		if (!visited[i])DFS(i,visited,g);
	free(visited);
}
/*宽度优先遍历*/
void BFS(int v, int visited[], mGraph g)
{
	int i;
	queue<int> q;
	visited[v] = 1;
	printf("%d ", v);
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (i = 0; i<g.n; i++)
		{
			if (!visited[v])
			{
				visited[v] = 1;
				printf("%d ", v);
				q.push(v);
			}
		}
	}
}
void BFSGraph(mGraph g)
{
	int i;
	int *visited = (int*)malloc(g.n * sizeof(int));
	for (i = 0; i<g.n; i++)
		visited[i] = 0;
	for (i = 0; i<g.n; i++)
	{
		if (!visited[i])
			BFS(i, visited, g);
	}
	free(visited);
}

void print(mGraph *g)
{
	int i, j,k=0;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
		{
			printf("%d", g->a[i][j]);
			k++;
			if ((k%(g->n))==0)
				printf("\n");
		}

}

int main()
{
	mGraph *MG = (mGraph*)malloc(sizeof(mGraph));
	Init(MG, 7, 0);
	Insert(MG, 2, 3, 1);
	Insert(MG, 3, 5, 1);
	Insert(MG, 1, 2, 1);
	Insert(MG, 2, 5, 1);
	Insert(MG, 4, 6, 1);
	Insert(MG, 5, 3, 1);
	DFSmGraph(MG);
	//print(MG);
	system("pause");
	return 0;

	/*
	mGraph *g=(mGraph*)malloc(sizeof(mGraph));
	int i,j,u,v,n,e;
	int noEdgeValue = 0;
	
	printf("请输入顶点数和边数:\n");
	scanf("%d,%d", &n,&e);

	Init(g, n, noEdgeValue);
	g->e = e;
	printf("请输入邻接矩阵:\n");
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			scanf("%d", &(g->a[i][j]));
	printf("此时的邻接矩阵为:\n");
	print(g);

	printf("请输入与要搜索的边相连的两个节点:\n");
	scanf("%d,%d",&u,&v);
	if (Exist(g, u, v))
		printf("找到了该边\n");
	else
		printf("该边不存在\n");

	printf("请输入与要插入的边相连的两个节点:\n");
	scanf("%d,%d,%d", &u, &v);
	Insert(g, u, v);
	printf("此时的邻接矩阵为:\n");
	print(g);

	printf("请输入与要删除的边相连的两个节点:\n");
	scanf("%d,%d", &u, &v);
	Remove(g, u, v);
	printf("此时的邻接矩阵为:\n");
	print(g);

	printf("深度优先遍历结果:\n");
	DFSmGraph(g);
	system("pause");
	//Destroy(g);
	*/
}