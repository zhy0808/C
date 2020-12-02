#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable:4996)
void menu()
{
	printf("############1.GAME##########\n");
	printf("############0.exit##########\n");
}
void GAME()
{
	int result_rand = rand() % 100;
	int a = 0;
	while (1)
	{
		printf("请你猜一个0-99的数：");
		scanf("%d",&a);
		if (a > result_rand)
			printf("你猜大了\n");
		else if (a < result_rand)
			printf("你猜小了\n");
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
}

int main()
{
	srand((int)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case(1):
				GAME();
				break;
		case(0):
				break;
		default:
				printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
	system("pause");
	return 0;
}