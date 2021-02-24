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

	RCTrace(500, "aaa: %d\n\r", aaa);

	return 0;
}



