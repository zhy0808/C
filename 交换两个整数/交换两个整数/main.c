#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Exchange(int *a, int *b)   //传地址会改变实参的值
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a=%d,b=%d",*a,*b);
}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个数：");
	scanf("%d %d",&a,&b);
	Exchange(&a,&b);
	system("pause");
	return 0;
}