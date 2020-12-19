#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct node
{
	int num;
	int key;
	struct node * next;
}node,*Linklist;
void Initlist(Linklist *L)//初始化循环链表
{
	(*L) = NULL;
}
void Joseph(Linklist *L,Linklist *r, int n)
{
	Linklist s;
	int k=0;
	int i=0;
	printf("请输入%d个人的密码:\n", n);
	while (i < n)
	{
		s = (node*)malloc(sizeof(node));
		scanf("%d",&k);
		s->key= k;
		s->num = i+1;
		if (i == 0)
		{
			*L = s;
			*r = s;
			(*r)->next = (*L);
		}
		else
		{
			(*r)->next = s;
			*r = s;
			(*r)->next =(*L);
		}
		i++;
	}
}
void Game(Linklist r, int m, int n)
{
	node *p;
	node *q;
	p = r;
	q = r;
	int i = 0;
	printf("出队序列：\n");
	while (n)
	{
		for (i = 1; i <= m; i++)
		{
			q = p;
			p = p->next;
		}
		printf("%d ", p->num);
		m = p->key;
		q->next = p->next;
		free(p);
		p = q;
		n--;
	}
	printf("\n");
}
int main()
{
	int m = 0;                  //出列
	int n = 0;  //人数
	int i = 1;
	printf("请输入随机数m：");
	scanf("%d", &m);
	printf("请输入总人数n：");
	scanf("%d", &n);
	Linklist L = NULL;          //头指针
	node* r = NULL;          //尾指针
	Linklist p=L;
	Initlist(&L);
	Joseph(&L,&r,n);
	Game(r,m,n);
	system("pause");
	return 0;
}