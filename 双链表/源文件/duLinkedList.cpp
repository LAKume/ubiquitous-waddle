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
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	(*L)->next =(*L)->prior= NULL;																//�������������
	DuLinkedList s, r;
	r = (*L);
	printf("��ʼ���ɹ���������Ҫ�����Ľڵ�����");
	scanf_s("%d", &j);
	while (i<j)													//��ʼ������
	{
		s = (DuLNode*)malloc(sizeof(DuLNode));					//�����µĽ�� 
		printf("�������%d��������", i + 1);
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

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))			//��������
{
	if ((L ->next)==NULL)													//�ж��Ƿ��ʼ������
	{
		printf("���ʼ������\n");
		return;
	}
		DuLinkedList p;
		p = L->next;
		printf("��ǰ����Ϊ��\n");
		while (p!=NULL)
		{
			visit(p->data);
			p = p->next;
		}
		printf("NULL\n");
	
}
void visit(ElemType e)														//�������
{
	printf("%d->", e);
}

void DestroyList_DuL(DuLinkedList* L)										//��������
{
	if (((*L)->next) == NULL)
	{
		printf("���ʼ������\n");
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

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)			//�ڽڵ�p�����ڵ�q
{
	if (p->next == NULL)									//���q������δ
	{
		p->next = q;
		q->prior = p;
		q->next = NULL;										//��p��q��ǰ��ָ��ı�
		return SUCCESS;
	}

	else													//���q��������β��
	{
		q->prior = p;
		p->next->prior = q;
		q->next = p->next->next;
		p->next = q;
		return SUCCESS;
	}
	return ERROR;
}


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)			//�ڽڵ�pǰ����ڵ�q
{
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = p;
	return SUCCESS;
}

Status DeleteList_DuL(DuLNode* p, ElemType* e)				//ɾ���ڵ�p��ĵ�һ���ڵ㣬������ֵ����e  
{
	if (p->next == NULL)
	{
		printf("�ý��λ������ĩ������������\n");
		return ERROR;
	}
	DuLinkedList n;
	n = p->next;											//nΪp��һ����㣬Ŀ��ɾ��n
	n->next->prior = p;
	p->next = n->next;
	*e = n->data;
	free(n);
	printf("ɾ���ɹ�,ɾ��������Ϊ%d\n", *e);
	return SUCCESS;
}
