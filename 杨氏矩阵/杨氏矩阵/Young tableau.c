#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
#define row 3
#define col 3
int found(int arr[row][col],int n)
{
	int r = 0;
	int c = 0;
	while (r >= 0&&r <row&&c < col)
	{
		if (arr[r][c] < n)
		{
			r++;
			if (r == row)
			{
				r--;
				c++;
			}
		}
		else if (arr[r][c]>n)
			c--;
		else
			return 1;
	}
	return 0;

}
int main()
{
	int arr[row][col] = {1,2,3,4,5,6,7,8,9};
	int n = 0;
	printf("请输入一个整数：");
	scanf("%d",&n);
	found(arr,n);
	if (found(arr, n) == 1)
		printf("found!\n");
	else
		printf("no found!\n");
	system("pause");
	return 0;
}