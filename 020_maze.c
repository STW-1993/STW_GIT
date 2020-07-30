/*	
 *	����·���ܳ��Թ�
 *	v 1.1
 */
#include <stdio.h>
#include <string.h>


#define MAX_ROW 8
#define MAX_COL 8

//�������������Թ���ģ��
int arr[MAX_ROW][MAX_COL] = {
		0, 0, 1, 1, 0, 0, 0, 1,
		1, 0, 0, 0, 1, 0, 0, 0,
		1, 0, 0, 0, 1, 0, 1, 0,
		1, 0, 0, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 0, 1, 0,
		0, 0, 0, 1, 0, 1, 0, 0,
		0, 1, 1, 0, 0, 1, 0, 1,
		0, 0, 0, 0, 1, 1, 0, 0,
	};

int array[MAX_ROW][MAX_COL];    //���߳��Թ�ʱ�����߹���·�߼�¼ͼ
int num[MAX_ROW * MAX_COL][2];  //�������·�ߵ�����

int m = 0;  //����Ƿ��ߵ��Թ����ڣ�0��δ���Թ�  2���ѳ��Թ�
int n = 2;  //���Թ��ļ�¼����2��ʼ
int k = 0;  //����·�ߵĲ���

/*
 *	�������ƣ�rec_fun1
 *	�������ã����Թ�
 *	�������壺row        �˲���ָ���ǵ�ǰλ�õĺ�����
 *	          col   �˲���ָ���ǵ�ǰ�����������
 *	          ret   �˲���ָ������һ�����굽�ﵱǰ����ķ���(ret = 5��ʾ��ʼ��1��ʾ���ϣ�2��ʾ���£�
 *	                                                                          3��ʾ����4��ʾ����)
 */
void rec_fun1(int row, int col, int ret)
{
	int i,j; 
	int tmp = 0;

	if (m == 0)
		arr[row][col] = n++;

#if 1        //��ӡÿһ���Ų�
	if (m == 0)
	{
		for (i = 0; i < MAX_ROW; i++)
			for (j = 0; j < MAX_COL; j++)
			{
				printf("\t%d",arr[i][j]);
				if (j == MAX_COL - 1)
					printf("\n\r");
			}
			
		printf("-------------------------------------------------------------------------\n\r");
	}			
#endif

	if (row == MAX_ROW -1 && col == MAX_COL -1)
	{	
		m = 2;

		for (i = 0; i < MAX_ROW; i++)
			for (j = 0; j < MAX_COL; j++)
				array[i][j]=arr[i][j];
			
		return;
	}

	if (col + 1 <= MAX_COL - 1 && arr[row][col + 1] == 0) //��
	{
		tmp = 4;
		
		if (ret != 3)
		{
			rec_fun1(row, col + 1, tmp);
			if (m == 0)
				arr[row][col + 1] += MAX_ROW * MAX_COL * 100;
		}
	}
	if (col - 1 >= 0 && arr[row ][col - 1] == 0)  //��
	{
		tmp = 3;
		
		if (ret != 4)
		{	
			rec_fun1(row, col - 1, tmp);
			if (m == 0)
				arr[row][col - 1] += MAX_ROW * MAX_COL * 100;
		}
	}
	if (row + 1 <= MAX_ROW - 1 && arr[row + 1][col] == 0) //��
	{
		tmp = 2;

		if (ret != 1)
		{	
			rec_fun1(row + 1, col, tmp);
			if (m == 0)
				arr[row + 1][col] += MAX_ROW * MAX_COL * 100;
		}
	}
	if (row - 1 >= 0 && (arr[row - 1][col] == 0))  //��
	{
		tmp = 1;
		
		if (ret != 2)
		{
			rec_fun1(row - 1, col, tmp);
			if (m == 0)
				arr[row - 1][col] += MAX_ROW * MAX_COL * 100;
		}
	}
}

/*
 *	�������ƣ�rec_fun2
 *	�������ã����Թ�
 *	�������壺row        �˲���ָ���ǵ�ǰλ�õĺ�����
 *	          col   �˲���ָ���ǵ�ǰ�����������
 *	          ret   �˲���ָ������һ�����굽�ﵱǰ����ķ���(ret = 5��ʾ��ʼ��1��ʾ���ϣ�2��ʾ���£�
 *	                                                                          3��ʾ����4��ʾ����)
 */

void rec_fun2(int row, int col)
{
	int tmp[4][3] = {0};
	int cnt, cnt_row, cnt_col;

	num[k][0] = row;
	num[k][1] = col;
	k++;
	
	if (row == MAX_ROW -1 && col == MAX_COL -1)
	{	
		return;
	}
	
	if (col + 1 <= MAX_COL - 1 && array[row][col + 1] < MAX_ROW * MAX_COL * 100) //��
	{
		tmp[0][0] = array[row][col + 1];
		tmp[0][1] = row;
		tmp[0][2] = col + 1;
	}
	if (row + 1 <= MAX_ROW - 1 && array[row + 1][col] < MAX_ROW * MAX_COL * 100) //��
	{
		tmp[1][0] = array[row + 1][col];
		tmp[1][1] = row + 1;
		tmp[1][2] = col;
	}
	if (row - 1 >= 0 && array[row - 1][col] < MAX_ROW * MAX_COL * 100)  //��
	{
		tmp[2][0] = array[row - 1][col];
		tmp[2][1] = row - 1;
		tmp[2][2] = col;
	}
	if (col - 1 >= 0 && array[row][col - 1] < MAX_ROW * MAX_COL * 100)  //��
	{
		tmp[3][0] = array[row][col - 1];
		tmp[3][1] = row;
		tmp[3][2] = col - 1;
	}

	cnt = tmp[0][0];
	cnt_row = tmp[0][1];
	cnt_col = tmp[0][2];
	
	if(cnt < tmp [1][0])
	{
		cnt = tmp [1][0];
		cnt_row = tmp[1][1];
		cnt_col = tmp[1][2];
	}
	if(cnt < tmp [2][0])
	{
		cnt = tmp [2][0];
		cnt_row = tmp[2][1];
		cnt_col = tmp[2][2];
	}
	if(cnt < tmp [3][0])
	{
		cnt = tmp [3][0];
		cnt_row = tmp[3][1];
		cnt_col = tmp[3][2];
	}

	rec_fun2(cnt_row, cnt_col);
}

void printf_fun()
{
	int i;
	
	rec_fun2(0, 0);

	if (m == 2)
		for (i = 0; i < k; i++)
			printf("(%d, %d)\n\r", num[i][0], num[i][1]);

	if (m == 0)
		printf("����Թ��޷�������ڣ�\n\r");
}

void printf_maze()
{
	int i,j;

	printf("************************** ��ӡ�߳������Թ�������·�� ***************************\n\r");
	printf("*�Թ���������Ͻ�(0, 0)�����������½�(max,max)��0�ǿ����ߵ�ͨ����1��ǽ���޷�ͨ��*\n\r");
	printf("*********************************************************************************\n\r");
	for (i = 0; i < MAX_ROW; i++)
		for (j = 0; j < MAX_COL; j++)
		{
			printf("\t%d",arr[i][j]);
			if (j == MAX_COL - 1)
				printf("\n\r");
		}
		
	printf("*********************************************************************************\n\r");
}

int main()
{
	printf_maze();          //��ӡ�Թ���ȫò����ӡ��ع涨
	
	rec_fun1(0, 0, 5);      //���Թ�
	
	printf_fun();           //��ӡ����·��

	return 0;
}



