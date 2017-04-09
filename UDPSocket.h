#pragma once
#include "Socket.h"
namespace ISOCKET{
	class UDPSocket : public Socket
	{
	public:
		UDPSocket(void);
		int writeTo(const char *buf,int len, const Socket *socket);
		int writeTo(const char *buf,int len, const Socket::ISocketAddr &addr);
		int readFrom(char *buf,int len, Socket *socket);

		~UDPSocket(void);
	};
}

