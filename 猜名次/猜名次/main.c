#include<stdio.h>
#include<windows.h>

void Judge()                 //对a—e进行的名次所有可能的排列组合，如果符合要求，则打印当前名次的排列
{
	for (int a = 1; a <= 5; a++)
	{
		for (int b = 1; b <= 5; b++)
		{
			for (int c = 1; c <= 5; c++)
			{
				for (int d = 1; d <= 5; d++)
				{
					for (int e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3)==1&&(b == 2) + (e == 4)==1&&(c == 1) + (d == 2)==1&&(c == 5) + (d == 3)==1&&(e == 4) + (a == 1) == 1)
						{
							if (a*b*c*d*e==120)
							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
}
int main()
{
	Judge();
	system("pause");
	return 0;
}