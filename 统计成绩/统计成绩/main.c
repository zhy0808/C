#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct
{
	char name[20];
	int score;
	int num;
}stu;
void Create(stu student[],int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("�������%d��ѧ��ѧ�š��������ɼ���\n",i+1);
		scanf(" %d %s %d",&student[i].num,student[i].name,&student[i].score);
	}
}
void NumSort(stu student[],int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (student[j].num>student[j + 1].num)
			{
				stu temp = student[j + 1];
				student[j + 1] = student[j];
				student[j] = temp;
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
void ScoreSort(stu student[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (student[j].score < student[j + 1].score)
			{
				stu temp = student[j + 1];
			    student[j + 1] = student[j];
			    student[j] = temp;
			    flag = 1;
		    }
			if (student[j].score == student[j + 1].score)
			{
				if (student[j].num>student[j + 1].num)
				{
					stu temp = student[j + 1];
					student[j + 1] = student[j];
					student[j] = temp;
				}
			}
	    }
	    if (!flag)
		   break;
    }
}
void Print(stu student[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d %s %d\n", student[i].num, student[i].name, student[i].score);
	}
}
int main()
{
	int n;
	printf("������ͳ��������");
	scanf("%d", &n);
	stu student[20] = {0};
	Create(student,n);
	NumSort(student,n);
	printf("��ѧ�������\n");
	Print(student,n);
	ScoreSort(student,n);
	printf("���ɼ������\n");
	Print(student, n);
	system("pause");
	return 0;
}