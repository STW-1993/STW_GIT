#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "RCTrace.h"

#define G_ARRY_LEFT 20
int g_arry[G_ARRY_LEFT][2];


//使用变参的知识解决
void RCTrace(int nLv,char *format,...)
{	
	int i;
	va_list args;
	va_start(args,format);

	for (i=0; i < G_ARRY_LEFT; i++) {
		if (g_arry[i][0] == 0) {
			break;
		}
		else {
			if (nLv >= g_arry[i][0] && nLv <= g_arry[i][1]) {
				vprintf(format,args);
			}
		}
	}
	va_end(args);
}

void InitRCTrace(int argc, char **argv)
{
	int ch;
	char *pInitString = NULL;

	if (argc != 2) {
		printf("应该带1个参数！\n\r");
	}
	ch = getopt(argc, argv, "hd:t:");
	switch (ch) {
		case 'd':
			pInitString = optarg;
			break;
		default:
			break;
	}
	RCTraceLevelManager(pInitString);
}

void RCTraceLevelManager(char *pInitString)
{	
	char *pstr_start =NULL;
	char *pstr_end =NULL;
	char *pToken = NULL;
	char *pDelimiter = ",";
	int i = 0;
	char buff[1000];
	
	pstr_start = strstr(pInitString, "e:");
	if(!pstr_start) {
		printf("输入打印等级字符串格式错误！！\n\r");
	}

	pstr_start += 2;
	pstr_end = strstr(pstr_start, ";aS");
	*pstr_end = '\0';

	memset(buff, 0, sizeof(buff));
	strcpy(buff, pstr_start);
	
	pToken = strtok(buff, pDelimiter);
	
	while(pToken)
	{
		if(strpbrk(pToken, "-") != NULL) {
			sscanf(pToken, "%d-%d", &g_arry[i][0], &g_arry[i][1]);
		}
		else {
			g_arry[i][0] = atoi(pToken);
			g_arry[i][1] = atoi(pToken);
		}
		pToken = strtok(NULL,pDelimiter);
		i++;
	}
}





