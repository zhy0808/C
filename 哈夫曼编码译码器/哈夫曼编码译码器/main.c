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
	printf("#########0.�˳�              1.��ԭ��#########\n");
	printf("#########2.����              3.����###########\n");
	printf("#########4.��ʾ����������    #################\n");
	printf("##############################################\n");
}
int min[2] = { 0 };
void Print(char *hc[],int n)
{
	if (hc[1] == NULL)
	{
		printf("error������δ���б������������������...\n");
		return;
	}
	printf("����Ϊ:");
	for (int i = 1; i <= n; i++)
	{
		printf("%s", hc[i]);
	}
	printf("\n");
}
int *Slect(hfmtree ht[], int m,int n)                          //������ǰ����Ȩֵ��С��û��parent�Ľڵ��±�
{
	for (int j = 1; j <= m; j++)                         //������ʼ����λ�ò�����ͬ������ͬ min[0]�õ���ǰλ���±꣬min[1]����δ�ҵ���С�ģ��������ڵ��±�ֵ����ֵ��ͬ
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
	for (int i = 1; i <= m; i++)                                //��������������һ��Ȩֵ��С��λ��
	{
		if (ht[min[0]].weight > ht[i].weight&&ht[i].parent == 0)
			min[0] = i;
	}
	for (int j = 1; j <= m; j++)                                //��������������һ�������治ͬ��Ȩֵ��С��λ��
	{
		if (min[1] == min[0]||ht[min[1]].parent!=0)
			min[1]--;
		if (ht[min[1]].weight > ht[j].weight&&min[0] != j&&ht[j].parent == 0)
			min[1] = j;
	}
	if (ht[min[0]].weight == ht[min[1]].weight)                 //�����ʱ����Ȩֵ��ͬ��������һ���Ǻϲ��Ľ������ԭ�ַ���λ�÷����ұߣ��䵱������
	{
		int temp = min[0];
		min[0] = min[1];
		min[1] = temp;
	}
	if (min[0] <= n&&min[1] > n)                                 //��֤�������Ĺ����У�ԭȨֵ��������
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
		int *min = Slect(ht, m, n) ;                        //����ǰ����������������СȨֵ���±��ҳ�
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
		printf("error�����������1������...\n");
		return;
	}
	if (n > Max)
	{
		printf("error:�������ݹ���...\n");
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("�������%d���ַ�����Ȩֵ��", i);
		scanf(" %c %d", &ht[i].c, &ht[i].weight);
	}
	Merge(ht,n);                                   //�ϲ�
	FILE * pFile;                                  //���ļ�
	pFile = fopen("hfmtree.txt", "w");            //�ļ�����
	if (pFile != NULL)
	{
		for (int i = 1; i <= n; i++)
		{
			fprintf(pFile," %c %d", ht[i].c, ht[i].weight);
		}
		fclose(pFile);
	}
	
	printf("����ɹ���\n");
}

void  Encoding(hfmtree ht[], int n, char *hc[Max])
{
	if (ht[1].c == NULL)
	{
		printf("error: ��������δ�����ַ���Ȩֵ...\n");
		return;
	}
	char code[Max] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		char code1[Max] = { 0 };
		int j = 0;
		int p = ht[i].parent;
		int child = i;
		while (p != 0)                                    //��Ҷ�ӽ�㵽���ڵ����α���
		{
			if (ht[p].Lchild == child)
				code[j] = '1';
			else
				code[j] = '0';
			child = p;
			p = ht[p].parent;
			j++;
		}
		for (int m = 0; m < j; m++)                     //���������ã���Ϊ����������
		{
			code1[m] = code[j - m - 1];
		}
		code1[j] = '\0';
		hc[i] = (char*)malloc(sizeof(char)*(j+1));
		strcpy(hc[i],code1);
	}
	FILE * pFile;                                  //���ļ�
	pFile = fopen("CodeFile.txt", "w");            //�ļ�����
	if (pFile != NULL)
	{
		for (int i = 1; i <= n; i++)
		{
			fprintf(pFile, " %s", hc[i]);
		}
		fclose(pFile);
	}
	printf("���ڱ���");
	for (int n = 0; n < 6; n++)
	{
		Sleep(500);
		printf(".");
	}
	printf("\n");
	printf("����ɹ���\n");
}
void Decoding(hfmtree ht[],char *hc[],int n)
{
	if (hc[1] == NULL)
	{
		printf("error������δ���б������������������...\n");
		return;
	}
	printf("��������");
	for (int n = 0; n < 6; n++)
	{
		Sleep(500);
		printf(".");
	}
	printf("\n");
	printf("����ɹ���");
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
			else                                        //���ݱ���Ӹ��ڵ����±�������Ҷ�ӽ��
			{
				if (cd[j] == '1')
					p = ht[p].Lchild;
				if (cd[j] == '0')
					p = ht[p].Rchild;
			}
		}
		printf("%c", ht[p].c);                         //��������ֵ
		FILE * pFile;                                  //���ļ�
		pFile = fopen("TextFile.txt", "a");            //�ļ�����
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
	char *hc[Max] = { 0 };                                //��ʼ�����ָ��ÿ���ַ������׵�ַ��ָ������
	hfmtree ht[Max] = { 0 };                              //��ʼ���ṹ������
	int s = 1;
	int n;
	Menu();
	while (s)
	{
		printf("������ѡ�");
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
		             printf("�������ַ�����С��");
				     scanf("%d", &n);
				     Creathfm(ht, n);
				     break;
		   }
		   case 2:
		   {
				     Encoding(ht, n, hc);                              //����
				     break;
		   }
		   case 3:
		   {
				     Decoding(ht, hc, n);                             //����
				     break;
		   }
		   case 4:
		   {
				     Print(hc, n);
				     break;
		   }
		   default:
			   printf("�����������������...\n");
			   break;
		}
		printf("#########################################\n");
	}
	
	system("pause");
	return 0;
}
