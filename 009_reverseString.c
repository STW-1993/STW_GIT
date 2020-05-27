/*
 * 用于反转输入的字符串
 */
#include <stdio.h>

//递归操作
void reverseString()
{
	char c;
	scanf("%c",&c);
	if(c != '\n')
	{
		//printf("%c",c);         //放在这里是正向打印
		reverseString();
		printf("%c",c);          //放在这里是反向打印
	}
}
 
int main()
{
	printf("请输入字符串：");
	reverseString();
	printf("\n");
    return 0;
}


