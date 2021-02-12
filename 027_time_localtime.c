/*
 * 获取本地时间，时间的差值
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


int main(void)
{
#if 1

	time_t sys_time1, sys_time2;
	struct tm *tm_nowlocaltime;
	
	time(&sys_time1);
	tm_nowlocaltime = localtime(&sys_time1);

	printf("%lu\n\r", sys_time1);
	printf("当前时间为：%d-%d-%d %d:%d:%d\n\r", tm_nowlocaltime->tm_year + 1900, 
		                                        tm_nowlocaltime->tm_mon + 1,
		                                        tm_nowlocaltime->tm_mday,
		                                        tm_nowlocaltime->tm_hour,
		                                        tm_nowlocaltime->tm_min,
		                                        tm_nowlocaltime->tm_sec);
	sleep(10);
	
	time(&sys_time2);
	
	printf("前后时间相差%lu秒。\n\r", sys_time2 - sys_time1);

#endif

#if 0 
	struct tm *tm_nowlocaltime;

	time_t *p_sys_time1 = (time_t *)malloc(sizeof(time_t));
	time_t *p_sys_time2 = (time_t *)malloc(sizeof(time_t));

	time(p_sys_time1);
	tm_nowlocaltime = localtime(p_sys_time1);

	printf("%lu\n\r", *p_sys_time1);
	printf("当前时间为：%d-%d-%d %d:%d:%d\n\r", tm_nowlocaltime->tm_year + 1900, 
		                                        tm_nowlocaltime->tm_mon + 1,
		                                        tm_nowlocaltime->tm_mday,
		                                        tm_nowlocaltime->tm_hour,
		                                        tm_nowlocaltime->tm_min,
		                                        tm_nowlocaltime->tm_sec);
	sleep(10);
	
	time(p_sys_time2);
	
	printf("前后时间相差%lu秒。\n\r", *p_sys_time2 - *p_sys_time1);

	free(p_sys_time1);
	free(p_sys_time2);
	p_sys_time1 = NULL;
	p_sys_time2 = NULL;
	
#endif
	
	return 0;
}



