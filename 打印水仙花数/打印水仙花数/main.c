#include <stdio.h>
#include <windows.h>
#include <math.h>
int main()
{
	for (int x = 0; x <= 100000; x++)
	{
		int n = 1;
		int X1 = x;
		int X2 = x;
		int Sn = 0;
		while (1)
		{
			if (X1 / 10 != 0)
			{
				X1 = (X1 / 10);
				n++;
			}
			else
				break;
		}
		for (int i = 0; i < n; i++)
		{
			Sn = pow((X2 % 10), n) +Sn;
			X2 = (X2 / 10);
		}
		if (Sn == x)
			printf("%d 为水仙花数\n",x);
	}
	system("pause");
	return 0;
}