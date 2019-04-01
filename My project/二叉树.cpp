/*
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
typedef struct BinaryTreeNode// 结构体定义
{
	char data; // 数据域
	struct BinaryTreeNode *lchild, *rchild; // 指针域包括左右孩子指针
}BinaryTreeNode, *BinTree;//为BiTNode取别名BiTNode，为BiTNode*取别名BiTree
void PreCreateBt(BinTree *T)////操作*T即可，(*T)是指向BinaryTreeNode的指针
{
	char ch;
	ch = getchar();
	if (ch == '#') // 结点的值为空
		*T = NULL;
	else // 结点的值不为空
	{
		*T = (BinTree)malloc(sizeof(BinaryTreeNode));
		if (!T)
		{
			printf("分配空间失败!!!");
			exit(ERROR);
		}
		(*T)->data = ch;                      //*T就是一个指向节点的指针
		PreCreateBt(&((*T)->lchild)); // 递归调用函数，构造左子树
		PreCreateBt(&((*T)->rchild)); // 递归调用函数，构造右子树
	}
}

void PreOrderT(BinTree T)
{
	if (T) // 二叉树非空
	{
		printf("%c ", T->data);// 先访问根结点
		PreOrderT(T->lchild); // 递归调用函数，先序遍历左子树
		PreOrderT(T->rchild); // 递归调用函数，先序遍历右子树
	}
}
void InOrderT(BinTree T)
{
	if (T)
	{
		InOrderT(T->lchild); // 递归调用函数，中序遍历左子树
		printf("%c ", T->data); // 访问根结点
		InOrderT(T->rchild); // 递归调用函数，中序遍历右子树
	}
}
void PostOrderT(BinTree T)
{
	if (T)
	{
		PostOrderT(T->lchild); // 递归调用函数 , 后序遍历左子树
		PostOrderT(T->rchild); // 递归调用函数 , 序遍历右子树
		printf("%c ", T->data); // 访问根结点
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
		treeHeight = leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;//重点，活学活用
	}

	return treeHeight;
}
void SwapChild(BinTree T)
{
	BinTree temp;//临时存储
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
	printf("按先序次序输入二叉树中结点的值 ( 输入#表示节点为空 )\n");
	printf("请输入所要建立的二叉树 :\n");
	PreCreateBt(&T);
	printf(" 先序遍历二叉树： \n");
	PreOrderT(T);
	printf("\n");
	printf("中序遍历二叉树： \n");
	InOrderT(T);
	printf("\n");
	printf("后序遍历二叉树： \n");
	PostOrderT(T);
	printf("\n");
	int jiedian = Jiedian(T);
	printf("结点数为：");
	printf("%d", jiedian);
	printf("\n");
	int YZJiedian = YZjiedian(T);
	printf("叶子结点数为：");
	printf("%d", YZJiedian);
	printf("\n");
	int height = BinaryTreeHeight(T);
	printf("二叉树的层数为：");
	printf("%d", height);
	printf("\n");
	printf("交换左右子树后的先序遍历为： \n");
	SwapChild(T);
	PreOrderT(T);
	printf("\n");
	system("PAUSE");
	return 0;
}
*/