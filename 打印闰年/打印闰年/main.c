#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Leap_year(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		if (i % 4 == 0 && i % 100 != 0)
		{
			printf("%d ",i);
		}
	}
}
int main()
{
	int a, b;
	printf("请输入打印区间：");
	scanf("%d %d",&a,&b);
	Leap_year(a,b);
	system("pause");
	return 0;
}