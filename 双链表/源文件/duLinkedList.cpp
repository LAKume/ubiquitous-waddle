#include "duLinkedList.h"

//typedef struct DuLNode {
//	ElemType data;
//	struct DuLNode* prior, * next;
//} DuLNode, * DuLinkedList;

Status InitList_DuL(DuLinkedList* L)
{
	int x, i = 0, j;
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if ((*L) == NULL)
	{
		printf("初始化失败\n");
		return ERROR;
	}
	(*L)->next =(*L)->prior= NULL;																//创建空链表完成
	DuLinkedList s, r;
	r = (*L);
	printf("初始化成功，请输入要创建的节点数：");
	scanf_s("%d", &j);
	while (i<j)													//初始化链表
	{
		s = (DuLNode*)malloc(sizeof(DuLNode));					//创建新的结点 
		printf("请输入第%d个整数：", i + 1);
		scanf_s("%d", &x);
		s->data = x;
		s->prior = r;
		r->next = s;
		r = s;
		i++;
	}
	r->next = NULL;
	return SUCCESS;

}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))			//遍历链表
{
	if ((L ->next)==NULL)													//判断是否初始化链表
	{
		printf("请初始化链表\n");
		return;
	}
		DuLinkedList p;
		p = L->next;
		printf("当前链表为：\n");
		while (p!=NULL)
		{
			visit(p->data);
			p = p->next;
		}
		printf("NULL\n");
	
}
void visit(ElemType e)														//输出函数
{
	printf("%d->", e);
}

void DestroyList_DuL(DuLinkedList* L)										//销毁链表
{
	if (((*L)->next) == NULL)
	{
		printf("请初始化链表\n");
		return;
	}
	DuLinkedList p, n;
	p = (*L)->next;
	while (p != NULL)
	{
		n = p;
		p = n->next;
		free(n);
	}
	(*L)->next = NULL;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)			//在节点p后插入节点q
{
	if (p->next == NULL)									//如果q是链表未
	{
		p->next = q;
		q->prior = p;
		q->next = NULL;										//将p，q的前后指向改变
		return SUCCESS;
	}

	else													//如果q不是链表尾部
	{
		q->prior = p;
		p->next->prior = q;
		q->next = p->next->next;
		p->next = q;
		return SUCCESS;
	}
	return ERROR;
}


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)			//在节点p前插入节点q
{
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = p;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)				//删除节点p后的第一个节点，并将其值赋给e  
{
	if (p->next == NULL)
	{
		printf("该结点位于链表末，请重新输入\n");
		return ERROR;
	}
	DuLinkedList n;
	n = p->next;											//n为p后一个结点，目的删除n
	n->next->prior = p;
	p->next = n->next;
	*e = n->data;
	free(n);
	printf("删除成功,删除的数据为%d\n", *e);
	return SUCCESS;
}
