/*
 * 用于测试字符串的打印
 */
#include<stdio.h>

int main()
{
	char str1[] = "5*(4+7-(4-2)*2)";
	char str2[] = "abcdefg";
	printf("str1[] = %s\n\r",str1);
	printf("str2[] = %s\n\r",str2);
	printf("str1 size = %d  str2 size = %d \n\r",sizeof(str1),sizeof(str2));
	
	printf("-------------------------------------------------------------------");
	
	char *p1 = "5*(4+7-(4-2)*2)";
	char *p2 = "abcdefg";
	printf("*p1 = %s\n\r",*p1);
	printf("*p2 = %s\n\r",*p2);
	printf("*p1 size = %d  *p2 size = %d \n\r",sizeof(*p1),sizeof(*p2));

	return 0;
}