#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Factorial(int n)
{
	int m = 1;
	for (int i = 1; i <= n; i++)
	{
		m = m*i;
	}
	printf("%d\n",m);
}
int main()
{
	int n = 0;
	printf("请输入一个整数：");
	scanf("%d",&n);
	Factorial(n);
	system("pause");
	return 0;
}