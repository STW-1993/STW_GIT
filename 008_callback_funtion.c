/*
 * �ص�������ʹ��
 */
#include <stdio.h>

void testfun(int nLv,int num1,int num2,int (*callback)(int ,int ))  //�ص������Ĳ�������ֱ��Я��
{
	if(callback(num1,num2) > nLv)
	{
		printf("x + y ���� z \n\r");
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



