#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void print(char arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c",arr[i]);
	}
	printf("\n");
}
void L_rotate(char arr[], int k,int size)
{
	while (k)
	{
		char temp = arr[0];
		for (int i = 0; i < size; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[size - 1] = temp;
		k--;
	}
	
}
int main()
{
	int k = 0;
	char arr[] = {'a','b','c','d','e','f','g'};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("����������������");
	scanf("%d",&k);
	printf("��תǰ��   ");
	print(arr, size);
	L_rotate(arr, k,size);
	printf("����%d�κ�",k);
	print(arr, size);
	system("pause");
	return 0;
}