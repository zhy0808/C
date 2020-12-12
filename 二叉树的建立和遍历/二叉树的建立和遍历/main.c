#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct Node
{
	char data;
	struct Node* Lchild;
	struct Node* Rchild;
}Bitnode,*Bittree;


void CreateTree(Bittree *root)
{
	char a = 0;
	a = getchar();
	if (a == '*')
		*root = NULL;
	else
	{
		*root = (Bittree)malloc(sizeof(Bitnode));
		(*root)->data = a;
		CreateTree(&((*root)->Lchild));
		CreateTree(&((*root)->Rchild));
	}
}
void PreOrder(Bittree root)
{
	
	if (root!=NULL)
	{
		printf("%c", root->data);
		PreOrder(root->Lchild);
		PreOrder(root->Rchild);
	}
}
void InOrder(Bittree root)
{
	if (root != NULL)
	{
		InOrder(root->Lchild);
		printf("%c", root->data);
		InOrder(root->Rchild);
	}
}
void PostOrder(Bittree root)
{
	if (root != NULL)
	{
		PostOrder(root->Lchild);
		PostOrder(root->Rchild);
		printf("%c", root->data);
	}
}
int main()
{
	Bittree tree;
	printf("������һ�������������У�");
	CreateTree(&tree);
	printf("��������Ϊ��");
	PreOrder(tree);
	printf("\n");
	printf("��������Ϊ��");
	InOrder(tree);
	printf("\n");
	printf("��������Ϊ��");
	PostOrder(tree);
	printf("\n");
	system("pause");
	return 0;
}