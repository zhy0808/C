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
		printf("�����һ��0-99������");
		scanf("%d",&a);
		if (a > result_rand)
			printf("��´���\n");
		else if (a < result_rand)
			printf("���С��\n");
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
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
				printf("�����������������\n");
				break;
		}
	} while (input);
	system("pause");
	return 0;
}