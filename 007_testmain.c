/*
 * ���ڲ���RCTrace��ӡ����
 */
#include "007_level_printf.h"

int main(int argc,char **argv)
{
	SetDebugLevel(atoi(argv[1]));  //�ַ�ת��Ϊ����

	char *p = "abcdefghijklmnopqrstuvwxyz";
	char str[] = "hello world!";
	int num = 888;
	
	RCTrace(5,"%s %d %s\n\r",str,num,p);
	
	return 0;
}

