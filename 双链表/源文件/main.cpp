#include "DulinkedList.h"


DuLinkedList L, p, n;


int main(void)
{
	char* ch;
	L = (DuLinkedList)malloc(sizeof(DuLNode));
	p = (DuLinkedList)malloc(sizeof(DuLNode));
	n = (DuLinkedList)malloc(sizeof(DuLNode));
	ch = (char*)malloc(sizeof(char));
	if (L == NULL)
	{
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	else
		L->next = NULL;

	int i = -1;
	int x = 0,a ;

	while (i != 0)
	{
		i = -1;
		system("color f3");
		printf("---------------------------------------˫����Ļ�������---------------------------------------\n");
		printf("					-������һ��������ѡ������Ҫ�Ĺ��ܣ�\n");
		printf("\n\n");
		printf("					-1.��ʼ������\n");
		printf("					-2.��������\n");
		printf("					-3.�ڽ��ǰ����һ������\n");
		printf("					-4.�ڽ������һ������\n");
		printf("					-5.ɾ��һ������\n");
		printf("					-6.�������\n");
		printf("					-0.�˳�bug��\n������һ��������");
		scanf_s("%d", &i);
		gets_s(ch, 40);

		switch (i)
		{
		case 1:
			system("cls");
			if (L->next != NULL)
			{
				printf("�����������\n");
				system("pause");
				system("cls");
				break;
			}
			InitList_DuL(&L);		//��ʼ������
			printf("\n\n\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			DestroyList_DuL(&L);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			p = L->next;
			TraverseList_DuL(L, visit);
			printf("������Ҫ�����λ�õĺ�һ���������ݣ�");
			scanf_s("%d", &a);
			while (p != NULL && p->data != a)
			{
				p = p->next;										//Ѱ�ҵ�����������������ȵĽ��p
			}
			if (p == NULL)	printf("�����ݲ�����������\n");			//�жϸ������Ƿ���������
			else
			{
				printf("������Ҫ�������ݣ�");
				scanf_s("%d", &a);
				n->data = a;
				InsertBeforeList_DuL(p, n);
				printf("����ɹ�\n");
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				system("cls");
				break;
			}			p = L->next;
			TraverseList_DuL(L, visit);
			printf("������Ҫ�����λ�õ�ǰһ���������ݣ�");
			scanf_s("%d", &a);
			while (p != NULL && p->data != a)
			{
				p = p->next;										//Ѱ�ҵ�����������������ȵĽ��p
			}
			if (p == NULL)	printf("�����ݲ�����������\n");			//�жϸ������Ƿ���������
			else
			{
				printf("������Ҫ�������ݣ�");
				scanf_s("%d", &a);
				n->data = a;
				InsertAfterList_DuL(p, n);
				printf("����ɹ�\n");
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			p = L->next;
			TraverseList_DuL(L, visit);
			printf("������Ҫɾ���Ľ���ǰһ���������ݣ�");
			scanf_s("%d", &a);
			while (p != NULL && n->data != a)
				p = p->next;
			if(p==NULL)	printf("�����ݲ�����������\n");			//�жϸ������Ƿ���������
			else
				DeleteList_DuL(p, &a);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			TraverseList_DuL(L, visit);
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			printf("��л�ۿ�\n");
			system("pause");
			return 0;
		default:
			system("cls");
			printf("��������ȷ������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
