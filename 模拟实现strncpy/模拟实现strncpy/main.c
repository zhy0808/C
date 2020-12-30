#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void my_strncpy(char * destination, const char * source, int num)
{
	const char *s = source;
	char *d = destination;
	int i;
	for ( i = 0; i < num; i++)
	{
		*(d+i) = *(s+i);
	}
	*(d + i) = '\0';
}
int main()
{
	char *source = "hello world!";
	char  dest[20];
	int num = 4;
	my_strncpy(dest,source,num);
	printf("%s\n",dest);
	system("pause");
	return 0;
}