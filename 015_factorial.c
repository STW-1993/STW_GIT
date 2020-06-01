/*
 * 求1+2!+3!+...+n!的和
 */
#include <stdio.h>

int main()
{
	int i,n;
	int sum = 0;
	int tmp = 1;

	printf("数列1+2!+3!+...+n!前多少个项的阶乘和：");
	scanf("%d",&n);

	for(i = 1;i <= n;i++)
	{
		sum = sum +tmp;
		tmp = tmp * (i+1);
	}

	printf("1+2!+3!+...+n!的前%d项和为：%d\n",n,sum);
    return 0;
}


