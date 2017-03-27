#pragma once
#include "TCPSocket.h"
#include "UDPSocket.h"
#include "IEXCEPTION.h"
class SocketBuilder
{
private:
	void initSocket(Socket *newSocket,int type);
	 
public:
	
	SocketBuilder(int l,int h);

	UDPSocket* createUDPScoket(); 
	TCPSocket* createTCPScoket(); 

	SocketBuilder(void);
	~SocketBuilder(void);
};

