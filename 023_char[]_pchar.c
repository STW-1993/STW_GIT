/*
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[50];

int main(void)
{
	unsigned char buff[8];
	char *tmp = str;             //һ��Ҫ������ڴ棬��Ȼtmpָ���ָ�������������������޸ģ�Ҳ�Ͳ���
								 //ʹ��memcpy��д��ĺ������в���
	buff[0] = 1;
	buff[1] = 3;
	buff[2] = 0;
	buff[3] = 1;
	buff[4] = 0;
	buff[5] = 1;
	buff[6] = 25;
	buff[7] = 26;
	
	memcpy(tmp, buff, sizeof(buff));  //���tmpû�з�����ڴ棬�������ֶδ���

	printf("%d \n\r", tmp[1]);
	
	return 0;
	
}



