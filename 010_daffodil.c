/*
 * 用于输出水仙花数字，打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身
 */
#include <stdio.h>



int main()
{
	int x,y,z;
	int i;
	for(i = 100; i < 1000;i++)
	{
		x=i/100;
		y=(i/10)%10;
		z=i%10;

		if(i == (x*x*x+y*y*y+z*z*z))
			printf("%d\n",i);
	}
    return 0;
}


