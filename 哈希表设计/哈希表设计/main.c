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
int Hashfunction(int k)           //哈希函数：除留余数法计算哈希地址
{
	int h = (k % 29);
	return h;                      //返回值为关键字在哈希表中的地址
}
void CreateClass(stu *arr, Hashtable *ht)
{
	int n = 0;
	printf("输入你要记录的人数：");
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		int knum = 0;
		printf("请输入姓名和数据结构成绩:\n");
		scanf(" %s %d",arr[i].name,&arr[i].score);
		int size = strlen(arr[i].name);
		for (int j = 0; j < size; j++)        //将输入的姓名转化为关键字
		{
			knum += arr[i].name[j];
		}
		int h=Hashfunction(knum);               //利用关键字确定存入哈希表中的具体位置
		for (int k = h; k < 29; k++)      
		{
			if (ht[h].key == 0)               //存入位置为空则存入，若不为空则向后存
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
	printf("请输入要查找的人名：");
	scanf("%s",n);
	int size = strlen(n);
	int k = 0;
	for (int i = 0; i < size; i++)          //将输入的姓名转化为关键字
	{
		k += n[i];
	}
	int h = Hashfunction(k);                //利用该关键字找哈希表中具体位置
	if (ht[h].key == k)                     //比较该位置中元素信息与要找的信息是否匹配
		printf("你找的人在哈希表中的位置为：%d\n姓名为:%s\n成绩为:%d\n", h,ht[h].person.name,ht[h].person.score);
	else if (ht[h].key == 0)
		printf("查无此人！\n");
	else                                    //线性探测再散列法处理冲突，即向后继续查找
	{
		int i;
		for (i = h; i < 29; i++)
		{
			h += 1;
			if (ht[h].key == k)
				printf("你找的人在哈希表中的位置为：%d\n",h);
		}
		if (i == 29)
			printf("查无此人！\n");
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