#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void Search(int arr[][3])
{
	int n = 0;
	int i = 0;
	int j = 2;
	printf("请输入要查找的数字：");
	scanf(" %d", &n);
	while (j>=0&&i<3)
	{
		if (n > arr[i][j])
		{
			i++;
		}
		else if (n < arr[i][j])
		{
			j--;
		}
		else
		{
			printf("Find!");
			break;
		}
	}
	if (j < 0 || i > 2)
	{
		printf("Not find！");
	}

	

}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Search(arr);
	system("pause");
	return 0;
}