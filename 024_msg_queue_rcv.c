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
	key_t key = ftok("/work/huangzhiwei/test",7);
	printf("Key:%x \n\r", key);

	int msgid = msgget(key, O_RDONLY);
	if (msgid < 0) {
		printf("msgget error!\n\r");
		exit(-1);
	}

	Msg rcv;
	long type;
	
	/* 0������ԭ�ͣ�ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg); 
	 * 1�����ܣ��ӱ�ʶ��Ϊmsgid����Ϣ���������һ��ָ�����͵���Ϣ ���洢��msgp�У���ȡ�����Ϣ����Ϣ������ɾ��
	 * 2������msgtyp��Ϊ 0 ��ʾ����ʲô���� �����Խ���
	 * 3������msgp�������Ϣ�Ľṹ��
	 * 4������msgsz��Ҫ���յ���Ϣ�Ĵ�С��������Ϣ����long mtypeռ�õ��ֽ�
	 * 5��msgflg�������0��ʶ��ʾû��ָ�����͵���Ϣ��һֱ�ȴ��������IPC_NOWAIT ���ʾ���ȴ�
	 */
	while (msgrcv(msgid, &rcv, sizeof(rcv)-sizeof(type), 0, 0) > 0)
		if (rcv.type == MSG_TYPE)
			printf("rcv_type:%ld rcv_name:%s rcv_age:%d \n\r", rcv.type, rcv.name, rcv.age);

	/* 0������ԭ�ͣ�int msgctl(int msqid, int cmd, struct msqid_ds *buf); 
	 * 1��msgctl(msgid,IPC_RMID��NULL);    //һ������ɾ����Ϣ���ж���
	 */
	//msgctl(msgid, IPC_RMID, NULL);
	
	return 0;
	
}



