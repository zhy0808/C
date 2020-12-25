#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Jud_prime(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
				break;
			if (j == i - 1)
				printf("%d ",i);
		}
	}
}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入要判断的区间：");
	scanf("%d %d",&a,&b);
	Jud_prime(a,b);
	system("pause");
	return 0;
}