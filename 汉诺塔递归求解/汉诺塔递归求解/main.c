#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void hanoi(int n, char a, char b, char c)
{
	if (n > 0)
	{
		hanoi(n - 1, a, c, b);
		printf("����%d�����Ӵ�%c�ƶ���%c\n", n, a, b);
		hanoi(n - 1, c, b, a);
	}
}
int main()
{
	int n;
	char a = 'A',b='B',c='C';
	printf("������Ҫ�ƶ������Ӹ�����");
	scanf("%d", &n);
	hanoi(n, a, b, c);
	system("pause");
	return 0;
}