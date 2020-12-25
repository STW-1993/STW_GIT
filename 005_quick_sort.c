/*
 * 快速排序（递归法）
 */
#include<stdio.h>

#define ARRNUM(x) (sizeof(x))/(sizeof(x[0]))

void quick_sort_swap(int *arr,int start,int end)
{
	if(start >= end)
	{
		return;
	}
	int mid_num,temp;
	
	int left = start;
	int right = end - 1;
	mid_num = *(arr + end);
	
	while(left < right)
	{
		while((left < right) && (*(arr+left) < mid_num))
			left++;
		while((left < right) && (*(arr+right) >= mid_num))
			right--;
		
		temp = *(arr+left);
		*(arr+left) = *(arr+right);
		*(arr+right) = temp;
	}

	if(*(arr+left) >= *(arr + end))
	{
		temp = *(arr+left);
		*(arr+left) = *(arr+end);
		*(arr+end) = temp;
	}
	else
	{
		left++;
	}
	
	if(left)
	{
		quick_sort_swap(arr,start,left - 1);
	}
	quick_sort_swap(arr,left + 1,end);
}

void quick_sort(int *arr,int len)
{
	quick_sort_swap(arr,0,len -1);
}

int main()
{
	int arr[]={100,2,322,40,5,6,7,18,9,10,13,12};

	int i,n;
	n = ARRNUM(arr);

	printf("本数组的元素个数为：%d \n\r",n);

	quick_sort(arr,n);

	printf("快速排序从大到小：");
	for(i = n-1;i >= 0 ;i--)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\r");
	
	return 0;
}

