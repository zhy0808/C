#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Exchange(int *a, int *b)   //����ַ��ı�ʵ�ε�ֵ
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
	printf("��������������");
	scanf("%d %d",&a,&b);
	Exchange(&a,&b);
	system("pause");
	return 0;
}