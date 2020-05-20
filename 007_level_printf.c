/*
 * ���һ���еȼ��Ĵ�ӡ
 */
#include <stdarg.h>
#include "007_level_printf.h"

int debug_flag = 0;


//ʹ�ñ�ε�֪ʶ���
void RCTrace(int nLv,char *format,...)
{
	va_list args;
	va_start(args,format);
	if(nLv <= debug_flag)
	{
		vprintf(format,args);
	}
	va_end(args);
}

void SetDebugLevel(int num)
{
	debug_flag = num; 
}


