/*
 * 从二维数组里，任意拿出第几大的元素的下标
 */


#include <stdio.h>
#include <string.h>

int n = 0;

void quick_sort(int arrr[][5], int start, int end)
{	
	n++;
	int *arr = (int *)arrr;
	
	if (start >= end) 
		return;

	int tmp = 0;
	int left = start;
	int right = end - 1;
	
	int key = arr[end];

	while (left < right) {
		while ((left < right) && (arr[left] > key)) {
			left++;
		}
		while ((left < right) && (arr[right] <= key)) {
			right--;
		}

		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}

	if (arr[left] <= arr[end]) {
		tmp = arr[left];
		arr[left] = arr[end];
		arr[end] = tmp;
	}
	else {
		left++;
	}

	if (left) {
		quick_sort((int (*)[5])arr, start, left - 1);
	}
	quick_sort((int (*)[5])arr, left + 1, end);
}


void quick_sort_swap(int arr[][5],int len)
{
	quick_sort(arr, 0, len - 1);
}

int main(void)
{
	int i,j;
	int tmp = 0;
	int a;
	
	int arr[4][5] = {61, 82, 13, 14, 15,
					 21, 22, 99, 24, 25,
					 31, 72, 33, 64, 95,
					 41, 27, 53, 44, 11,};
	
	int arr_tmp[4][5] = {0};

	memcpy(arr_tmp, arr, sizeof(arr));

	printf("原来的二维数组：\n\r");
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		printf("%d	", arr[i/5][i%5]);
		
		if (4 == i%5) {
			printf("\n\r");
		}
	}

	printf("请输入要显示的以上4x5矩阵的第几大的数：");
	scanf("%d", &a);

	
#if 0   //选择排序
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		for (j = sizeof(arr)/sizeof(arr[0][0]) - 1; j > i; j--) {
			if (arr[i/5][i%5] < arr[j/5][j%5]) {
				tmp = arr[i/5][i%5];
				arr[i/5][i%5] = arr[j/5][j%5];
				arr[j/5][j%5] = tmp;
			}
			n++;
		}
	}
#endif

#if 0	//冒泡排序
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]) - 1; i++) {
		for (j = 0; j < sizeof(arr)/sizeof(arr[0][0]) - i - 1; j++) {
			if (arr[j/5][j%5] < arr[(j+1)/5][(j+1)%5]) {
				tmp = arr[j/5][j%5];
				arr[j/5][j%5] = arr[(j+1)/5][(j+1)%5];
				arr[(j+1)/5][(j+1)%5] = tmp;
			}
			n++;
		}
	}
#endif 

#if 1	//快速排序
	quick_sort_swap(arr, sizeof(arr)/sizeof(arr[0][0]));
#endif 

	printf("原来的二维数组从高到低排列后为：\n\r");
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		printf("%d	", arr[i/5][i%5]);
		
		if (4 == i%5) {
			printf("\n\r");
		}
	}
	printf("第%d大的数为：%d 时间复杂度：%d\n\r", a, arr[(a-1)/5][(a-1)%5], n);

	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		if (arr_tmp[i/5][i%5] == arr[(a-1)/5][(a-1)%5]) {
			printf("第%d大的数在原来的二维数组下的坐标为：arr[%d][%d]\n\r", a, i/5, i%5);
		}
	}
	return 0;
}



