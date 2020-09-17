/*
 * ��Ϣ���е�ѵ��
 */

#include "test.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	/* 0������ԭ�ͣ�key_t ftok(const char *pathname, int proj_id); ���ܣ�����һ����ֵ
	 * 1��ftok�����Ĳ���snd��rcvҪ����һ�¡�
	 * 2��ftok��������·��������ȡ�ļ���Ϣ���ٸ�����Щ�ļ���Ϣ��project ID�ϳ�key����·������������á�
	 * 3����·���Ǳ�����ڵģ�ftokֻ�Ǹ����ļ�inode��ϵͳ�ڵ�Ψһ����ȡһ����ֵ�����ļ���Ȩ���޹ء�
	 * 4��proj_id�ǿ��Ը����Լ���Լ�����������á��������,�еĳ�֮Ϊproject ID; ��UNIXϵͳ��,����ȡֵ��1��255;
	 */
	key_t key = ftok("/work/huangzhiwei/test",7);     
	printf("Key:%x \n\r", key);

	/* 0������ԭ�ͣ�int msgget(key_t key, int flag|mode); 
	 * 1�����ܣ�������ȡ��һ����Ϣ���ж���
	 * 2�����أ���Ϣ���ж����id ͬһ��key�õ�ͬһ������
	 * 3��flag:������0����IPC_CREAT(�����ھʹ���)
	 * 4��mode:ͬ�ļ�Ȩ��һ��
	 */
	int msgid = msgget(key, IPC_CREAT|O_WRONLY|0777);
	if (msgid < 0) {
		printf("msgget error!\n\r");
		exit(-1);
	}

	Msg m;
	
	printf("please input your  name and age: \n\r");
	scanf("%ld %s %d",&m.type, m.name, &m.age);

	/* 0������ԭ�ͣ�int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg); 
	 * 1�����ܣ���msgp��Ϣд���ʶΪmsgid����Ϣ����
	 * 2������msgp��struct msgbuf {
	 					long mtype;    // message type, must be > 0   ��Ϣ�����ͱ���>0
	 					char mtext[1]; // message data                ��������
	 				};
	 * 3������msgsz��Ҫ���͵���Ϣ�Ĵ�С ��������Ϣ������long mtypeռ�õ��ֽ�
	 * 4������msgflg�������0����Ϣ����Ϊ��ʱmsgsnd�������������IPC_NOWAIT����Ϣ����Ϊ��ʱ��������������
	 */
	msgsnd(msgid, &m, sizeof(m)-sizeof(m.type), 0); 
	
	return 0;
	
}



