#include "linkedlist.h"
extern int i = 1;

Status InitList(LinkedList* L)			//��ʼ������
{
	int a,i,j=0;
	LinkedList n,p;
	*L = (LinkedList)malloc(sizeof(LNode));
	if ((*L) == NULL)
	{
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	else
		(*L)->next = NULL;

	printf("����������Ҫ����Ľ������");
	scanf_s("%d", &i);
	(*L)->next=NULL ;
	while (j < i)
	{
		printf("�������%d���������ݣ�", j + 1);
		scanf_s("%d", &a);
		p = (LinkedList)malloc(sizeof(LNode));
		p->data = a;
		p->next=(*L)->next;
		(*L)->next = p;
		j++;
	}
	return SUCCESS;
}

void DestroyList(LinkedList* L)			//ɾ������
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

Status InsertList(LNode* p, LNode* q)			//��q���뵽p֮ǰ
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
	q = p->next;									//��qΪp����һ�����
	p->next = q->next;								//ʹpֱ��ָ��q����һ����㣬���������q��ʹ��q��ɾ��
	*e = q->data;									//��q�����ݸ���e
	free(q);										//�ͷŽ��q
	return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))			//��������
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

Status SearchList(LinkedList L, ElemType e)				//�ж�����e�Ƿ���������
{
	LinkedList p;
	p = L->next;
	while (p)
	{
		i++;
		if (e == p->data)
			return SUCCESS;								//������ڸ�������Ż�1
		p = p->next;
	}
	return ERROR;										//���ֱ��β�����δ�ҵ������ݣ�����0
}

Status ReverseList(LinkedList* L)						//��ת����
{
	LinkedList p, n, m;									
	n = NULL;
	p = (*L)->next;
	(*L)->next = NULL;
	while (p)
	{
		m = p->next;							//mΪ��һ�����
		p->next = n;							//����һ������ָ��ָ����һ�����
		n = p;									//��nΪ��ǰ��㣬Ϊ��һ��ѭ��׼��
		p = m;									//pָ����һ�����
	}
	(*L)->next = n;								//ͷָ��ָ��ԭ�����е����һ����㣬��������ĵ�һ�����
	return SUCCESS;
}

Status IsLoopList(LinkedList L)					//�ж��Ƿ�Ϊѭ������
{
	LinkedList p, n;			
	p = L->next;								//��ָ��p
	n = L->next->next;							//��ָ��n
	while (p!=NULL||n!=NULL)
	{		
		if (p == n)
			return SUCCESS;						//����1��˵����ѭ������
		p = p->next;
		n = n->next->next;
	}
	return ERROR;								//�Ż�0��˵������ѭ������
}

LNode* ReverseEvenList(LinkedList* L)				//��ż����
{
	int j;
	LinkedList p, n;
	p = (*L)->next;
	n = (*L)->next->next;
	while (p != NULL && n != NULL&&(n->next)!=NULL)
	{
		j = p->data;
		p->data = n->data;
		n->data = j;									//����������������ֵ
		p = p->next;
		n = n->next->next;
	}
	return *L;

}

LNode* FindMidNode(LinkedList* L)						//�����м���
{
	LinkedList p, n;
	p = (*L)->next;
	n = (*L)->next->next;
	while (p != NULL && n != NULL && (n->next) != NULL)			//����һ��������һ��
	{
		p = p->next;
		n = n->next->next;
	}
	return p;
}
