/*
 * �Ӷ�ά����������ó��ڼ����Ԫ�ص��±�
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

	printf("ԭ���Ķ�ά���飺\n\r");
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		printf("%d	", arr[i/5][i%5]);
		
		if (4 == i%5) {
			printf("\n\r");
		}
	}

	printf("������Ҫ��ʾ������4x5����ĵڼ��������");
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

	printf("ԭ���Ķ�ά����Ӹߵ������к�Ϊ��\n\r");
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		printf("%d	", arr[i/5][i%5]);
		
		if (4 == i%5) {
			printf("\n\r");
		}
	}
	printf("��%d�����Ϊ��%d \n\r", a, arr[(a-1)/5][(a-1)%5]);

	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		if (arr_tmp[i/5][i%5] == arr[(a-1)/5][(a-1)%5]) {
			printf("��%d�������ԭ���Ķ�ά�����µ�����Ϊ��arr[%d][%d]\n\r", a, i/5, i%5);
		}
	}
	return 0;
}



