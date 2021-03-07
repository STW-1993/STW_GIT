/*
 * 根据等级打印调试
 * 格式例子：./test -d"e:100,200,300,450-500,650-700,710,750;aS"
 */
#include <stdio.h>
#include "RCTrace.h"

int main(int argc, char **argv)
{
	InitRCTrace(argc, argv);

	int aaa = 1000;

	int i;
	for (i=0; i < 10; i++) {
		RCTrace(0, "[%s %s] %s: %s: %d aaa: %d\n\r", __DATE__, __TIME__, __FILE__, __func__, __LINE__, 
				aaa * i);
	}

	return 0;
}



