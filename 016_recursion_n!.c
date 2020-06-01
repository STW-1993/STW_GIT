/*
 * 用递归求n!的值
 */
#include <stdio.h>

int recursion(int n)
{	
	if(n <= 1)
	{
		return 1;
	}
	n = n * recursion(n - 1);
	return n;
}

int main()
{
	int n;
	int sum = 0;
	printf("请输入需要计算的数：");
	scanf("%d",&n);
	sum = recursion(n);
	printf("值为：%d\n",sum);
	return 0;
}


