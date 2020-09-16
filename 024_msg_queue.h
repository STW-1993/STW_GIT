#ifndef __MSG_QUEUE_H__
#define __MSG_QUEUE_H__

typedef struct {
	long type;           //这个元素一定要放在第一位，否则消息队列数据异常
	char name[20];
	int age;
}Msg;

#define MSG_TYPE 88

#endif /* __MSG_QUEUE_H__ */
