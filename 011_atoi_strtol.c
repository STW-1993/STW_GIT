/*
 * ����ʵ���ַ�����ʽ����ת��Ϊ��ֵ��ʽ����
 */
#include <stdio.h>



int main()
{
	//int num;
	char *str1="123456789abcdef";
	char *str2="ghijk123456789";
	char *stop1=NULL;
	char *stop2=NULL;
	printf("ԭ�����ַ�������str1Ϊ��%s\n",str1);
	printf("ԭ�����ַ�������str2Ϊ��%s\n",str2);

	printf("-------------------------------------------------\n");
	
	printf("atoi()����ת��str1��%d\n",atoi(str1));       //�����ַ�����'\0'�ͻ�ֹͣ�������������ͷ���Ƿ������ַ����᷵��0
	printf("atoi()����ת��str2��%d\n",atoi(str2));
	
	printf("-------------------------------------------------\n");
	printf("str1tol()����ת��str1��%d \n",strtol(str1,&stop1,10));
	printf("str1tol()����ת��str2��%d \n",strtol(str2,&stop2,10));
	printf("��ֹ�ַ�stop1��%s \n",stop1);
	printf("��ֹ�ַ�stop2��%s \n",stop2);

    return 0;
}


