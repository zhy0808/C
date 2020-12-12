#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Print(int a)                //Pr(12345)  打印5   调用Pr(1234)  打印4   调用PR（123）  打印3  调用Pr（12）  打印2 调用Pr（1）  打印1
{
	
	if (a > 9)
	{
		Print(a / 10);
	}
    printf("%d\n",a%10);

}
int main()
{
	int x = 0;
	printf("请输入一个数：");
	scanf("%d",&x);
	Print(x);
	system("pause");
	return 0;
}