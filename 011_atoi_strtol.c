/*
 * 用于实现字符串形式数字转换为数值形式数字
 */
#include <stdio.h>



int main()
{
	//int num;
	char *str1="123456789abcdef";
	char *str2="ghijk123456789";
	char *stop1=NULL;
	char *stop2=NULL;
	printf("原本的字符串数字str1为：%s\n",str1);
	printf("原本的字符串数字str2为：%s\n",str2);

	printf("-------------------------------------------------\n");
	
	printf("atoi()函数转换str1：%d\n",atoi(str1));       //遇到字符或者'\0'就会停止，但如果遇到开头就是非数字字符，会返回0
	printf("atoi()函数转换str2：%d\n",atoi(str2));
	
	printf("-------------------------------------------------\n");
	printf("str1tol()函数转换str1：%d \n",strtol(str1,&stop1,10));
	printf("str1tol()函数转换str2：%d \n",strtol(str2,&stop2,10));
	printf("终止字符stop1：%s \n",stop1);
	printf("终止字符stop2：%s \n",stop2);

    return 0;
}


