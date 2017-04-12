 #include "UDPSocket.h"

using namespace ISOCKET;
UDPSocket::UDPSocket(void)
{
}

int UDPSocket::writeTo(const char *buf,int len, const Socket *socket){
	int code = sendto(iSocket,buf,len,0,(socket->socketAddr.getStanderStyle()),socket->socketAddr.addrLength);
	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","writeTo",WSAGetLastError());
	}
	return code;
}

int UDPSocket::writeTo(const char *buf,int len, const Socket::ISocketAddr &addr){

	int code = sendto(iSocket,buf,len,0,addr.getStanderStyle(),addr.addrLength);

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

int UDPSocket::readFrom(char *buf,int len,  Socket::ISocketAddr &addr){

	int code = recvfrom(iSocket,buf,len,0,(addr.getStanderStyle()),&(addr.addrLength));
	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("read error!!","readFrom",WSAGetLastError());
	}
	return code;
}
UDPSocket::~UDPSocket(void)
{

}
