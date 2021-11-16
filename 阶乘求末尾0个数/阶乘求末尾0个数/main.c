#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Fact(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		int num = i;
		while (num)
		{
			if (num % 5 == 0)
			{
				count++;
				num /= 5;
			}
			else
				break;
		}
	}
	printf("该相乘数字末尾有%d个0\n", count);
}
int main()
{
	int n = 0;
	printf("请输入整数n：");
	scanf("%d", &n);
	Fact(n);
	system("pause");
	return 0;
}