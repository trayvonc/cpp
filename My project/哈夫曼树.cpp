/*
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char ElementType;
const int MAX = 20;
#define S 20
typedef struct HFMTNode{
	ElementType Data;
	int w;
	int parent, lchild, rchild;
}HFMTNode;
void CreateHfmtREE(HFMTNode Ht[], int N)//哈夫曼树创建
{
	int i, j, k, lmin,rmin;
	int min1, min2;
	for (i = 1; i < 2 * N; i++)
		Ht[i].parent = Ht[i].lchild = Ht[i].rchild = -1;
	for (i = N+1; i < 2*N; i++)
	{
		min1 = min2 = MAX;
		lmin = rmin = -1;
		for (k = 1; k <= i - 1; k++)
			if (Ht[k].parent == -1)
			{
				if (Ht[k].w < min1)
				{
					min2 = min1; rmin = lmin;
					min1 = Ht[k].w; lmin = k;
				}
				else if (Ht[k].w < min2)
				{
					min2 = Ht[k].w; rmin = k;
				}
				
			}
		Ht[lmin].parent = i;
		Ht[rmin].parent = i;
		Ht[i].w = Ht[lmin].w + Ht[rmin].w;
		Ht[i].lchild = lmin; Ht[i].rchild = rmin;
	}
}


int main()
{
	int n;
	HFMTNode ht[S];
	printf("请输入节点个数\n");
	scanf("%d", &n);
	printf("\n");
	printf("请输入各权值\n");
	for (int i = 0; i <n; i++)
	{
		scanf("%d",&(ht[i].w) ) ;
	}
	CreateHfmtREE(ht, n);  
}
*/