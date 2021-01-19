#include<stdio.h>
#include<windows.h>
#include<string.h>
#pragma warning(disable:4996)
#define Max 1000
typedef struct
{
	char c;
	int weight;
	int Lchild;
	int Rchild;
	int parent;
}hfmtree;
void Menu()
{
	printf("##############################################\n");
	printf("#########0.退出              1.存原码#########\n");
	printf("#########2.编码              3.译码###########\n");
	printf("#########4.显示哈夫曼编码    #################\n");
	printf("##############################################\n");
}
int min[2] = { 0 };
void Print(char *hc[],int n)
{
	if (hc[1] == NULL)
	{
		printf("error：您还未进行编码操作，请编码后再试...\n");
		return;
	}
	printf("编码为:");
	for (int i = 1; i <= n; i++)
	{
		printf("%s", hc[i]);
	}
	printf("\n");
}
int *Slect(hfmtree ht[], int m,int n)                          //挑出当前树中权值最小且没有parent的节点下标
{
	for (int j = 1; j <= m; j++)                         //两个起始查找位置不能相同。若相同 min[0]拿到当前位置下标，min[1]由于未找到更小的，还是现在的下标值，两值相同
	{
		if (ht[j].parent == 0)
		{
			min[0] = j;
			break;
		}
	}
	for (int j = m; j >= 1; j--)
	{
		if (ht[j].parent == 0)
		{
			min[1] = j;
			break;
		}
		

	}
	for (int i = 1; i <= m; i++)                                //从左至右挑出第一个权值最小的位置
	{
		if (ht[min[0]].weight > ht[i].weight&&ht[i].parent == 0)
			min[0] = i;
	}
	for (int j = 1; j <= m; j++)                                //从右至左挑出第一个与上面不同的权值最小的位置
	{
		if (min[1] == min[0]||ht[min[1]].parent!=0)
			min[1]--;
		if (ht[min[1]].weight > ht[j].weight&&min[0] != j&&ht[j].parent == 0)
			min[1] = j;
	}
	if (ht[min[0]].weight == ht[min[1]].weight)                 //如果此时两个权值相同，且其中一个是合并的结果，则将原字符的位置放在右边，充当右子树
	{
		int temp = min[0];
		min[0] = min[1];
		min[1] = temp;
	}
	if (min[0] <= n&&min[1] > n)                                 //保证生成树的过程中，原权值在右子树
	{
		int temp = min[0];
		min[0] = min[1];
		min[1] = temp;
	}
	return min;
}
void Merge(hfmtree ht[],int n)
{
	int m = n;
	for (int j = n + 1; j <= 2 * n - 1; j++)
	{
		int *min = Slect(ht, m, n) ;                        //将当前哈夫曼树中两个最小权值的下标找出
		int s1 = min[0];
		int s2 = min[1];
		ht[j].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = j;
		ht[s2].parent = j;
		ht[j].Lchild = s1;
		ht[j].Rchild = s2;
		m++;
	}
	
}


void Creathfm(hfmtree ht[],int n)
{
	if (n <= 1)
	{
		printf("error：请输入大于1的整数...\n");
		return;
	}
	if (n > Max)
	{
		printf("error:存入数据过大！...\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("请输入第%d个字符及其权值：", i);
		scanf(" %c %d", &ht[i].c, &ht[i].weight);
	}
	Merge(ht,n);                                   //合并
	FILE * pFile;                                  //打开文件
	pFile = fopen("hfmtree.txt", "w");            //文件操作
	if (pFile != NULL)
	{
		for (int i = 1; i <= n; i++)
		{
			fprintf(pFile," %c %d", ht[i].c, ht[i].weight);
		}
		fclose(pFile);
	}
	
	printf("存入成功！\n");
}

void  Encoding(hfmtree ht[], int n, char *hc[Max])
{
	if (ht[1].c == NULL)
	{
		printf("error: 存入错误或未存入字符及权值...\n");
		return;
	}
	char code[Max] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		char code1[Max] = { 0 };
		int j = 0;
		int p = ht[i].parent;
		int child = i;
		while (p != 0)                                    //从叶子结点到根节点依次编码
		{
			if (ht[p].Lchild == child)
				code[j] = '1';
			else
				code[j] = '0';
			child = p;
			p = ht[p].parent;
			j++;
		}
		for (int m = 0; m < j; m++)                     //将编码逆置，成为哈夫曼编码
		{
			code1[m] = code[j - m - 1];
		}
		code1[j] = '\0';
		hc[i] = (char*)malloc(sizeof(char)*(j+1));
		strcpy(hc[i],code1);
	}
	FILE * pFile;                                  //打开文件
	pFile = fopen("CodeFile.txt", "w");            //文件操作
	if (pFile != NULL)
	{
		for (int i = 1; i <= n; i++)
		{
			fprintf(pFile, " %s", hc[i]);
		}
		fclose(pFile);
	}
	printf("正在编码");
	for (int n = 0; n < 6; n++)
	{
		Sleep(500);
		printf(".");
	}
	printf("\n");
	printf("编码成功！\n");
}
void Decoding(hfmtree ht[],char *hc[],int n)
{
	if (hc[1] == NULL)
	{
		printf("error：您还未进行编码操作，请编码后再试...\n");
		return;
	}
	printf("正在译码");
	for (int n = 0; n < 6; n++)
	{
		Sleep(500);
		printf(".");
	}
	printf("\n");
	printf("译码成功：");
	for (int i = 1; i <= n; i++)
	{
		int p = 2 * n - 1;
		char cd[Max] = { 0 };
		strcpy(cd, hc[i]);
		int size = strlen(cd);
		for (int j = 0; j < size; j++)                      
		{
			if (ht[p].Lchild == 0&&ht[p].Rchild == 0)
				break;
			else                                        //根据编码从根节点向下遍历，找叶子结点
			{
				if (cd[j] == '1')
					p = ht[p].Lchild;
				if (cd[j] == '0')
					p = ht[p].Rchild;
			}
		}
		printf("%c", ht[p].c);                         //输出译出的值
		FILE * pFile;                                  //打开文件
		pFile = fopen("TextFile.txt", "a");            //文件操作
		if (pFile != NULL)
		{
			fprintf(pFile, " %c", ht[p].c);
			fclose(pFile);
		}
	}
	printf("\n");
}
int main()
{
	char *hc[Max] = { 0 };                                //初始化存放指向每个字符编码首地址的指针数组
	hfmtree ht[Max] = { 0 };                              //初始化结构体数组
	int s = 1;
	int n;
	Menu();
	while (s)
	{
		printf("请输入选项：");
		scanf("%d", &s);
		switch(s)
		{
		   case 0:
		  {
					 printf("byebye!\n");
					 break;
		  }
		
		   case 1:
		   {
		             printf("请输入字符集大小：");
				     scanf("%d", &n);
				     Creathfm(ht, n);
				     break;
		   }
		   case 2:
		   {
				     Encoding(ht, n, hc);                              //编码
				     break;
		   }
		   case 3:
		   {
				     Decoding(ht, hc, n);                             //解码
				     break;
		   }
		   case 4:
		   {
				     Print(hc, n);
				     break;
		   }
		   default:
			   printf("输入错误，请重新输入...\n");
			   break;
		}
		printf("#########################################\n");
	}
	
	system("pause");
	return 0;
}
