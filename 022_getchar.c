/*
 * getchar()��putchar()������ѵ��
 */

#include <stdio.h>

int main(void)
{
	char ch;

	while ((ch = getchar()) != '\n') {
		printf("%c ",ch);
	}

	putchar('\n');
	
	return 0;
	
}



