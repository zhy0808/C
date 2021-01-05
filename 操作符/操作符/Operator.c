#include<stdio.h>
#include<windows.h>
int i;                      //全局变量未初始化会被默认初始化为0
int main()
{
	i--;
	if (i > sizeof(i))       //sizeof返回值为无符号整型，比较时i被转化成无符号数，-1的无符号数远大于4
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	/*int i = 1;
	int ret = (++i) + (++i) + (++i);       //执行顺序不确定
	printf("ret=%d\n",ret);*/
	system("pause");
	return 0;
}
