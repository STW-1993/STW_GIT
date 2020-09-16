/*
 * 消息队列的训练
 */

#include "024_msg_queue.h"
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
	
	/* 0、函数原型：ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg); 
	 * 1、功能：从标识符为msgid的消息队列里接收一个指定类型的消息 并存储于msgp中，读取后把消息从消息队列中删除
	 * 2、参数msgtyp：为 0 表示无论什么类型 都可以接收
	 * 3、参数msgp：存放消息的结构体
	 * 4、参数msgsz：要接收的消息的大小不包含消息类型long mtype占用的字节
	 * 5、msgflg：如果是0标识表示没有指定类型的消息就一直等待，如果是IPC_NOWAIT 则表示不等待
	 */
	msgrcv(msgid, &rcv, sizeof(rcv)-sizeof(type), MSG_TYPE, 0); 
	printf("rcv_name:%s rcv_age:%d \n\r", rcv.name, rcv.age);

	/* 0、函数原型：int msgctl(int msqid, int cmd, struct msqid_ds *buf); 
	 * 1、msgctl(msgid,IPC_RMID，NULL);    //一般用于删除消息队列对象
	 */
	msgctl(msgid, IPC_RMID, NULL);
	
	return 0;
	
}



