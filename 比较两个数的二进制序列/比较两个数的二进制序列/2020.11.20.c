#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void comp(int num)
{
	int count = 0;
	int flag = 1;
	while (num)
	{
		if (num&flag)
		{
			count++;
		}
		num=num >> 1;
	}
	printf("%d\n",count);
}
int main()
{
	int m = 0;
	int n = 0;
	printf("请输入两个数：");
	scanf("%d %d",&m,&n);
	int num = m^n;
	comp(num);
	system("pause");
	return 0;
}