/*	
 *	最优路线跑出迷宫
 *	v 1.1
 */
#include <stdio.h>
#include <string.h>


#define MAX_ROW 8
#define MAX_COL 8

//下面的数组就是迷宫的模型
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

int array[MAX_ROW][MAX_COL];    //刚走出迷宫时，已走过的路线记录图
int num[MAX_ROW * MAX_COL][2];  //存放最优路线的坐标

int m = 0;  //标记是否走到迷宫出口，0：未出迷宫  2：已出迷宫
int n = 2;  //走迷宫的记录，从2开始
int k = 0;  //最优路线的步数

/*
 *	函数名称：rec_fun1
 *	函数作用：跑迷宫
 *	参数含义：row        此参数指的是当前位置的横坐标
 *	          col   此参数指的是当前坐标的纵坐标
 *	          ret   此参数指的是上一次坐标到达当前坐标的方向(ret = 5表示开始，1表示向上，2表示向下，
 *	                                                                          3表示向左，4表示向右)
 */
void rec_fun1(int row, int col, int ret)
{
	int i,j; 
	int tmp = 0;

	if (m == 0)
		arr[row][col] = n++;

#if 1        //打印每一个脚步
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

	if (col + 1 <= MAX_COL - 1 && arr[row][col + 1] == 0) //右
	{
		tmp = 4;
		
		if (ret != 3)
		{
			rec_fun1(row, col + 1, tmp);
			if (m == 0)
				arr[row][col + 1] += MAX_ROW * MAX_COL * 100;
		}
	}
	if (col - 1 >= 0 && arr[row ][col - 1] == 0)  //左
	{
		tmp = 3;
		
		if (ret != 4)
		{	
			rec_fun1(row, col - 1, tmp);
			if (m == 0)
				arr[row][col - 1] += MAX_ROW * MAX_COL * 100;
		}
	}
	if (row + 1 <= MAX_ROW - 1 && arr[row + 1][col] == 0) //下
	{
		tmp = 2;

		if (ret != 1)
		{	
			rec_fun1(row + 1, col, tmp);
			if (m == 0)
				arr[row + 1][col] += MAX_ROW * MAX_COL * 100;
		}
	}
	if (row - 1 >= 0 && (arr[row - 1][col] == 0))  //上
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
 *	函数名称：rec_fun2
 *	函数作用：跑迷宫
 *	参数含义：row        此参数指的是当前位置的横坐标
 *	          col   此参数指的是当前坐标的纵坐标
 *	          ret   此参数指的是上一次坐标到达当前坐标的方向(ret = 5表示开始，1表示向上，2表示向下，
 *	                                                                          3表示向左，4表示向右)
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
	
	if (col + 1 <= MAX_COL - 1 && array[row][col + 1] < MAX_ROW * MAX_COL * 100) //右
	{
		tmp[0][0] = array[row][col + 1];
		tmp[0][1] = row;
		tmp[0][2] = col + 1;
	}
	if (row + 1 <= MAX_ROW - 1 && array[row + 1][col] < MAX_ROW * MAX_COL * 100) //下
	{
		tmp[1][0] = array[row + 1][col];
		tmp[1][1] = row + 1;
		tmp[1][2] = col;
	}
	if (row - 1 >= 0 && array[row - 1][col] < MAX_ROW * MAX_COL * 100)  //上
	{
		tmp[2][0] = array[row - 1][col];
		tmp[2][1] = row - 1;
		tmp[2][2] = col;
	}
	if (col - 1 >= 0 && array[row][col - 1] < MAX_ROW * MAX_COL * 100)  //左
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
		printf("这个迷宫无法到达出口！\n\r");
}

void printf_maze()
{
	int i,j;

	printf("************************** 打印走出以下迷宫的最优路线 ***************************\n\r");
	printf("*迷宫入口是左上角(0, 0)，出口是右下角(max,max)，0是可以走的通道，1是墙壁无法通行*\n\r");
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
	printf_maze();          //打印迷宫的全貌，打印相关规定
	
	rec_fun1(0, 0, 5);      //跑迷宫
	
	printf_fun();           //打印最优路线

	return 0;
}



