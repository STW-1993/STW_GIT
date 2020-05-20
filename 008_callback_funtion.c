/*
 * 回调函数的使用
 */
#include <stdio.h>

void testfun(int nLv,int num1,int num2,int (*callback)(int ,int ))  //回调函数的参数不能直接携带
{
	if(callback(num1,num2) > nLv)
	{
		printf("x + y 大于 z \n\r");
	}
	return;
}

int mathfun(int num1,int num2)
{
	return (num1 + num2);
}

int main()
{
	int x = 10;
	int y = 20;
	int z = 25;

	testfun(z,x,y,mathfun);
	
	return 0;
}



