#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void my_strncat(char *str1, char *str2, int n,int size)
{
	for (int i = 0; i < n&&str2[i] != NULL; i++)
	{
		str1[size+i] = str2[i];
	}
}
int main()
{
	int n;
	printf("ÊäÈë³¤¶È£º");
	scanf("%d",&n);
	char str1[20] = "Hello ";
	char str2[20] = "world!";
	int size = strlen(str1);
	my_strncat(str1,str2,n,size);
	puts(str1);
	system("pause");
	return 0;
}