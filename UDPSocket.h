#pragma once
#include "Socket.h"
class UDPSocket : public Socket
{
public:
	UDPSocket(void);
	int writeTo(char *buf,int len, const Socket *socket);
 
	int readFrom(char *buf,int len, Socket *socket);

	~UDPSocket(void);
};

