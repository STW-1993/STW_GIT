/*
 * ���ڲ���RCTrace��ӡ����
 */
#include <stdio.h>
#include "007_level_printf.h"

int main(int argc,char **argv)
{
	SetDebugLevel(atoi(argv[1]));  //�ַ�ת��Ϊ����

	char *p = "abcdefghijklmnopqrstuvwxyz";
	int num = 888;
	
	RCTrace(5,"hello world! %d %s\n\r",num,p);
	
	return 0;
}

