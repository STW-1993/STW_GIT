/*	
 *	�ݹ�ѵ��
 *	
 */
#include <stdio.h>
#include <string.h>

int m = 0;
int n = 2;
#define MAX_ROW 7
#define MAX_COL 7

int arr[MAX_ROW][MAX_COL] = {
		0, 1, 1, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 1, 0,
		0, 1, 0, 1, 0, 1, 0,
		0, 1, 1, 1, 0, 1, 0,
		0, 0, 0, 1, 0, 1, 0,
		1, 0, 1, 1, 0, 1, 0,
		0, 0, 0, 0, 0, 1, 0,
	};

int array[MAX_ROW][MAX_COL];


void backfun2(int row, int col, int ret)
{
	int i,j; 
	int tmp = 0;
	arr[row][col] = n++;

	printf("-------------------------------\n\r");
	for (i = 0; i < MAX_ROW; i++)
		for (j = 0; j < MAX_COL; j++)
		{
			printf("\t%1d",arr[i][j]);
			if (j == MAX_COL - 1)
				printf("\n\r");
		}
		
	if (row == MAX_ROW -1 && col == MAX_COL -1)
	{	
		m = 2;

		for (i = 0; i < MAX_ROW; i++)
			for (j = 0; j < MAX_COL; j++)
			{
				array[i][j]=arr[i][j];
			}
			
		return;
	}

	if (col + 1 <= MAX_COL - 1 && arr[row][col + 1] == 0) //��
	{
		tmp = 4;
		
		if (ret != 3)
		{
			backfun2(row, col + 1, tmp);
			if (m == 0)
				arr[row][col + 1] += MAX_ROW * MAX_COL;
		}
	}
	if (row + 1 <= MAX_ROW - 1 && arr[row + 1][col] == 0) //��
	{
		tmp = 2;

		if (ret != 1)
		{	
			backfun2(row + 1, col, tmp);
			if (m == 0)
				arr[row + 1][col] += MAX_ROW * MAX_COL;
		}
	}
	if ((row - 1 >= 0) && (arr[row - 1][col] == 0))  //��
	{
		tmp = 1;
		
		if (ret != 2)
		{
			backfun2(row - 1, col, tmp);
			if (m == 0)
				arr[row - 1][col] += MAX_ROW * MAX_COL;
		}
	}
	if (col - 1 >= 0 && arr[row ][col - 1] == 0)  //��
	{
		tmp = 3;
		
		if (ret != 4)
		{	
			backfun2(row, col - 1, tmp);
			if (m == 0)
				arr[row][col - 1] += MAX_ROW * MAX_COL;
		}
	}
}

int main()
{
	backfun2(0, 0, 5);

	int num[30][2] = {0};
	int tmp1,tmp2;
	int k = 0;
	
	int i,j;
	printf("++++++++++++++++++++++++++++++++++++\n\r");
	for (i = 0; i < MAX_ROW; i++)
		for (j = 0; j < MAX_COL; j++)
		{
			if (array[i][j] < 50 && array[i][j] > 1)
			{
				num[k][0] = i;
				num[k][1] = j;
				k++;
			}
		}

	for (i = 0; i < k; i++)
		for (j = k - 1; j > i; j--)
		{
			if (array[num[i][0]][num[i][1]] >= array[num[j][0]][num[j][1]])
			{
				tmp1 = num[i][0];
				tmp2 = num[i][1];
				num[i][0] = num[j][0];
				num[i][1] = num[j][1];
				num[j][0] = tmp1;
				num[j][1] = tmp2;
			}
		}

	for (i = 0; i < k; i++)
		printf("(%d, %d)\n\r", num[i][0], num[i][1]);


	return 0;
}



