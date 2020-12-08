/*
 * socket网络编程训练
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
	int sfp, nfp;                      //定义两个描述符
	struct sockaddr_in s_add, c_add;
	int sin_size;
	unsigned short portnum = 0x8888;   //服务端端口

	printf("Hello, welcome to my server!\n\r");
	sfp = socket(AF_INET, SOCK_STREAM, 0);

	if (-1 == sfp) {
		printf("socket fail!\n\r");
		return -1;
	}
	printf("socket ok!\n\r");

	//填充服务器端口地址信息，以便下面使用此地址和端口监听
	bzero(&s_add, sizeof(struct sockaddr_in));
	s_add.sin_family = AF_INET;
	s_add.sin_addr.s_addr = htonl(INADDR_ANY); //这里地址使用全0，即所有地址
	s_add.sin_port = htons(portnum);

	//使用bind进行绑定窗口
	if (-1 == bind(sfp, (struct sockaddr *)(&s_add), sizeof(struct sockaddr))) {
		printf("bind fail !\n\r");
		return -1;
	}
	printf("bind ok!\n\r");

	//开始监听响应的端口
	if (-1 == listen(sfp, 5)) {
		printf("listen fail! \n\r");
		return -1;
	}
	printf("listen ok !\n\r");

	while (1) {
		sin_size = sizeof(struct sockaddr_in);
		/* accept服务端使用函数，调用时即进入阻塞状态，等待用户进行连接，在没有客户端进行连接时，
		 * 程序停止在此处，不会看到后面的打印，当有客户端进行连接时，程序马上执行一次，然后再次循
		 * 环到此处继续等待。此处accept的第二个参数用于获取客户端的端口和地址信息。 
         */ 
		nfp = accept(sfp, (struct sockaddr *)(&c_add), &sin_size);

		if (-1 == nfp) {
			printf("accept fail! \n\r");
			return -1;
		}
		printf("accept ok! \n\r Server start get connect from %#x : %#x\n\r", ntohl(c_add.sin_addr.s_addr), 
			   ntohs(c_add.sin_port));

		//这里使用write向客户端发送信息，也可以尝试使用其他函数实现
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



