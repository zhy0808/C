#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void comp(int a, int b)
{
	if (a > b)
		printf("%d>%d\n", a, b);
	else if (a < b)
		printf("%d<%d\n", a, b);
	else
		printf("���\n");
}
int main()
{
	int a = 0;
	int b = 0;
	printf("��������������");
	scanf("%d %d",&a,&b);
	comp(a,b);
	system("pause");
	return 0;
}