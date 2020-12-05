#include<stdio.h>
#include<windows.h>

int main()
{
	for (int murder = 'A'; murder <= 'D'; murder++)            //遍历嫌疑人ABCD
	{
		murder == 1;                                           //假设当前遍历到的嫌疑人为凶手
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)  //判断是否有三个人证词正确，若有三个人证词正确，则该嫌疑人为凶手
		{
			printf("murder is %c!\n",murder);
		}
	}

	system("pause");
	return 0;
}