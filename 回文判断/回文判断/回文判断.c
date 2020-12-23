#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define Size 100

typedef struct
{
	char elem[Size];
	int top;
}Stack;
void InitStack(Stack *S)
{
	S->top = -1;
}
void Push(Stack *S, char x)
{
	if (S->top == Size - 1)
		printf("ջ����\n");
	S->top++;
    S->elem[S->top] = x;
}
void Pop(Stack *S, char *x)
{
	if (S->top == -1)
		printf("ջ�ѿ�\n");
	*x = S->elem[S->top];
	S->top--;
}
void Judge(Stack *S, char str[])
{
	char x;
	int i = 0;
	printf("�������ж�������&�����@������\n");
	gets(str);                     //���������д���������
	while(str[i]!='&')
	{
		Push(S,str[i]);
		i++;
	}
	i = i + 1;
	while (S->top != -1&&str[i]!='@')
	{
		Pop(S, &x);
		if (x == str[i])
			i++;
		else
			break;
	}
	if (S->top == -1&&str[i]=='@')
		printf("������Ϊ��������\n");
	else
		printf("�����в��ǻ�������\n");
}
int main()
{
	Stack S;
	char str[Size];
	char x=0;
	InitStack(&S);
	Push(&S,x);
	Pop(&S, &x);
	Judge(&S,str);
	system("pause");
	return 0;
}