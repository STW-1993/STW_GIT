/*
 * �������������һ�������е�������ֺ͵ڶ��󡢵����������
 */
#include<stdio.h>

int main()
{	
	int arr[3][4]={100,2,322,40,5,6,7,18,9,10,13,12};
	int *p =(int *)arr;
	int temp1,temp2,temp3,mnt;
	
	temp1 = temp2 = *p;
	
	while(p <= &(arr[2][3]))
	{
		if(*p >= temp1)
		{
			temp1 =*p;
			if(temp1 >= temp2)
			{
				mnt = temp1;
				temp1 = temp2;
				temp2 = mnt;
			}
			if(temp2 >= temp3)
			{
				mnt = temp2;
				temp2 = temp3;
				temp3 = mnt;
			}
		}
		p++;
	}

	printf("�����������Ϊ%d \n\r",temp1);
	printf("�ڶ��������Ϊ%d \n\r",temp2);
	printf("��������Ϊ%d \n\r",temp3);

	return 0;
}



