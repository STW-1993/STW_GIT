#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "RCTrace.h"

int g_arr[G_ARR_LEFT][2];

void RCTraceDBG(int nLv,char *format,...)
{	
	int i, iNum;
	char strTmpBuf[1000];
	char *pcTmp;
	
	va_list args;
	va_start(args, format);
	iNum = vsprintf(strTmpBuf, format, args);
	va_end(args);
	strTmpBuf[iNum] = '\0';
	pcTmp = strTmpBuf;

	for (i = 0; i < G_ARR_LEFT; i++) {
		if (-1 == g_arr[i][0])
			break;
		if (nLv >= g_arr[i][0] && nLv <= g_arr[i][1])
			printf("%s", pcTmp);
	}
}

void InitRCTrace(int argc, char **argv)
{
	int ch;

	ch = getopt(argc, argv, "hd:");
	switch (ch) {
		case 'd':
			RCTraceLevelManager(optarg);
			break;
		case 'h':
			printf("请输入这种格式：./test -d\"e:0-2048;aS\"\n\r");
			break;
		default:
			printf("输入-h参数知道help信息\n\r");
			break;
	}
}

void RCTraceLevelManager(char *pInitString)
{	
	int i = 0;
	char buff[1000];

	char *pstr_start =NULL;
	char *pstr_end =NULL;
	char *pToken = NULL;
	
	pstr_start = strstr(pInitString, "e:");
	pstr_start += 2;
	pstr_end = strstr(pstr_start, ";aS"); //pstr_start的范围在e:和;aS之间
	*pstr_end = '\0';                     //暂时用不上后面的数据，用结束符增加安全性

	memset(g_arr, -1, sizeof(g_arr));
	memset(buff, 0, sizeof(buff));
	strcpy(buff, pstr_start);
	
	pToken = strtok(buff, ",");
	while(pToken) {
		if(strpbrk(pToken, "-") != NULL) 
			sscanf(pToken, "%d-%d", &g_arr[i][0], &g_arr[i][1]);
		else
			g_arr[i][0] = g_arr[i][1] = atoi(pToken);
		pToken = strtok(NULL, ",");
		i++;
	}
}





