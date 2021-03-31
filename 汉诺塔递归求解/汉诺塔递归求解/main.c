#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void hanoi(int n, char a, char b, char c)
{
	if (n > 0)
	{
		hanoi(n - 1, a, c, b);
		printf("将第%d个盘子从%c移动到%c\n", n, a, b);
		hanoi(n - 1, c, b, a);
	}
}
int main()
{
	int n;
	char a = 'A',b='B',c='C';
	printf("请输入要移动的盘子个数：");
	scanf("%d", &n);
	hanoi(n, a, b, c);
	system("pause");
	return 0;
}