#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "RCTrace.h"

int g_arr[G_ARR_NUM][2];

void RCTraceDBG(int nLv,char *format,...)
{	
	int i;
	va_list args;
	va_start(args,format);

	for (i=0; i < G_ARR_NUM; i++) {
		if (g_arr[i][0] == 0) {
			break;
		}
		else {
			if (nLv >= g_arr[i][0] && nLv <= g_arr[i][1]) {
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
	pstr_start += 2;
	pstr_end = strstr(pstr_start, ";aS");
	*pstr_end = '\0';

	memset(buff, 0, sizeof(buff));
	strcpy(buff, pstr_start);
	
	pToken = strtok(buff, pDelimiter);
	while(pToken) {
		if(strpbrk(pToken, "-") != NULL) {
			sscanf(pToken, "%d-%d", &g_arr[i][0], &g_arr[i][1]);
		}
		else {
			g_arr[i][0] = atoi(pToken);
			g_arr[i][1] = atoi(pToken);
		}
		pToken = strtok(NULL, pDelimiter);
		i++;
	}
}





