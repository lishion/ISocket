
#include "UDPSocket.h"


UDPSocket::UDPSocket(void)
{
}

int UDPSocket::writeTo(char *buf,int len, const Socket *socket){
	int code = sendto(iSocket,buf,len,0,(socket->socketAddr.getStanderStyle()),socket->socketAddr.addrLength);
	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","writeTo",WSAGetLastError());
	}
	return code;
}

int UDPSocket::readFrom(char *buf,int len, Socket *socket){
	int code = recvfrom(iSocket,buf,len,0,(socket->socketAddr.getStanderStyle()),&(socket->socketAddr.addrLength));
	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("read error!!","readFrom",WSAGetLastError());
	}
	return code;
}

UDPSocket::~UDPSocket(void)
{

}
