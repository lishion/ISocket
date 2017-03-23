#pragma once
#include <WinSock2.h>
#include "IEXCEPTION.h"
#include "SockAddr.h"
class Socket{

public:
	static WSAData *wsa;	
	friend class SocketBuilder;

	SOCKET iSocket;
	SocketAddr socketAddr;
	bool isBlock;

	typedef SocketAddr ISocketAddr;

	Socket():isBlock(true){};
	static Socket converToSocket(SOCKET socket);
	Socket* setBlock(bool flag);
	Socket* bindSocket();
	Socket* startListen(int max);
	Socket* startListen();
	Socket* getConection();
	Socket* connectTo(char *s,int port);
	Socket* connectTo(ISocketAddr addr);
	Socket* setAddr(char *s);
	Socket* setAddr(char *s,int port);
	void read(char *buf,int len,Socket *socket);
	void write(char *buf,int len,Socket* socket);
	void write(char *buf,int len);
	void write(char *buf,int len,SOCKET socket);
	~Socket(){
		 closesocket(iSocket);
	}
};

