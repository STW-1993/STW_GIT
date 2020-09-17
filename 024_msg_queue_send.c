/*
 * 消息队列的训练
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
	/* 0、函数原型：key_t ftok(const char *pathname, int proj_id); 功能：生成一个键值
	 * 1、ftok函数的参数snd和rcv要保持一致。
	 * 2、ftok函数根据路径名，提取文件信息，再根据这些文件信息及project ID合成key，该路径可以随便设置。
	 * 3、该路径是必须存在的，ftok只是根据文件inode在系统内的唯一性来取一个数值，和文件的权限无关。
	 * 4、proj_id是可以根据自己的约定，随意设置。这个数字,有的称之为project ID; 在UNIX系统上,它的取值是1到255;
	 */
	key_t key = ftok("/work/huangzhiwei/test",7);     
	printf("Key:%x \n\r", key);

	/* 0、函数原型：int msgget(key_t key, int flag|mode); 
	 * 1、功能：创建或取得一个消息队列对象
	 * 2、返回：消息队列对象的id 同一个key得到同一个对象
	 * 3、flag:可以是0或者IPC_CREAT(不存在就创建)
	 * 4、mode:同文件权限一样
	 */
	int msgid = msgget(key, IPC_CREAT|O_WRONLY|0777);
	if (msgid < 0) {
		printf("msgget error!\n\r");
		exit(-1);
	}

	Msg m;
	
	printf("please input your  name and age: \n\r");
	scanf("%ld %s %d",&m.type, m.name, &m.age);

	/* 0、函数原型：int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg); 
	 * 1、功能：将msgp消息写入标识为msgid的消息队列
	 * 2、参数msgp：struct msgbuf {
	 					long mtype;    // message type, must be > 0   消息的类型必须>0
	 					char mtext[1]; // message data                长度随意
	 				};
	 * 3、参数msgsz：要发送的消息的大小 不包括消息的类型long mtype占用的字节
	 * 4、参数msgflg：如果是0当消息队列为满时msgsnd会阻塞，如果是IPC_NOWAIT当消息队列为满时不阻塞立即返回
	 */
	msgsnd(msgid, &m, sizeof(m)-sizeof(m.type), 0); 
	
	return 0;
	
}



