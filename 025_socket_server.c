/*
 * socket������ѵ��
 */


//server.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void)
{
	int sfp, nfp;                      //��������������
	struct sockaddr_in s_add, c_add;
	int sin_size;
	unsigned short portnum = 0x8888;   //����˶˿�

	printf("Hello, welcome to my server!\n\r");
	sfp = socket(AF_INET, SOCK_STREAM, 0);

	if (-1 == sfp) {
		printf("socket fail!\n\r");
		return -1;
	}
	printf("socket ok!\n\r");

	//���������˿ڵ�ַ��Ϣ���Ա�����ʹ�ô˵�ַ�Ͷ˿ڼ���
	bzero(&s_add, sizeof(struct sockaddr_in));
	s_add.sin_family = AF_INET;
	s_add.sin_addr.s_addr = htonl(INADDR_ANY); //�����ַʹ��ȫ0�������е�ַ
	s_add.sin_port = htons(portnum);

	//ʹ��bind���а󶨴���
	if (-1 == bind(sfp, (struct sockaddr *)(&s_add), sizeof(struct sockaddr))) {
		printf("bind fail !\n\r");
		return -1;
	}
	printf("bind ok!\n\r");

	//��ʼ������Ӧ�Ķ˿�
	if (-1 == listen(sfp, 5)) {
		printf("listen fail! \n\r");
		return -1;
	}
	printf("listen ok !\n\r");

	while (1) {
		sin_size = sizeof(struct sockaddr_in);
		/* accept�����ʹ�ú���������ʱ����������״̬���ȴ��û��������ӣ���û�пͻ��˽�������ʱ��
		 * ����ֹͣ�ڴ˴������ῴ������Ĵ�ӡ�����пͻ��˽�������ʱ����������ִ��һ�Σ�Ȼ���ٴ�ѭ
		 * �����˴������ȴ����˴�accept�ĵڶ����������ڻ�ȡ�ͻ��˵Ķ˿ں͵�ַ��Ϣ�� 
         */ 
		nfp = accept(sfp, (struct sockaddr *)(&c_add), &sin_size);

		if (-1 == nfp) {
			printf("accept fail! \n\r");
			return -1;
		}
		printf("accept ok! \n\r Server start get connect from %#x : %#x\n\r", ntohl(c_add.sin_addr.s_addr), 
			   ntohs(c_add.sin_port));

		//����ʹ��write��ͻ��˷�����Ϣ��Ҳ���Գ���ʹ����������ʵ��
		if (-1 == write(nfp, "hello, welcome to my server !\n\r", 32)) {
			printf("write fail!\n\r");
			return -1;
		}
		printf("write ok!\n\r");
		close(nfp);
	}

	close(sfp);
	return 0;
}



