#include<stdio.h>
#include<windows.h>

void Bubble_sort(int *arr, int size)
{
	for (int j = 1; j < size; j++)
	{
		int flag = 0;
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
	for (int k = 0; k < size; k++)
	{
		printf("%d ",arr[k]);
	}
}
int main()
{
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	int size = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr,size);
	system("pause");
	return 0;
}