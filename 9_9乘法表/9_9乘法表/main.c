#include<stdio.h>
#include<windows.h>

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d  ",j,i,i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}