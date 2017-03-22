#pragma once
#include "Socket.h"
#include "IEXCEPTION.h"
class SocketBuilder
{
private:

	Socket *socketClass;
	Socket *createSocketWraper(){
		return new Socket();
	}
	void createSocket(int socketType);
public:

	SocketBuilder(int l,int h);
	Socket* createUDPScoket(); 
	Socket* createTCPScoket(); 

	SocketBuilder(void);
	~SocketBuilder(void);
};

