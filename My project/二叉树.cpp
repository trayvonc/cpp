/*
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
typedef struct BinaryTreeNode// �ṹ�嶨��
{
	char data; // ������
	struct BinaryTreeNode *lchild, *rchild; // ָ����������Һ���ָ��
}BinaryTreeNode, *BinTree;//ΪBiTNodeȡ����BiTNode��ΪBiTNode*ȡ����BiTree
void PreCreateBt(BinTree *T)////����*T���ɣ�(*T)��ָ��BinaryTreeNode��ָ��
{
	char ch;
	ch = getchar();
	if (ch == '#') // ����ֵΪ��
		*T = NULL;
	else // ����ֵ��Ϊ��
	{
		*T = (BinTree)malloc(sizeof(BinaryTreeNode));
		if (!T)
		{
			printf("����ռ�ʧ��!!!");
			exit(ERROR);
		}
		(*T)->data = ch;                      //*T����һ��ָ��ڵ��ָ��
		PreCreateBt(&((*T)->lchild)); // �ݹ���ú���������������
		PreCreateBt(&((*T)->rchild)); // �ݹ���ú���������������
	}
}

void PreOrderT(BinTree T)
{
	if (T) // �������ǿ�
	{
		printf("%c ", T->data);// �ȷ��ʸ����
		PreOrderT(T->lchild); // �ݹ���ú������������������
		PreOrderT(T->rchild); // �ݹ���ú������������������
	}
}
void InOrderT(BinTree T)
{
	if (T)
	{
		InOrderT(T->lchild); // �ݹ���ú������������������
		printf("%c ", T->data); // ���ʸ����
		InOrderT(T->rchild); // �ݹ���ú������������������
	}
}
void PostOrderT(BinTree T)
{
	if (T)
	{
		PostOrderT(T->lchild); // �ݹ���ú��� , �������������
		PostOrderT(T->rchild); // �ݹ���ú��� , �����������
		printf("%c ", T->data); // ���ʸ����
	}
}
int Jiedian(BinTree T)
{
	if (!T)
		return 0;
	return Jiedian(T->lchild) + Jiedian(T->rchild) + 1;
}

int YZjiedian(BinTree T)
{
	int nodes;
	if (!T)
		return 0;
	else if ((T->lchild == NULL) && (T->rchild == NULL))
		return 1;
	else
		nodes = YZjiedian(T->lchild) + YZjiedian(T->rchild);
	return nodes;
}

int BinaryTreeHeight(BinTree T)
{
	int treeHeight = 0;
	if (!T)
		return 0;
	else
	{
		int leftHeight = BinaryTreeHeight(T->lchild);
		int rightHeight = BinaryTreeHeight(T->rchild);
		treeHeight = leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;//�ص㣬��ѧ����
	}

	return treeHeight;
}
void SwapChild(BinTree T)
{
	BinTree temp;//��ʱ�洢
	if (T == NULL)
		return;
	else {
		temp = T->lchild;
		T->lchild = T->rchild;
		T->rchild = temp;
		SwapChild(T->lchild);
		SwapChild(T->rchild);
	}
}

int main()
{
	BinTree T;
	printf("�������������������н���ֵ ( ����#��ʾ�ڵ�Ϊ�� )\n");
	printf("��������Ҫ�����Ķ����� :\n");
	PreCreateBt(&T);
	printf(" ��������������� \n");
	PreOrderT(T);
	printf("\n");
	printf("��������������� \n");
	InOrderT(T);
	printf("\n");
	printf("��������������� \n");
	PostOrderT(T);
	printf("\n");
	int jiedian = Jiedian(T);
	printf("�����Ϊ��");
	printf("%d", jiedian);
	printf("\n");
	int YZJiedian = YZjiedian(T);
	printf("Ҷ�ӽ����Ϊ��");
	printf("%d", YZJiedian);
	printf("\n");
	int height = BinaryTreeHeight(T);
	printf("�������Ĳ���Ϊ��");
	printf("%d", height);
	printf("\n");
	printf("����������������������Ϊ�� \n");
	SwapChild(T);
	PreOrderT(T);
	printf("\n");
	system("PAUSE");
	return 0;
}
*/