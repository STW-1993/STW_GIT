/*
 * �Ӷ�ά����������ó��ڼ����Ԫ�ص��±�
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
	int i,j,k;
	int tmp = 0;
	int a;
	
	int arr[4][5] = {61, 82, 13, 14, 15,
					 21, 22, 23, 24, 25,
					 31, 72, 33, 64, 95,
					 41, 27, 53, 44, 45,};
	
	int arr_tmp[4][5] = {0};

	memcpy(arr_tmp, arr, sizeof(arr));
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d  ", arr[i][j]);
		}
		printf("\n\r");
	}

	printf("������Ҫ��ʾ������4x5����ĵڼ��������");
	scanf("%d", &a);
	
#if 0   //���ַ������������ַ���Ч����һ���ģ��������������Եúÿ�
	for (k = 0; k < sizeof(arr)/arr[0][0]; k++) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 5; j++) {
				if (j == 4) {
					if (i == 3) {
						continue;
					}
					else if (arr[i][j] < arr[i+1][0]) {
						tmp = arr[i][j];
						arr[i][j] = arr[i+1][0];
						arr[i+1][0] = tmp;
					}
				}
				else if (arr[i][j] < arr[i][j+1]) {
					tmp = arr[i][j];
					arr[i][j] = arr[i][j+1];
					arr[i][j+1] = tmp;
				}
			}
		}
	}
#endif
	for (i = 0; i < sizeof(arr)/sizeof(arr[0][0]); i++) {
		for (j = 0; j < sizeof(arr)/sizeof(arr[0][0]); j++) {
			if (arr[i/5][i%5] > arr[j/5][j%5]) {
				tmp = arr[i/5][i%5];
				arr[i/5][i%5] = arr[j/5][j%5];
				arr[j/5][j%5] = tmp;
			}
		}
	}

	printf("��%d�����Ϊ��%d\n\r", a, arr[(a-1)/5][(a-1)%5]);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			if (arr_tmp[i][j] == arr[(a-1)/5][(a-1)%5]) {
				printf("��%d��������±�Ϊ��arr[%d][%d]\n\r", a, i, j);
			}
		}
	}
	return 0;
}



