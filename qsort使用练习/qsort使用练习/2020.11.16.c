#include<stdio.h>
#include<windows.h>
int compint(const void* _x, const void* _y)
{
	int *x = (int*)_x;
	int *y = (int*)_y;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	else
		return 0;

}
void print(int* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = {77,55,33,99,22,11,0,44,66,88};
	int num = sizeof(arr) / sizeof(arr[0]);
	print(arr,num);
	qsort(arr,num,sizeof(int),compint);
	print(arr,num);
	system("pause");
	return 0;
}