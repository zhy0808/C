#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define max 100
void YH_triangle(int n)
{
	int arr[max][max] = {1};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			printf("%d  ",arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	printf("ÇëÊäÈëËæ»úÊý£º\n");
	scanf("%d",&n);
	YH_triangle(n);
	system("pause");
	return 0;
}