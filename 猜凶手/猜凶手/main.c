#include<stdio.h>
#include<windows.h>

int main()
{
	for (int murder = 'A'; murder <= 'D'; murder++)            //����������ABCD
	{
		murder == 1;                                           //���赱ǰ��������������Ϊ����
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)  //�ж��Ƿ���������֤����ȷ������������֤����ȷ�����������Ϊ����
		{
			printf("murder is %c!\n",murder);
		}
	}

	system("pause");
	return 0;
}