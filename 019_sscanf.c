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

	sscanf(str,"%*[^/]/%[^@]",tmp);
	printf("%s \r\n",tmp);

	sscanf(str,"%[^\r]",tmp2);
	printf("%s \r\n",tmp2);
	
    return 0;

}


