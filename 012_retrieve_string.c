/*
 * ���ڼ����ַ�������ĸ���ո����֡�����������
 */
#include <stdio.h>



int main()
{
	int letter_num = 0;
	int digits_num = 0;
	int spaces_num = 0;
	int others_num = 0;

	char c;
	printf("������һЩ��ĸ��");
	while((c=getchar())!='\n')
	{
		if((c > 'a'&& c < 'z')||(c > 'A'&&c > 'Z'))
		{
			letter_num++;
		}
		else if(c>'0'&&c<'9')
		{
			digits_num++;
		}
		else if(c == ' ')
		{
			spaces_num++;
		}
		else
		{
			others_num++;
		}
	}

	printf("letter_num = %d digits_num = %d spaces_num = %d others_num = %d\n",letter_num,digits_num,spaces_num,others_num);

    return 0;
}


