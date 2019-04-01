// 哈夫曼树.cpp : 定义控制台应用程序的入口点。
//
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 999
#define ElementType char
typedef struct HFMTNode {
	ElementType Data;
	int w;
	int parent, lChild, rChild;
}HFMTNode;

void CreateHFMTree(HFMTNode Ht[], int N)
{
	int i, j, k, lmin, rmin;
	int min1, min2;
	for (int i = 1; i<2 * N; i++)
		Ht[i].parent = Ht[i].lChild = Ht[i].rChild = -1;
	for (int i = N + 1; i<2 * N; i++)
	{
		min1 = min2 = 9999;
		lmin = rmin = -1;
		for (k = 1; k <= i - 1; k++)
		{
			if (Ht[k].parent == -1)
			{
				if (Ht[k].w<min1) {
					min2 = min1; rmin = lmin;
					min1 = Ht[k].w; lmin = k;
				}

				else if (Ht[k].w<min2) {
					min2 = Ht[k].w; rmin = k;
				}
			}
		}
		Ht[lmin].parent = i;
		Ht[rmin].parent = i;
		Ht[i].w = Ht[lmin].w + Ht[rmin].w;
		Ht[i].lChild = lmin; Ht[i].rChild = rmin;
	}
}

void CreatBM(char bm[][66], HFMTNode Ht[], int N)
{
	int i, j, k, temp, x = 0, y = 0;
	char BM[22][22];
	for (i = 0; i<2 * N; i++, y = 0)//创建编码表
	{
		if (Ht[i].Data >= 'A'&&Ht[i].Data <= 'Z')
		{
			int Parent = Ht[i].parent;
			temp = i;
			while (Ht[Parent].parent != -1)
			{
				if (Ht[Parent].lChild == temp)
					BM[x][y++] = '0';
				else
					BM[x][y++] = '1';
				temp = Parent;
				Parent = Ht[Parent].parent;
			}
			if (Ht[Parent].lChild == temp)
				BM[x][y++] = '0';
			else
				BM[x][y++] = '1';
			BM[x][y++] = Ht[i].Data;
			BM[x++][y++] = '\0';
		}
	}

	for (i = 0; i<N; i++)//逆置
	{
		for (j = 0; BM[i][j] != '\0'; j++);
		for (k = 0; k<j; k++)
		{
			bm[i][k] = BM[i][j - k - 1];
		}
		bm[i][k] = '\0';
		//printf("k=%d\n",k);
	}
}

int Search(char BM[][66], char ch, int N)
{
	int i, j;
	for (i = 0; i<N; i++)
	{
		if (BM[i][0] == ch)
			return i;
	}
	return -1;
}

void Compress(char BM[][66], char Text[], char Ht[], int N)
{
	int i, j = 0;
	int T = 0;
	for (i = 0; Text[i] != '\0'; i++)
	{
		int t = Search(BM, Text[i], N);
		for (j = 1; BM[t][j] != '\0'; j++)
		{
			Ht[T++] = BM[t][j];
		}
	}
	Ht[T] = '\0';
}

void UnCompress(char Text[], HFMTNode Ht[], int N)
{
	int k, Max, sign;
	Max = 0;
	for (k = 1; k<2 * N; k++)
	{
		if (Ht[k].w>Max)
		{
			Max = Ht[k].w; sign = k;
		}
	}

	int i = sign;
	int j = 0;
	while (Text[j] != '\0') {    //遍历字符数组/编码串
		if (Text[j] == '0')
			i = Ht[i].lChild;   //走向左孩子
		else
			i = Ht[i].rChild;   //走向右孩子
		if (Ht[i].lChild == -1) {   //看是否该节点为叶子节点
			printf("%c", Ht[i].Data); //是的话输出，并返回根节点
			i = 11;
		}
		j++;   //无论是否找到叶子节点都读取下一个编码串字符
	}
}



int main()
{
	int num = 6;
	char ch;
	HFMTNode Ht[99];
	Ht[1].Data = 'A'; Ht[1].w = 28;
	Ht[2].Data = 'B'; Ht[2].w = 23;
	Ht[3].Data = 'C'; Ht[3].w = 15;
	Ht[4].Data = 'D'; Ht[4].w = 9;
	Ht[5].Data = 'E'; Ht[5].w = 11;
	Ht[6].Data = 'F'; Ht[6].w = 14;

	//printf("请输入待编码的不同字母个数\n"); //手动输入权值关系时使用
	//scanf("%d",&num);
	//for(int i=1;i<=num;i++)
	//{
	//ch=getchar();
	//printf("请输入待编码的元素：");
	//scanf("%c",&Ht[i].Data);
	//printf("请输入该元素的权值：");
	//scanf("%d",&Ht[i].w);
	//printf("\n");
	//}

	CreateHFMTree(Ht, num);

	//for(int i=1;i<2*num;i++) //打印哈夫曼树
	//{
	//printf("No.%d parent：%d lchild：%d rchild:%d value:%d Data:%c\n",i,Ht[i].parent,Ht[i].lChild,Ht[i].rChild,Ht[i].w,Ht[i].Data);
	//}

	char BM[66][66];
	CreatBM(BM, Ht, num);

	printf("请输入需要编码的字符串\n");
	char Text[MAX];

	getchar();
	gets_s(Text);

	printf("编码结果为:\n");
	char HFM[66];
	Compress(BM, Text, HFM, num);
	puts(HFM);

	printf("请输入需要译码的字符串\n");
	gets_s(Text);
	printf("译码结果为:\n");
	UnCompress(Text, Ht, num);


	system("pause");
	return 0;
}
*/