#pragma once
#include <WinSock2.h>
#include "IEXCEPTION.h"
#include "SockAddr.h"
class Socket{

public:
	static WSAData *wsa;        //存放WINSOCKET信息的结构体
	friend class SocketBuilder;
	SOCKET iSocket;            //套接字
	SocketAddr socketAddr;     //地址
	bool isBlock;              //是否阻塞
	typedef SocketAddr ISocketAddr;

	Socket():isBlock(true){};

	static Socket* converToSocket(SOCKET socket);//将绑定后的原始套接字转换为Socket地址

	Socket* setBlock(bool flag);//是否阻塞
	Socket* bindSocket();       //绑定
	Socket  clone();            //得到一个克隆Socket对象 而不是指针
	Socket* setAddr(char *s);   //设置地址
	Socket* setAddr(char *s,int port);//设置地址

	virtual ~Socket(){

	}
};

