#include "linkedlist.h"
extern int i = 1;

Status InitList(LinkedList* L)			//初始化链表
{
	int a,i,j=0;
	LinkedList n,p;
	*L = (LinkedList)malloc(sizeof(LNode));
	if ((*L) == NULL)
	{
		printf("初始化失败\n");
		return ERROR;
	}
	else
		(*L)->next = NULL;

	printf("请输入所需要构造的结点数：");
	scanf_s("%d", &i);
	(*L)->next=NULL ;
	while (j < i)
	{
		printf("请输入第%d个整数数据：", j + 1);
		scanf_s("%d", &a);
		p = (LinkedList)malloc(sizeof(LNode));
		p->data = a;
		p->next=(*L)->next;
		(*L)->next = p;
		j++;
	}
	return SUCCESS;
}

void DestroyList(LinkedList* L)			//删除链表
{
	LinkedList p, q;
	p = (*L)->next;
	while (p)
	{
		q=p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
}

Status InsertList(LNode* p, LNode* q)			//将q插入到p之前
{
	if (p || q)
	{
		q->next = p->next;
		p->next = q;
		return SUCCESS;
	}
	return ERROR;
}


Status DeleteList(LNode* p, ElemType* e)
{
	LNode* q;
	q = p->next;									//令q为p的下一个结点
	p->next = q->next;								//使p直接指向q的下一个结点，即跳过结点q，使得q被删除
	*e = q->data;									//将q的数据赋给e
	free(q);										//释放结点q
	return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))			//遍历链表
{
	LinkedList p;
	p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void visit(ElemType e)
{
	printf("%d->", e);
}

Status SearchList(LinkedList L, ElemType e)				//判断数据e是否在链表中
{
	LinkedList p;
	p = L->next;
	while (p)
	{
		i++;
		if (e == p->data)
			return SUCCESS;								//如果存在该数据则放回1
		p = p->next;
	}
	return ERROR;										//如果直到尾结点仍未找到该数据，返回0
}

Status ReverseList(LinkedList* L)						//反转链表
{
	LinkedList p, n, m;									
	n = NULL;
	p = (*L)->next;
	(*L)->next = NULL;
	while (p)
	{
		m = p->next;							//m为下一个结点
		p->next = n;							//将下一个结点的指针指向上一个结点
		n = p;									//令n为当前结点，为下一个循环准备
		p = m;									//p指向下一个结点
	}
	(*L)->next = n;								//头指针指向原链表中的最后一个结点，即新链表的第一个结点
	return SUCCESS;
}

Status IsLoopList(LinkedList L)					//判断是否为循环链表
{
	LinkedList p, n;			
	p = L->next;								//慢指针p
	n = L->next->next;							//快指针n
	while (p!=NULL||n!=NULL)
	{		
		if (p == n)
			return SUCCESS;						//返回1，说明是循环链表
		p = p->next;
		n = n->next->next;
	}
	return ERROR;								//放回0，说明不是循环链表
}

LNode* ReverseEvenList(LinkedList* L)				//奇偶互换
{
	int j;
	LinkedList p, n;
	p = (*L)->next;
	n = (*L)->next->next;
	while (p != NULL && n != NULL&&(n->next)!=NULL)
	{
		j = p->data;
		p->data = n->data;
		n->data = j;									//交换相邻两结点的数值
		p = p->next;
		n = n->next->next;
	}
	return *L;

}

LNode* FindMidNode(LinkedList* L)						//查找中间结点
{
	LinkedList p, n;
	p = (*L)->next;
	n = (*L)->next->next;
	while (p != NULL && n != NULL && (n->next) != NULL)			//和上一个基本上一样
	{
		p = p->next;
		n = n->next->next;
	}
	return p;
}
