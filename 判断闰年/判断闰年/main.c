#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Jud_leapyear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0))
		printf("%d年是闰年\n",y);
	else
		printf("%d年不是闰年\n",y);
}
int main()
{
	int x = 0;
	printf("请输入要判断的年份：");
	scanf("%d",&x);
	Jud_leapyear(x);
	system("pause");
	return 0;
}