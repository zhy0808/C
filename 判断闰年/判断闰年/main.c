#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Jud_leapyear(int y)
{
	if ((y % 4 == 0) && (y % 100 != 0))
		printf("%d��������\n",y);
	else
		printf("%d�겻������\n",y);
}
int main()
{
	int x = 0;
	printf("������Ҫ�жϵ���ݣ�");
	scanf("%d",&x);
	Jud_leapyear(x);
	system("pause");
	return 0;
}