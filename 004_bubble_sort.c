/*冒泡排序*/
#include<stdio.h>

#define ARRNUM(x) (sizeof(x))/(sizeof(x[0]))

void bubble_sort1(int *arr,int n)
{
	int i,j;
	int temp;
	
	for(i = 0; i < n ;i++)
	{
		for(j = n -1; j > i;j--)
		{
			if(*(arr+i) <= *(arr+j))
			{
				temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
}

void bubble_sort2(int * arr, int n)
{
	int i,j;
	int temp;

	for(i = 0; i < n ;i++)
	{
		for(j = i+1; j < n;j++)
		{
			if(*(arr+i) <= *(arr+j))
			{
				temp = *(arr+i);
				*(arr+i) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
}

int main()
{
	int arr[]={100,2,322,40,5,6,7,18,9,10,13,12};

	int i,n;
	n = ARRNUM(arr);

	printf("本数组的元素个数为：%d \n\r",n);

	//bubble_sort1(arr,n);
	bubble_sort2(arr,n);

	printf("冒泡排序从大到小：");
	for(i =0;i < n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\r");
	
	return 0;
}


