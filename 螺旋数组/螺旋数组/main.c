#include<stdio.h>     
#include<windows.h>
#pragma warning(disable:4996)
void Input(int arr1[][100], int n)
{
	
	int k = 1;
	int x = n*n;
	int m = n;
	int a = 1;
	int I[] = { 0, 1 };
	while (x--)
	{
		for (int i = 1; i < 2 * m; i++)
		{
			int b = i / (m + 1);
			I[b] = I[b] + a;
			arr1[I[0]][I[1]] = k;
			k++;
		}
		a = -a;
		m--;
	}
}
void Print(int arr1[][100], int n)
{
	for (int i = 1; i<=n; i++)
	{
		for (int j = 1; j<=n; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	printf("ÇëÊäÈënÖµ£º");
	scanf("%d", &n);
	int arr1[100][100];
	Input(arr1, n);
	Print(arr1, n);
	system("pause");
	return 0;
}
