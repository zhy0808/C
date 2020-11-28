#include<stdio.h>
#include<windows.h>
#define size 10
void Print(int arr[])
{
	for (int j = 0; j < size; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
}
void Exchange(int *arr1, int *arr2)
{
	for (int i = 0; i < size; i++)
	{
		int temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
	printf("½»»»ºó\n");
	Print(arr1);
	Print(arr2);
}
int main()
{
	int arr1[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Print(arr1);
	int arr2[size] = { 91, 92, 93, 94, 95, 96, 97, 98, 99, 100 };
	Print(arr2);
	Exchange(arr1,arr2);
	system("pause");
	return 0;
}