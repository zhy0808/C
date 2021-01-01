#include<stdio.h>
#include<windows.h>
int judge(char s1[], char s2[], int size1, int size2)
{
	if (size1 != size2)
		return 0;
	int flag = 0;
	if (s1[0] == s2[size2 - 1] && s1[size1 - 1] == s2[0])
	{
		for (int i = 1; i < size1 - 1; i++)
		{
			if (s1[i] == s2[i])
				flag = 1;
			else
				flag = 0;;
		}
		return flag;
	}
	else
		return 0;
}
int main()
{
	
	char s1[] = {'A','A','B','C','D'};
	char s2[] = {'D','A','B','C','A'};
	int size1 = sizeof(s1) / sizeof(s1[0]);
	int size2 = sizeof(s2) / sizeof(s2[0]);
	judge(s1,s2,size1,size2);
	printf("%d:Á½×Ö·û´®ÊÇÐý×ª×Ö·û´®\n",judge(s1,s2,size1,size2));
	system("pause");
	return 0;
}