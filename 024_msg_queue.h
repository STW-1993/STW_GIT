#ifndef __MSG_QUEUE_H__
#define __MSG_QUEUE_H__

typedef struct {
	long type;           //���Ԫ��һ��Ҫ���ڵ�һλ��������Ϣ���������쳣
	char name[20];
	int age;
}Msg;

#define MSG_TYPE 88

#endif /* __MSG_QUEUE_H__ */
