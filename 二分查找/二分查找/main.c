#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void lookup(int arr[],int size,int a)
{
	int low = 0;
	int high = size-1;
	while (high >= low)
	{
		int mid = (high + low) / 2;
		if (arr[mid] < a)
		{
			low = mid + 1;
		}
		else if (arr[mid] > a)
		{
			high = mid - 1;
		}
		else
		{
			printf("%d所在下标为%d\n", a,mid);
			break;
		}
	}
	if (high<low)
		printf("Can't find!\n");
}
int main()
{
	int a;
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	printf("请输入查找的数：");
	scanf("%d",&a);
	int size = sizeof(arr) / sizeof(arr[0]);
	lookup(arr,size,a);
	system("pause");
	return 0;
}