/*
 * ��һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮��
 */
#include <stdio.h>



int main()
{
	int i,n,tmp;
	float a=2,b=1,sum = 0;

	printf("Ҫ����������е�ǰ����֮�ͣ�");
	scanf("%d",&n);

	for(i =0;i < n;i++)
	{
		sum = sum + (a / b);
		tmp = a;
		a   = a+b;
		b   = tmp;
	}

	printf("�������У�2/1��3/2��5/3��8/5��13/8��21/13...������е�ǰ%d��֮��Ϊ��%f\n",n,sum);
	
    return 0;
}


