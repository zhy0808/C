#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Prime_number(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		int j = 0;
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break;
		}
		if (j==i)
		printf("%d ", i);
	}
	printf("\n");
}
int main()
{
	int a, b;
	printf("输入打印区间：");
	scanf("%d %d",&a,&b);
	Prime_number(a,b);
	system("pause");
	return 0;
}