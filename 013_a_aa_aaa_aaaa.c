/*
 * 用于计算a+aa+aaa+aaaa....
 */
#include <stdio.h>
/*
int mypow(int num,int power)
{
	int sum = 1;
	while((power - 1) > 0)
	{
		sum *= num;
		power--;
	}
	return sum;
}

int fun(int a,int n)         //最大的项
{	
	int s=0;

	while(n > 0)
	{
		s +=  a  * mypow(10,n);
		n--;
	}

	return s;
}
*/
int main()
{
/*
	int a,n;
	int s = 0;
	
	scanf("%d %d",&a,&n);

	while(n > 0)
	{
		s +=fun(a,n);
		n--;
	}

	printf("%d\n",s);
*/

	int a,n,tmp;
	int s=0;
	
	printf("请输入一个基数和项个数：");
	scanf("%d %d",&a,&n);

	tmp = a;
	while(n > 0)
	{
		s   += tmp ;
		a   =  a*10;
		tmp += a   ;
		n--;
	}

	printf("a+aa+aaa...=%d\n",s);
	
    return 0;
}


