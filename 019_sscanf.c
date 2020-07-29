/*
 * ssacnf()º¯Êý
 * 
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "ABCDEFG/HI123456\rJK@LMN";
	char tmp[50];
	char tmp2[50];
	char str2[] = "5~abcd";
	int	num1, num2;
	char *arr;

	sscanf(str,"%*[^/]/%[^@]",tmp);
	printf("%s \r\n",tmp);

	sscanf(str,"%[^\r]",tmp2);
	printf("%s \r\n",tmp2);

	sscanf(str2,"%d~%s", &num1, arr);
	printf("%d  %s \n\r", num1, arr);
	
    return 0;

}


