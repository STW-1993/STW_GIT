/*
 * socket������ѵ��
 */

//client.c
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(void)
{
	int cfd;   //�ļ�������
	int recbytes;
	int sin_size;
	char buffer[1024] = {0};           //���ջ�����
	struct sockaddr_in s_add, c_add;   //�洢����˺ͱ��˵�ip���˿ڵ���Ϣ�ṹ��
	unsigned short portnum = 0x8888;   //�����ʹ�õ�ͨ�Ŷ˿ڣ����Ը��ģ���ͷ������ͬ

	printf("Hello, welcome to client!\n\r");

	//����socket��ʹ����������ʹ��TCP��ʽ����
	cfd = socket(AF_INET, SOCK_STREAM, 0);   
	if (-1 == cfd) {
		printf("socket fail!\n\r");
		return -1;
	}
	printf("socket ok!\n\r");

	//����������˵�ip�Ͷ˿���Ϣ������ṹ����Բ�����
	bzero(&s_add, sizeof(struct sockaddr_in));
	s_add.sin_family = AF_INET;
	s_add.sin_addr.s_addr = inet_addr("172.16.89.204"); //ipת��Ϊ4�ֽ����Σ�ʹ��ʱ���Ը��ݷ����ip�����޸�
	s_add.sin_port = htons(portnum);   /* ����htons�ǽ�short�������ֽ�����������ת��Ϊ�����ͣ���ʵ���� 
    	��2�ֽ����ݵ�ǰ�������ֽڵ������Ͷ�Ӧ��ntohsЧ����ʵ����ͬ��ֻ�������ֲ�ͬ��htonl��ntohl�� 
    	������4�ֽ����Ρ���0x12345678��Ϊ0x78563412�����ֲ�ͬ������������ͬ��һ�����������Ϊ��ˣ� 
   		PPC��cpuΪ��ˣ�x86��cpuΪС�ˣ�arm�Ŀ������ô�С�ˣ���Ҫ��֤����ʱ�ֽ�����ȷ�� 
 	*/ 

	//�����ӡ��������С�˵ģ�������ƽʱ���������෴��
	printf("s_addr = %#x, port = %#x \n\r", s_add.sin_addr.s_addr, s_add.sin_port);

	//�ͻ������ӷ���������������Ϊsocket�ļ�����������ַ��Ϣ����ַ�ṹ��С
	if (-1 == connect(cfd, (struct sockaddr *)(&s_add), sizeof(struct sockaddr))) {
		printf("connect fail!\n\r");
		return -1;
	}
	printf("connect ok!\n\r");

	//���ӳɹ����ӷ���˽����ַ�
	if (-1 == (recbytes = read(cfd, buffer, 1024))) {
		printf("read data fail !\n\r");
		return -1;
	}
	printf("read ok!\n\r REC:\n\r");

	buffer[recbytes] = '\0';
	printf("buffer: %s\n\r", buffer);

	getchar();   //�˾�Ϊ�ǳ�����ͣ�ڴ˴�������ʹ��netstat�鿴��ǰ������
	close(cfd);  //�ر����ӣ�����ͨ�����
	
	return 0;
}



