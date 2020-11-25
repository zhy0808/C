#include<stdio.h>
#include<windows.h>
void Search(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == arr[j] && i != j)
				break;
			if (j == size - 1)
				printf("µ¥Éí¹·ÊÇ:%d\n",arr[i]);
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 9, 3, 4, 6, 5, 4, 3, 2, 1, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Search(arr,size);
	system("pause");
	return 0;
}