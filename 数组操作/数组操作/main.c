#include<stdio.h>
#include<windows.h>
void init(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 0;
	}
}
void print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void reverse(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size-i; j++)
		{
			int temp = arr[j + 1];
			arr[j + 1]=arr[j];
			arr[j] = temp;
		}
	}
	print(arr,size);
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	init(arr,size);
	print(arr, size);
	reverse(arr, size);
	system("pause");
	return 0;
}