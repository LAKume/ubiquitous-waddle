#include "linkedList.h"


LinkedList L,p,n;



int main(void)
{
	char *ch;
	L = (LinkedList)malloc(sizeof(LNode));
	p = (LinkedList)malloc(sizeof(LNode));
	n = (LinkedList)malloc(sizeof(LNode));
	ch = (char*)malloc(sizeof(char));
	if (L == NULL)
	{
		printf("��ʼ��ʧ��\n");
		return ERROR;
	}
	else
		L->next = NULL;

	int i = -1;
	int x=0,a=0;
	while (i != 0)
	{
		i = -1;
		system("color f5");
		printf("					��ӭ������ˮ����-�S-��bug��\n");
		printf("					-������һ��������ѡ������Ҫ�Ĺ��ܣ�\n");
		printf("\n\n");
		printf("					-1.��ʼ������\n");
		printf("					-2.�������\n");
		printf("					-3.����һ������\n");
		printf("					-4.ɾ��һ������\n");
		printf("					-5.�������\n");
		printf("					-6.���������Ƿ�����������\n");
		printf("					-7.��ת����\n");
		printf("					-8.�ж��Ƿ�Ϊѭ������\n");
		printf("					-9.�����������ż��������\n");
		printf("					-10.���������м�ֵ\n");
		printf("					-0.�˳�bug��\n������һ��������");
		scanf_s("%d", &i);
		gets_s(ch,40);

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
			InitList( &L);		//��ʼ������
			ReverseList(&L);				
			printf("\n\n\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			if (L->next==NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			DestroyList(&L);
			printf("ɾ������ɹ�\n\n\n");
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				break;
			}
			p = L->next;
			TraverseList(L, visit);
			printf("������Ҫ�����λ�õ�ǰһ���������ݣ�");
			scanf_s("%d", &a);
			while (p!=NULL&&p->data != a)
			{
				p = p->next;										//Ѱ�ҵ�����������������ȵĽ��p
			}
			if (p==NULL)	printf("�����ݲ�����������\n");			//�жϸ������Ƿ���������
			else
			{
				printf("������Ҫ�������ݣ�");
				scanf_s("%d", &a);
				n->data = a;
				InsertList(p, n);
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
				break;
			}

			TraverseList(L, visit);
			printf("��������Ҫɾ���Ľ���ǰһ����������:");
			scanf_s("%d", &a);
			p = L->next;
			while (p!=NULL&&p->data != a)
			{
				p = p->next;										//Ѱ�ҵ�����������������ȵĽ��p
			}
			if (p == NULL)	printf("�����ݲ�����������\n");			//�жϸ������Ƿ���������
			else
			{
				DeleteList(p, &a);
				
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
				break;
			}
			TraverseList(L, visit);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				break;
			}
			printf("����������Ҫ���ҵ�����:");
			scanf_s("%d", &a);
			fgets(ch, 20, stdin);
			x=SearchList(L, a);
			if (x == 1)
				printf("%d��������\n", a);
			else printf("%d����������\n",a);
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				break;
			}
			ReverseList(&L);
			printf("��ת����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				break;
			}
			x=IsLoopList(L);
			if (x == 1)	printf("��ѭ������\n");
			else printf("����ѭ������\n");
			system("pause");
			system("cls");
			break;				
		case 9:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				break;
			}
			ReverseEvenList(&L);
			printf("��ż�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			if (L->next == NULL)
			{
				printf("����Ϊ�գ����ʼ������\n");
				system("pause");
				break;
			}
			p=FindMidNode(&L);
			printf("������м�ֵΪ%d\n", p->data);
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