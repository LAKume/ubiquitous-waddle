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
		printf("初始化失败\n");
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
		printf("---------------------------------------双链表的基本操作---------------------------------------\n");
		printf("					-请输入一个整数来选择所需要的功能：\n");
		printf("\n\n");
		printf("					-1.初始化链表\n");
		printf("					-2.销毁链表\n");
		printf("					-3.在结点前插入一个数据\n");
		printf("					-4.在结点后插入一个数据\n");
		printf("					-5.删除一个数据\n");
		printf("					-6.输出链表\n");
		printf("					-0.退出bug屋\n请输入一个整数：");
		scanf_s("%d", &i);
		gets_s(ch, 40);

		switch (i)
		{
		case 1:
			system("cls");
			if (L->next != NULL)
			{
				printf("请先清空链表\n");
				system("pause");
				system("cls");
				break;
			}
			InitList_DuL(&L);		//初始化链表
			printf("\n\n\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
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
				printf("链表为空，请初始化链表\n");
				system("pause");
				system("cls");
				break;
			}
			p = L->next;
			TraverseList_DuL(L, visit);
			printf("请输入要插入的位置的后一个结点的数据：");
			scanf_s("%d", &a);
			while (p != NULL && p->data != a)
			{
				p = p->next;										//寻找到数据与输入数据相等的结点p
			}
			if (p == NULL)	printf("该数据不存在于链表\n");			//判断该数据是否在链表中
			else
			{
				printf("请输入要插入数据：");
				scanf_s("%d", &a);
				n->data = a;
				InsertBeforeList_DuL(p, n);
				printf("插入成功\n");
			}
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				system("cls");
				break;
			}			p = L->next;
			TraverseList_DuL(L, visit);
			printf("请输入要插入的位置的前一个结点的数据：");
			scanf_s("%d", &a);
			while (p != NULL && p->data != a)
			{
				p = p->next;										//寻找到数据与输入数据相等的结点p
			}
			if (p == NULL)	printf("该数据不存在于链表\n");			//判断该数据是否在链表中
			else
			{
				printf("请输入要插入数据：");
				scanf_s("%d", &a);
				n->data = a;
				InsertAfterList_DuL(p, n);
				printf("插入成功\n");
			}
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				system("cls");
				break;
			}
			p = L->next;
			TraverseList_DuL(L, visit);
			printf("请输入要删除的结点的前一个结点的数据：");
			scanf_s("%d", &a);
			while (p != NULL && n->data != a)
				p = p->next;
			if(p==NULL)	printf("该数据不存在于链表\n");			//判断该数据是否在链表中
			else
				DeleteList_DuL(p, &a);
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
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
			printf("感谢观看\n");
			system("pause");
			return 0;
		default:
			system("cls");
			printf("请输入正确的整数\n");
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}
