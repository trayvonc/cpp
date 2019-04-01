/*
#include<iostream>
using namespace std;
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef int Status;
typedef struct Node
{
	ElemType element;
	struct Node *link;
}Node;
typedef struct
{
	struct Node *head;
	int n;
}HeaderList;
//初始化
Status Init(HeaderList *h)
{
	h->head = (Node*)malloc(sizeof(Node));
	if (!h->head)
		return ERROR;
	h->head ->link = NULL;
	h->n = 0;
	return OK;
}
//查找
Status Find(HeaderList h, int i, ElemType *x)
{
	Node *p;
	int j;
	if (i<0 || i>h.n - 1)
		return ERROR;
	p = h.head;
	for (j = 0; j < i; j++)
		*x = p->element;
	return OK;
}
//插入
Status Insert(int i, ElemType x, HeaderList *h)
{
	if (i<-1 || i>h->n-1)
		return ERROR;
	Node *p = h->head;                                       //多考虑
	for (int j = 0; j<i; j++) p = p->link;
	Node *q = new Node;
	q->element = x;
	q->link = p->link;
	p->link = q;
	h->n++;
	return OK;
}
//删除
Status Delete(HeaderList *h, int i)
{
	int j;
	Node *p, *q;
	if (!h->n)
		return ERROR;
	if (i<0 || i>h->n - 1)
		return ERROR;
	q = h->head;
	for (j = 0; j<i; j++)q = q->link;
	p = q->link;
	q->link = p->link;
	free(p);
	h->n--;
	return OK;
}
//输出
Status Output(HeaderList h)
{
	int i;
	if (!h.n)
		return ERROR;
	Node *p = h.head->link;
	while (p)
	{
		printf("%d", p->element);
		p = p->link;
	}
	return OK;
}
//撤销
void Destroy(HeaderList *h)
{
	Node *p;
	while (h->head)
	{
		p = h->head->link;
		free(h->head);
		h->head = p;
	}
}
void main() 
{
	int i;
	int x;
	HeaderList list;
	Init(&list);
	for (i = 0; i < 9; i++)
	Insert(i-1,i,&list);
	cout << "the HeaderList is :";
	Output(list);
	Delete(&list, 0);
	cout << endl << "the HeaderList is :";
	Output(list);
	int l=Find(list, 0, &x);
	cout << endl << "the value is:"<<l<<endl;
	Destroy(&list);
}
*/