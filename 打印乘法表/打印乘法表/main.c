#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void Print(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d ",j,i,i*j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	printf("�������ӡ�˷���Ľ�����");
	scanf("%d",&n);
	Print(n);
	system("pause");
	return 0;
}