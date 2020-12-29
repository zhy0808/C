#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Common_divisor(int a, int b)
{
	int c = 1;
	while (c)
	{
		c = (a % b);
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	int a, b;
	printf("请输入两个数：");
	scanf("%d %d",&a,&b);
	Common_divisor(a,b);
	printf("最大公约数为：%d\n", Common_divisor(a, b));
	system("pause");
	return 0;
}