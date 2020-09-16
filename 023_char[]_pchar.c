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
	char *tmp = str;             //一定要分配好内存，不然tmp指针会指向常量区，常量区不能修改，也就不能
								 //使用memcpy等写入的函数进行操作
	buff[0] = 1;
	buff[1] = 3;
	buff[2] = 0;
	buff[3] = 1;
	buff[4] = 0;
	buff[5] = 1;
	buff[6] = 25;
	buff[7] = 26;
	
	memcpy(tmp, buff, sizeof(buff));  //如果tmp没有分配好内存，这里会出现段错误

	printf("%d \n\r", tmp[1]);
	
	return 0;
	
}



