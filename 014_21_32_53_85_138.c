/*
 * 有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和
 */
#include <stdio.h>



int main()
{
	int i,n,tmp;
	float a=2,b=1,sum = 0;

	printf("要计算这个数列的前几项之和：");
	scanf("%d",&n);

	for(i =0;i < n;i++)
	{
		sum = sum + (a / b);
		tmp = a;
		a   = a+b;
		b   = tmp;
	}

	printf("分数序列：2/1，3/2，5/3，8/5，13/8，21/13...这个数列的前%d项之和为：%f\n",n,sum);
	
    return 0;
}


