/*
 * ��1+2!+3!+...+n!�ĺ�
 */
#include <stdio.h>

int main()
{
	int i,n;
	int sum = 0;
	int tmp = 1;

	printf("����1+2!+3!+...+n!ǰ���ٸ���Ľ׳˺ͣ�");
	scanf("%d",&n);

	for(i = 1;i <= n;i++)
	{
		sum = sum +tmp;
		tmp = tmp * (i+1);
	}

	printf("1+2!+3!+...+n!��ǰ%d���Ϊ��%d\n",n,sum);
    return 0;
}


