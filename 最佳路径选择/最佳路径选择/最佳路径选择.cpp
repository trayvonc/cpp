#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define ERROR 0
#define OK 1
#define Overflow 2 //上溢
#define Underflow 3//下溢
#define NotPresent 4//元素不存在
#define Duplicate 5 //存在重复元素
#define INFTY 32767//最大值
typedef int ElemType;
typedef int Status;
using namespace std;
typedef struct ENode
{
	int adjVex;//任意顶点u相邻接的顶点
	ElemType w;//边的权值
	struct ENode *nextArc; //指向下一个节点
}ENode;
typedef struct
{
	int n;//顶点数
	int e;//边数
	ENode **a; //一维数组指针
}LGraph;

/*初始化*/
Status Init(LGraph *lg, int nSize)
{
	int i;
	lg->n = nSize;
	lg->e = 0;
	lg->a = (ENode**)malloc(nSize * sizeof(ENode*));//申请一维指针数组
	if (!lg->a)
		return ERROR;
	else
	{
		for (i = 0; i<lg->n; i++)
			lg->a[i] = NULL;//将指针数组置空
		return OK;
	}
}
/*撤销*/
void Destroy(LGraph *lg)
{
	int i;
	ENode *p, *q;
	for (i = 0; i<lg->n; i++)
	{
		p = lg->a[i]; //指针p指向顶点i的单链表的第一个边结点
		q = p;
		while (p)
		{
			p = p->nextArc;
			free(q);
			q = p;
		}
	}
	free(lg->a);
}
/*搜索*/
Status Exist(LGraph *lg, int u, int v)
{
	ENode *p;
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1 || u == v)
		return ERROR;
	p = lg->a[u];
	while (p&&p->adjVex != v) p = p->nextArc;
	if (!p) return ERROR;
	else return OK;
}
/*插入*/
Status Insert(LGraph *lg, int u, int v, ElemType w)
{
	ENode *p;
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1 || u == v)
		return ERROR;
	if (Exist(lg, u, v)) return Duplicate;
	p = (ENode *)malloc(sizeof(ENode)); //为新的边节点分配空间
	p->adjVex = v;
	p->w = w;
	p->nextArc = lg->a[u]; //将新节点插入到链表最前面
	lg->a[u] = p;
	lg->e++;
	return OK;
}
/*删除边*/
Status Remove(LGraph *lg, int u, int v)
{
	ENode *p, *q;
	if (u<0 || v<0 || u>lg->n - 1 || v>lg->n - 1 || u == v)
		return ERROR;
	p = lg->a[u], q = NULL;
	while (p&&p->adjVex != v)
	{
		q = p;
		p = p->nextArc;
	}
	if (!p)
		return NotPresent;
	if (q) q->nextArc = p->nextArc;
	else lg->a[u] = p->nextArc;
	free(p);
	lg->e--;
	return OK;
}

/*深度优先遍历*/
void DFS(int v, int visited[], LGraph g)
{
	ENode *w;
	printf("%d ", v);
	visited[v] = 1;//打上标记
	for (w = g.a[v]; w; w = w->nextArc)
	{
		if (!visited[w->adjVex])
			DFS(w->adjVex, visited, g);//递归调用，将连通图访问一遍
	}
}
void DFSGraph(LGraph g)
{
	int i;
	int *visited = (int*)malloc(g.n * sizeof(int));
	for (i = 0; i<g.n; i++)
		visited[i] = 0;
	for (i = 0; i<g.n; i++)
		if (!visited[i])
			DFS(i, visited, g);//逐一检查节点
	free(visited);
}

/*宽度优先遍历*/
void BFS(int v, int visited[], LGraph g)
{
	ENode *w;
	queue<int> q;

	visited[v] = 1;
	printf("%d ", v);
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (w = g.a[v]; w; w = w->nextArc)
			if (!visited[w->adjVex])
			{
				visited[w->adjVex] = 1;
				printf("%d ", w->adjVex);
				q.push(w->adjVex);
			}
	}
}
void BFSGraph(LGraph g)
{
	int i;
	int *visited = (int *)malloc(g.n * sizeof(int));
	for (i = 0; i<g.n; i++)
		visited[i] = 0;
	for (i = 0; i<g.n; i++)
		if (!visited[i])
			BFS(i, visited, g);
	free(visited);
}

/*输出临接表*/
void OutPut(LGraph *LG)
{
	int i;
	ENode *p;
	p = LG->a[0];
	for (i = 0; i<LG->n; i++)
	{
		printf("%d: ", i);
		while (p) {
			printf("%d,", p->adjVex);
			p = p->nextArc;
		}
		p = LG->a[i + 1];
		printf("\n");
	}
}

/*迪结斯特拉算法，生成最短路径*/
int Choose(int *d, int *s, int n)
{
	int i, minpos;
	ElemType min;
	min = 32767;
	minpos = -1;
	for (i = 1; i<n; i++)
	{
		if (d[i] <= min && !s[i])
		{
			min = d[i];
			minpos = i;
		}
	}
	return minpos;//返回下标的位置
}
Status Dijkstra(int v, ElemType *d, int * path, LGraph g)
{
	int i, k, w;
	int *s;
	ENode *p;
	p = g.a[v];
	if (v<0 || v>g.n - 1)
		return ERROR;
	s = (int*)malloc(sizeof(int)*g.n);

	/*初始化*/
	for (i = 0; i<g.n; i++)
	{
		s[i] = 0;
		d[i] = INFTY;
	}
	while (p)
	{
		d[p->adjVex] = p->w;
		p = p->nextArc;
	}
	for (i = 0; i<g.n; i++)
	{
		if (i != v&&d[i]<INFTY) path[i] = v;
		else path[i] = -1;
	}

	s[v] = 1; d[v] = 0;
	for (i = 1; i<g.n - 1; i++)
	{
		k = Choose(d, s, g.n);
		s[k] = 1;
		//printf("%d ",k);
		p = g.a[k];
		while (p)
		{
			if (!s[p->adjVex] && d[k] + p->w<d[p->adjVex])
			{
				d[p->adjVex] = d[k] + p->w;
				path[p->adjVex] = k;
			}
			p = p->nextArc;
		}
	}
	/*for(i=0;i<g.n;i++)
	printf("%d ",d[i]);*/
	return OK;

}

/*输出最短路径*/
void OutPut_path(int *path, int E, int S)
{
	if (E == S)
	{
		return;
	}
	if (path[E] == -1)
	{
		printf("OutPut_path ERROR\n");
		return;
	}
	OutPut_path(path, path[E], S);
	printf("%d->", path[E]);
}
void path_shortest(int *path, int E, int S)//E为终点，S为起点
{
	if (path[E] != -1)
	{
		printf("路径为：");
		OutPut_path(path, E, S);
		printf("%d\n", E);
	}
	else {
		printf("路径不存在\n");
	}
}

/*最短路径选择*/
void Path_Selection(LGraph lg)
{
	int S, E;//S为起点，E为终点
	printf("共%d个地点\n", lg.n);
	printf("请输入起点和终点\n");
	scanf("%d%d", &S, &E);
	if (S<0 || E<0 || S >= lg.n || E >= lg.n)
	{
		printf("路径不存在\n");
		return;
	}
	/*迪杰斯特拉算法*/
	int *d = (int*)malloc(lg.n * sizeof(int));
	int *path = (int*)malloc(lg.n * sizeof(int));
	Dijkstra(S, d, path, lg);

	if (path[E] != -1)//判断路径是否存在
		printf("最短路径长度为：%d\n", d[E]);//输出最短路径长度
	path_shortest(path, E, S);//输出最短路径
	free(d);
	free(path);
}

int main()
{
	LGraph *LG = (LGraph*)malloc(sizeof(LGraph));
	/*由用户输入图*/
	int n, m, i;
	int s, e, w;
	printf("请输入地点个数\n");
	scanf("%d", &n);
	printf("请输入路径个数\n");
	scanf("%d", &m);
	if (m<0 || n<0 || m>(n + 1)*n / 2.0f)
	{
		printf("Graph Error\n");
		return 0;
	}
	Init(LG, n);
	for (i = 0; i<m; i++)
	{
		printf("请输入起点、终点、路径长度\n");
		scanf("%d%d%d", &s, &e, &w);
		Insert(LG, s, e, w);
	}

	/*Insert(LG,0,1,50);
	Insert(LG,0,2,10);
	Insert(LG,0,4,80);
	Insert(LG,2,3,15);
	Insert(LG,3,1,20);
	Insert(LG,3,4,45);
	Insert(LG,1,2,15);
	Insert(LG,1,4,20);
	Insert(LG,5,4,10);
	Insert(LG,5,3,9);
	Insert(LG,4,3,45);*/

	Path_Selection(*LG);

	system("pause");
	return 0;
}

