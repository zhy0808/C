#include<stdio.h>
#include<windows.h>

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d ",i);
		}
	}
	system("pause");
	return 0;
}