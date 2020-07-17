/*
 * C��ָ��֮�ַ���strchr��strpbrk��strstr
 * 1��char *strchr(const char *s, int c)�����Ĺ��ܣ�
 *    ��s�����ַ�c��һ�γ��ֵĵط����������ָ���λ�õ�ָ�룬û�ҵ�����NULL
 * 2��char *strpbrk(const char *s1, const char *s2);
 *    ��s1�У���s2�������һ�γ��ֵ��ַ����������ָ���λ�õ�ָ�룬û�ҵ�����NULL
 * 3��char *strstr(const char *big, const char *little);
 *    ��big���ҵ�һ�γ���little���ַ������������ָ���λ�õ�ָ�룬û�ҵ�����NULL
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


