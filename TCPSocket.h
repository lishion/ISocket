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

	TCPSocket* connectTo(char *s,int port);//连接到
	TCPSocket* connectTo(ISocketAddr addr);



	int read(char *buf,int len,const Socket *socket);//接受
	int read(char *buf,int len);
	int read(char *buf,int len,SOCKET socket);

	int write(char *buf,int len,const Socket* socket);//发送
	int write(char *buf,int len);
	int write(char *buf,int len,SOCKET socket);

	~TCPSocket(void);
};

