/*
 * ���ڷ�ת������ַ���
 */
#include <stdio.h>

//�ݹ����
void reverseString()
{
	char c;
	scanf("%c",&c);
	if(c != '\n')
	{
		//printf("%c",c);         //���������������ӡ
		reverseString();
		printf("%c",c);          //���������Ƿ����ӡ
	}
}
 
int main()
{
	printf("�������ַ�����");
	reverseString();
	printf("\n");
    return 0;
}


