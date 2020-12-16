#include<stdio.h>
#include<windows.h>

int main()
{
	int a = 0;
	int b = 0;
	for (int i = 1; i < 100; i++)
	{
		a = a + 1 / i;
		i++;
	}
	for (int j = 2; j <= 100; j++)
	{
		b = b + 1 / j;
		j++;
	}
	printf("%d\n",a-b);
	system("pause");
	return 0;
}