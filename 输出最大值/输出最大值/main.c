#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Scan(int arr[])
{
	printf("请输入10个整数：\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
	}
}
void Comp(int *arr,int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			arr[i+1] = arr[i];
		}
	}
	printf("Max=%d\n",arr[size-1]);
}
int main()
{
	int arr[100] = {0};
	Scan(arr);
	int size = sizeof(arr) / sizeof(arr[0]);
	Comp(arr,size);
	system("pause");
	return 0;
}