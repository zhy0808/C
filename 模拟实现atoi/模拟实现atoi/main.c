#include<stdio.h>
#include<windows.h>

int my_atoi(char *a)
{
	int b = 0;
	int c = 1;
	if (*a == ' ')
		a++;
	if (*a == '-')
	{
		c = -1;
		a++;
	}
	while (*a >= '0' && *a <= '9')
	{
		b = b * 10 + (*a - '0');
		a++;
	}
	return b*c;
}
int main()
{
	char *a = "-123789";
	printf("%d\n",a);
	my_atoi(a);
	printf("%d\n",my_atoi(a));
	system("pause");
	return 0;
}