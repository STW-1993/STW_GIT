/*
 * C和指针之字符串strchr、strpbrk、strstr
 * 1）char *strchr(const char *s, int c)函数的功能：
 *    在s中找字符c第一次出现的地方，返回这个指向该位置的指针，没找到返回NULL
 * 2）char *strpbrk(const char *s1, const char *s2);
 *    在s1中，找s2中任意第一次出现的字符，返回这个指向该位置的指针，没找到返回NULL
 * 3）char *strstr(const char *big, const char *little);
 *    在big中找第一次出现little子字符串，返回这个指向该位置的指针，没找到返回NULL
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


