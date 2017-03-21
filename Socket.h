#pragma once
#include <WinSock2.h>
#include "SOCKET_EXCEPTION.h"
class Socket{

public:
	static WSAData *wsa;	
	friend class SocketBuilder;
	SOCKET iSocket;
	sockaddr_in sockAddr;
	int addrLength;

	boolean isBlock;

	Socket():addrLength(sizeof(sockAddr)),isBlock(true){}
	
	Socket* setAddr(char *s, int port);
	Socket* setAddr(sockaddr_in &addr,char *s, int port);
	Socket* setBlock(bool flag);
	Socket* bindSocket();
	Socket* startListen(int max);
	Socket* startListen();
	Socket* getConection();
	Socket* connectTo(char *s,int port);
	Socket* connectTo(Socket* socket);
	sockaddr* toStanderStyle(){
		return (sockaddr*)&sockAddr;
	}
	char* getAddrLocalStyle(){
		return inet_ntoa(sockAddr.sin_addr);
	}
	int getPortLocalStyle(){
		return ntohs(sockAddr.sin_port);
	}
	void read(char *buf,int len,Socket *socket);
	void write(char *buf,int len,Socket* socket);

	~Socket(){
		if(wsa!=nullptr){
			delete wsa;
			wsa = nullptr;
		}
	}
};

