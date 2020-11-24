#include<stdio.h>
#include<windows.h>
#include<assert.h>
#include<stdlib.h>
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
int compchar(const void* _xp,const void* _yp)
{
	char *x = (char*)_xp;
	char *y = (char*)_yp;
	if (*x>*y)
		return 1;
	else if (*x < *y)
		return -1;
	else
		return 0;
}
void swap(char* src, char*dst, int size)
{
	while (size)
	{
		char temp = *src;
		*src = *dst;
		*dst = temp;
		size--;
		src++;
		dst++;
	}
}
void my_qsort(void* arr, int num, int size, int(*comp)(const void*, const void*))
{
	assert(arr!=NULL);
	assert(comp!=NULL);
	char *p = (char*)arr;
	int flag = 0;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (comp(p + j*size, p + (j + 1)*size)>0)
			{
				swap(p + j*size, p + (j + 1)*size, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
void print(int* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = {2,6,4,87,89,13,43,87,44,88};
	char arr1[] = {'c','a','b','h','f','e','g','d'};
	int num = sizeof(arr) / sizeof(arr[0]);
	print(arr, num);
	qsort(arr,num,sizeof(int),compint);
	my_qsort(arr,num,sizeof(int),compint);
	print(arr,num);
	system("pause");
	return 0;
}