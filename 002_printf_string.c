/*
 * ���ڲ��Դ�ӡ���
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
	//printf��%d�Ǵ�ӡint�������ݣ���sizeof��strlen()�������������Ƿ���size_t�������ݣ���ӡ�ᾯ�����ʹ���
	//��%u����Դ�ӡunsight int��������
	//��%zu����Դ�ӡsize_t��������
	//��%s����Դ�ӡ�ַ���

	//sizeof�������������һ��\0,��strlen()����������һ��\0�������㲻�������\0
	//strlen()������������ַ�����ʵ�ʳ��ȣ�������һ����\0������
	//sizeof���ص��Ǳ�����������ռ���ڴ���������ʵ�ʳ��ȣ�����sizeof���Ǻ�����������һ��������
	
	char *p1 = "5*(4+7-(4-2)*2)";
	char *p2 = "abcdefg";
	printf("*p1 = %s\n\r",p1);
	printf("*p2 = %s\n\r",p2);
	printf("*p1 size = %zu  *p2 size = %zu \n\r",strlen(p1),strlen(p2)); 

	return 0;
}