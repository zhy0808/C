#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void comp(int a, int b, int c)
{
	int temp;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c)
	{
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c)
	{
		temp = b;
		b = c;
		c = temp;
	}
	printf("a=%d,b=%d,c=%d",a,b,c);

}
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入三个数：");
	scanf("%d %d %d",&a,&b,&c);
	comp(a,b,c);
	system("pause");
	return 0;
}