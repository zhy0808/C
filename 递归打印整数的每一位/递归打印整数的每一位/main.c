#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
int Print(int a)                //Pr(12345)  ��ӡ5   ����Pr(1234)  ��ӡ4   ����PR��123��  ��ӡ3  ����Pr��12��  ��ӡ2 ����Pr��1��  ��ӡ1
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
	printf("������һ������");
	scanf("%d",&x);
	Print(x);
	system("pause");
	return 0;
}