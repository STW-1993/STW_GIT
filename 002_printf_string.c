/*
 * 用于测试打印相关
 */
#include<stdio.h>
#include <string.h>
int main()
{
	char str1[] = "5*(4+7-(4-2)*2)";
	char str2[] = "abcdefg";
	printf("str1[] = %s\n\r",str1);
	printf("str2[] = %s\n\r",str2);
	printf("str1 size = %zu  str2 size = %zu \n\r",sizeof(str1),sizeof(str2));
	
	printf("-------------------------------------------------------------------\n\r");
	//printf用%d是打印int类型数据，但sizeof和strlen()这两个函数都是返回size_t类型数据，打印会警告类型错误
	//而%u则可以打印unsight int类型数据
	//而%zu则可以打印size_t类型数据
	//而%s则可以打印字符串

	//sizeof操作符会多计算第一个\0,而strlen()函数遇到第一个\0结束计算不包含这个\0
	//strlen()函数计算的是字符串的实际长度，遇到第一个’\0’结束
	//sizeof返回的是变量声明后所占的内存数，不是实际长度，此外sizeof不是函数，仅仅是一个操作符
	
	char *p1 = "5*(4+7-(4-2)*2)";
	char *p2 = "abcdefg";
	printf("*p1 = %s\n\r",p1);
	printf("*p2 = %s\n\r",p2);
	printf("*p1 size = %zu  *p2 size = %zu \n\r",strlen(p1),strlen(p2)); 

	return 0;
}