#include<stdio.h>
#include<windows.h>
int i;                      //ȫ�ֱ���δ��ʼ���ᱻĬ�ϳ�ʼ��Ϊ0
int main()
{
	i--;
	if (i > sizeof(i))       //sizeof����ֵΪ�޷������ͣ��Ƚ�ʱi��ת�����޷�������-1���޷�����Զ����4
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	/*int i = 1;
	int ret = (++i) + (++i) + (++i);       //ִ��˳��ȷ��
	printf("ret=%d\n",ret);*/
	system("pause");
	return 0;
}
