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
		printf("栈已满\n");
	S->top++;
    S->elem[S->top] = x;
}
void Pop(Stack *S, char *x)
{
	if (S->top == -1)
		printf("栈已空\n");
	*x = S->elem[S->top];
	S->top--;
}
void Judge(Stack *S, char str[])
{
	char x;
	int i = 0;
	printf("请输入判断序列以&间隔以@结束：\n");
	gets(str);                     //将整个序列存入数组中
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
		printf("该序列为回文序列\n");
	else
		printf("该序列不是回文序列\n");
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