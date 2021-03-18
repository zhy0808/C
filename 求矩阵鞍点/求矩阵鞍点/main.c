#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Input(int arr[3][3])
{
	printf("请输入矩阵元素：");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void Find(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		int minj = 0;
		int maxi = i;
		int n,j;
		for (j = 0; j < 3; j++)
		{
			
			if (arr[i][minj]>arr[i][j])
			{
				minj = j;
			}
		}
		for (n = 0; n < 3; n++)
		{
			if (arr[maxi][minj] < arr[n][minj])
				break;
		}
		if (n < 3)
			continue;
		printf("第%d行 第%d列的%d为鞍点\n", i, j, arr[maxi][minj]);
	}
}
int main()
{
	int arr[3][3];
	Input(arr);
	Find(arr);
	system("pause");
	return 0;
}