/*
 * strpbrk������ʹ��,�Ƚ��ַ���str1��str2���Ƿ�����ͬ���ַ�������У��򷵻ظ��ַ���str1�е�λ�õ�ָ�롣
 * ���û�У��򷵻�NULL
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
		printf("û����ͬ���ַ� \r\n");
	}
	else
	{
		printf("����ͬ���ַ� %c \r\n",strtmp[0]);
	}
	
    return 0;

}


