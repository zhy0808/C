#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct node
{
	int num;
	int key;
	struct node * next;
}node,*Linklist;
void Initlist(Linklist *L)//��ʼ��ѭ������
{
	(*L) = NULL;
}
void Joseph(Linklist *L,Linklist *r, int n)
{
	Linklist s;
	int k=0;
	int i=0;
	printf("������%d���˵�����:\n", n);
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
	printf("�������У�\n");
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
	int m = 0;                  //����
	int n = 0;  //����
	int i = 1;
	printf("�����������m��");
	scanf("%d", &m);
	printf("������������n��");
	scanf("%d", &n);
	Linklist L = NULL;          //ͷָ��
	node* r = NULL;          //βָ��
	Linklist p=L;
	Initlist(&L);
	Joseph(&L,&r,n);
	Game(r,m,n);
	system("pause");
	return 0;
}