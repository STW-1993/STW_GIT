/* 
 * ���ڲ��Դ�ӡ�ռ�
 */
#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
	char logstring[256];
	time_t logtime;
	struct tm *pTimeCur;
	
	logtime = time(NULL);
	pTimeCur = localtime(&logtime);

	//�鿴linuxϵͳʱ������ date
	//$(cat /work/huangzhiwei/test/hello.txt)���Զ�ȡĳ���ļ�����Ϊһ������һ��ʹ��
	
	memset(logstring,0,sizeof(logstring));

	sprintf(logstring,"echo %04d-%02d-%02d  %02d:%02d:%02d $(cat /work/huangzhiwei/test/hello.txt) > /work/huangzhiwei/test/log-test",
		pTimeCur->tm_year+1900,pTimeCur->tm_mon+1,pTimeCur->tm_mday,pTimeCur->tm_hour,pTimeCur->tm_min,pTimeCur->tm_sec);
	system(logstring);
	
	memset(logstring,0,sizeof(logstring));
	sprintf(logstring,"echo $(cat /work/huangzhiwei/test/log-test) >> /work/huangzhiwei/test/log");
	system(logstring);
	
	return 0;
}


