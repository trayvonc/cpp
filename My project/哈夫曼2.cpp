// ��������.cpp : �������̨Ӧ�ó������ڵ㡣
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
	for (i = 0; i<2 * N; i++, y = 0)//���������
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

	for (i = 0; i<N; i++)//����
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
	while (Text[j] != '\0') {    //�����ַ�����/���봮
		if (Text[j] == '0')
			i = Ht[i].lChild;   //��������
		else
			i = Ht[i].rChild;   //�����Һ���
		if (Ht[i].lChild == -1) {   //���Ƿ�ýڵ�ΪҶ�ӽڵ�
			printf("%c", Ht[i].Data); //�ǵĻ�����������ظ��ڵ�
			i = 11;
		}
		j++;   //�����Ƿ��ҵ�Ҷ�ӽڵ㶼��ȡ��һ�����봮�ַ�
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

	//printf("�����������Ĳ�ͬ��ĸ����\n"); //�ֶ�����Ȩֵ��ϵʱʹ��
	//scanf("%d",&num);
	//for(int i=1;i<=num;i++)
	//{
	//ch=getchar();
	//printf("������������Ԫ�أ�");
	//scanf("%c",&Ht[i].Data);
	//printf("�������Ԫ�ص�Ȩֵ��");
	//scanf("%d",&Ht[i].w);
	//printf("\n");
	//}

	CreateHFMTree(Ht, num);

	//for(int i=1;i<2*num;i++) //��ӡ��������
	//{
	//printf("No.%d parent��%d lchild��%d rchild:%d value:%d Data:%c\n",i,Ht[i].parent,Ht[i].lChild,Ht[i].rChild,Ht[i].w,Ht[i].Data);
	//}

	char BM[66][66];
	CreatBM(BM, Ht, num);

	printf("��������Ҫ������ַ���\n");
	char Text[MAX];

	getchar();
	gets_s(Text);

	printf("������Ϊ:\n");
	char HFM[66];
	Compress(BM, Text, HFM, num);
	puts(HFM);

	printf("��������Ҫ������ַ���\n");
	gets_s(Text);
	printf("������Ϊ:\n");
	UnCompress(Text, Ht, num);


	system("pause");
	return 0;
}
*/