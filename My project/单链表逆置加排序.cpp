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
//Äæ»»
Status Inverse(HeaderList *h)
{
	if (h->n == 0 || h->n == 1)   //¿¼ÂÇ
		return ERROR;
	Node *p1, *p2, *p3;
	//int i;
	p1 = h->head;
	p2 = p1->link;
	p3 = NULL;
	while (p2)
	{
		p3 = p2->link;
		p2->link = p1;
		p1 = p2;
		p2 = p3;
	}
	h->head->link->link = NULL;
	h->head->link = p1;
	return OK;
}
//ÅÅĞò
Status paixu(HeaderList *h)
{
	if (h->n == 0 || h->n == 1)   //¿¼ÂÇ
		return ERROR;
	Node *p1, *p2;
	int a, i, j;
	int n = h->n;
	for (i = 0; i < n - 1; i++)
	{
		p1 = h->head->link;
		for (j =n-1; j >0; j--)
		{
			while (p1->link != NULL)
			{
				p2 = p1;
				p1 = p1->link;
				if (p2->element < p1->element)
				{
					a = p1->element;
					p1->element = p2->element;
					p2->element = a;
				}
			}
		}
	}
}
//³õÊ¼»¯
Status Init(HeaderList *h)
{
	h->head = (Node*)malloc(sizeof(Node));
	if (!h->head)
		return ERROR;
	h->head->link = NULL;
	h->n = 0;
	return OK;
}
//²åÈë
Status Insert(int i, ElemType x, HeaderList *h)
{
	if (i<-1 || i>h->n - 1)
		return ERROR;
	Node *p = h->head;                                       //¶à¿¼ÂÇ
	for (int j = 0; j<i; j++) p = p->link;
	Node *q = new Node;
	q->element = x;
	q->link = p->link;
	p->link = q;
	h->n++;
	return OK;
}
//Êä³ö
Status Output(HeaderList h)
{
	//int i;
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
//³·Ïú
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
	HeaderList list;
    Init(&list);
	//for (i = 0; i < 10; i++)
	//	Insert(i-1, i, &list);
	Insert(-1, 1, &list);
	Insert(0, 2, &list);
	Insert(1, 3, &list);
	cout << "the HeaderList is:";
	Output(list);
	Inverse(&list);
	cout <<endl<< "after inverse:";
	Output(list);
	paixu(&list);
	cout << endl << "after paixu:";
	Output(list);
	cout << endl;
	Destroy(&list);
}
*/