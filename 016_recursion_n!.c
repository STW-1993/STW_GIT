/*
 * �õݹ���n!��ֵ
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
	printf("��������Ҫ���������");
	scanf("%d",&n);
	sum = recursion(n);
	printf("ֵΪ��%d\n",sum);
	return 0;
}


