#include<stdio.h>
#include<windows.h>

int main()
{
	int count = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	printf("%d",count);
	system("pause");
	return 0;
}