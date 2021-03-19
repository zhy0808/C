#include<stdio.h>
#include<windows.h>
void Number_pairs(int arr[], int num)
{
	int parnums[10][10] = { 0 };
	int i, j;
	for (i = 0; i < num - 1; i++)
	{
		j = i + 1;
		parnums[arr[i]][arr[j]]++;
	}
	for (i = 0; i < num - 1; i++)
	{
		j = i + 1;
		if (parnums[arr[i]][arr[j]]>0 && arr[i] == arr[j])
		{
			printf("(%d,%d) = %d\n", arr[i], arr[j], parnums[arr[i]][arr[j]]);
			parnums[arr[i]][arr[j]] = 0;
		}
		if (parnums[arr[i]][arr[j]]>0 && parnums[arr[j]][arr[i]]>0 )
		{
			printf("(%d,%d) = %d (%d,%d) = %d\n", arr[i], arr[j], parnums[arr[i]][arr[j]], arr[j], arr[i], parnums[arr[j]][arr[i]]);
			parnums[arr[i]][arr[j]] = 0;
		}
	}
}
int main()
{
	int arr[] = {0,1,5,9,8,7,2,2,2,3,2,7,8,7,8,7,9,6,5,9};
	int num = sizeof(arr) / sizeof(arr[0]);
	Number_pairs(arr, num);
	system("pause");
	return 0;
	
}