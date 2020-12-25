/*
 * 从二维数组里，任意拿出第几大的元素的下标
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,j;
	int tmp = 0;
	int a;
	
	int arr[4][5] = {61, 82, 13, 14, 15,
					 21, 22, 23, 24, 25,
					 31, 72, 33, 64, 95,
					 41, 27, 53, 44, 45,};
	
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
	
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		for (j = sizeof(arr)/sizeof(arr[0][0]) - 1; j > i; j--) {
			if (arr[i/5][i%5] < arr[j/5][j%5]) {
				tmp = arr[i/5][i%5];
				arr[i/5][i%5] = arr[j/5][j%5];
				arr[j/5][j%5] = tmp;
			}
		}
	}

	printf("原来的二维数组从高到低排列后为：\n\r");
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		printf("%d	", arr[i/5][i%5]);
		
		if (4 == i%5) {
			printf("\n\r");
		}
	}
	printf("第%d大的数为：%d \n\r", a, arr[(a-1)/5][(a-1)%5]);

	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		if (arr_tmp[i/5][i%5] == arr[(a-1)/5][(a-1)%5]) {
			printf("第%d大的数在原来的二维数组下的坐标为：arr[%d][%d]\n\r", a, i/5, i%5);
		}
	}
	return 0;
}



