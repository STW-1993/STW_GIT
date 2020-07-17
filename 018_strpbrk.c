/*
 * strpbrk函数的使用,比较字符串str1和str2中是否有相同的字符，如果有，则返回该字符在str1中的位置的指针。
 * 如果没有，则返回NULL
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "ABCDEFGHIJKLNM";
	char str2 = 'a';
	char *strtmp = NULL;

	strtmp = strpbrk(str1, &str2);

	if(strtmp == NULL)
	{
		printf("没有相同的字符 \r\n");
	}
	else
	{
		printf("有相同的字符 %c \r\n",strtmp[0]);
	}
	
    return 0;

}


