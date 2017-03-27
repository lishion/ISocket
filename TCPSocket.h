#pragma once
#include "Socket.h"
class TCPSocket:public Socket
{
public:
	TCPSocket(void);
	TCPSocket* startListen(int max);//开始监听,max 连接队列最大值
	TCPSocket* startListen();      //开始监听，默认10个

	TCPSocket* getConection();    //得到连接
	void getConection(TCPSocket *socket);//得到连接并用于初始化一个Socket*类型的指针

	TCPSocket* connectTo(char *s,int port);//建立连接
	TCPSocket* connectTo(ISocketAddr addr);

	int read(char *buf,int len,const Socket *socket);//通过一个Socket对象接收,多用于服务器
	int read(char *buf,int len);//利用自身的SOCKET接收，多用于客户端
	int read(char *buf,int len,SOCKET socket);//通过原始的SOCKET接受

	int write(char *buf,int len,const Socket* socket);//发送，同上
	int write(char *buf,int len);
	int write(char *buf,int len,SOCKET socket);

	~TCPSocket(void);
};

