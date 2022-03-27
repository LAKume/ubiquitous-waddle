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
		printf("初始化失败\n");
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
		printf("					欢迎来到倒水工人-楽-的bug屋\n");
		printf("					-请输入一个整数来选择所需要的功能：\n");
		printf("\n\n");
		printf("					-1.初始化链表\n");
		printf("					-2.清空链表\n");
		printf("					-3.插入一个数据\n");
		printf("					-4.删除一个数据\n");
		printf("					-5.输出链表\n");
		printf("					-6.查找数据是否纯在于链表中\n");
		printf("					-7.反转链表\n");
		printf("					-8.判断是否为循环链表\n");
		printf("					-9.对链表进行奇偶互换操作\n");
		printf("					-10.输出链表的中间值\n");
		printf("					-0.退出bug屋\n请输入一个整数：");
		scanf_s("%d", &i);
		gets_s(ch,40);

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
			InitList( &L);		//初始化链表
			ReverseList(&L);				
			printf("\n\n\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			if (L->next==NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				system("cls");
				break;
			}
			DestroyList(&L);
			printf("删除链表成功\n\n\n");
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				break;
			}
			p = L->next;
			TraverseList(L, visit);
			printf("请输入要插入的位置的前一个结点的数据：");
			scanf_s("%d", &a);
			while (p!=NULL&&p->data != a)
			{
				p = p->next;										//寻找到数据与输入数据相等的结点p
			}
			if (p==NULL)	printf("该数据不存在于链表\n");			//判断该数据是否在链表中
			else
			{
				printf("请输入要插入数据：");
				scanf_s("%d", &a);
				n->data = a;
				InsertList(p, n);
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
				break;
			}

			TraverseList(L, visit);
			printf("请输入所要删除的结点的前一个结点的数据:");
			scanf_s("%d", &a);
			p = L->next;
			while (p!=NULL&&p->data != a)
			{
				p = p->next;										//寻找到数据与输入数据相等的结点p
			}
			if (p == NULL)	printf("该数据不存在于链表\n");			//判断该数据是否在链表中
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
				printf("链表为空，请初始化链表\n");
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
				printf("链表为空，请初始化链表\n");
				system("pause");
				break;
			}
			printf("请输入你所要查找的数据:");
			scanf_s("%d", &a);
			fgets(ch, 20, stdin);
			x=SearchList(L, a);
			if (x == 1)
				printf("%d在链表中\n", a);
			else printf("%d不在链表中\n",a);
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				break;
			}
			ReverseList(&L);
			printf("反转链表成功\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				break;
			}
			x=IsLoopList(L);
			if (x == 1)	printf("是循环链表\n");
			else printf("不是循环链表\n");
			system("pause");
			system("cls");
			break;				
		case 9:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				break;
			}
			ReverseEvenList(&L);
			printf("奇偶互换成功\n");
			system("pause");
			system("cls");
			break;
		case 10:
			system("cls");
			if (L->next == NULL)
			{
				printf("链表为空，请初始化链表\n");
				system("pause");
				break;
			}
			p=FindMidNode(&L);
			printf("链表的中间值为%d\n", p->data);
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