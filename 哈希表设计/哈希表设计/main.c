#include<stdio.h>
#include<string.h>
#include<windows.h>
#pragma warning(disable:4996)
typedef struct
{
	char name[30];
	int score;
}stu;
typedef struct
{
	int key;
	stu person;
}Hashtable;
int Hashfunction(int k)           //��ϣ���������������������ϣ��ַ
{
	int h = (k % 29);
	return h;                      //����ֵΪ�ؼ����ڹ�ϣ���еĵ�ַ
}
void CreateClass(stu *arr, Hashtable *ht)
{
	int n = 0;
	printf("������Ҫ��¼��������");
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int knum = 0;
		printf("���������������ݽṹ�ɼ�:\n");
		scanf(" %s %d",arr[i].name,&arr[i].score);
		int size = strlen(arr[i].name);
		for (int j = 0; j < size; j++)        //�����������ת��Ϊ�ؼ���
		{
			knum += arr[i].name[j];
		}
		int h=Hashfunction(knum);               //���ùؼ���ȷ�������ϣ���еľ���λ��
		for (int k = h; k < 29; k++)      
		{
			if (ht[h].key == 0)               //����λ��Ϊ������룬����Ϊ��������
			{
				ht[h].key = knum;
				ht[h].person = arr[i];
				break;
			}
			h += 1;
		}
	}
}
void HashSearch(Hashtable *ht)
{
	char n[20] = {0};
	printf("������Ҫ���ҵ�������");
	scanf("%s",n);
	int size = strlen(n);
	int k = 0;
	for (int i = 0; i < size; i++)          //�����������ת��Ϊ�ؼ���
	{
		k += n[i];
	}
	int h = Hashfunction(k);                //���øùؼ����ҹ�ϣ���о���λ��
	if (ht[h].key == k)                     //�Ƚϸ�λ����Ԫ����Ϣ��Ҫ�ҵ���Ϣ�Ƿ�ƥ��
		printf("���ҵ����ڹ�ϣ���е�λ��Ϊ��%d\n����Ϊ:%s\n�ɼ�Ϊ:%d\n", h,ht[h].person.name,ht[h].person.score);
	else if (ht[h].key == 0)
		printf("���޴��ˣ�\n");
	else                                    //����̽����ɢ�з������ͻ��������������
	{
		int i;
		for (i = h; i < 29; i++)
		{
			h += 1;
			if (ht[h].key == k)
				printf("���ҵ����ڹ�ϣ���е�λ��Ϊ��%d\n",h);
		}
		if (i == 29)
			printf("���޴��ˣ�\n");
	}
}
int main()
{
	stu arr[50];
	Hashtable ht[50] = {0};
	CreateClass(arr,ht);
	HashSearch(ht);
	system("pause");
	return 0;
}