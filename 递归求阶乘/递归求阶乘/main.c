#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Factorial(int n)
{
	if (n == 1)
		return 1;
	int m = n*Factorial(n - 1);
	return m;
}
int main()
{
	int n = 0;
	printf("请输入一个整数：");
	scanf("%d", &n);
	Factorial(n);
	printf("%d\n",Factorial(n));
	system("pause");
	return 0;
}