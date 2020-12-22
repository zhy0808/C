#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Print(int arr[])
{
	int size = 11;
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Insert(int arr[],int size)
{
	int x = 0;
	printf("请输入要插入的数：");
	scanf("%d", &x);
	int min = 0;
	int max = size - 1;
	int mid = (max + min) / 2;
	while (max!=min)
	{
		if (x>mid)
		{
			min = mid + 1;
		}
		else if (x < mid)
		{
			max = mid - 1;
		}
		else
			break;
		mid = (max + min) / 2;
	}
	if (x >= arr[mid])
	{
		if (mid == size - 1)
			arr[size] = x;
		else
		{
			for (int i = size; i > mid; i--)
			{
				arr[i] = arr[i - 1];
			}
			arr[mid + 1] = x;
		}
	}
	else
	{
		for (int i = size; i>=mid; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[mid] = x;
	}
	Print(arr);
}
int main()
{
	int arr[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = 10;
	Insert(arr,size);
	system("pause");
	return 0;
}