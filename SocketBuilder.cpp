#include "StdAfx.h"
#include "SocketBuilder.h"


SocketBuilder::SocketBuilder(void)
{
}

void SocketBuilder::createSocket(int socketType){

	socketClass = createSocketWraper();

	socketClass->iSocket = socket(AF_INET,socketType,0);

	if(socketClass->iSocket == SOCKET_ERROR){
		delete socketClass;
		socketClass = nullptr;
		throw IEXPECTION("create socket error!!","createSocket",WSAGetLastError());
	}
}

SocketBuilder::SocketBuilder(int l,int h){

	if(Socket::wsa ==  nullptr){
		Socket::wsa = new WSAData();
		int code =  WSAStartup(MAKEWORD(h,l),Socket::wsa);
		if(code != 0){
			throw IEXPECTION("initial socket error!!","SocketBuilder",code);
		}
	}

}


Socket* SocketBuilder::createUDPScoket(){
	createSocket(SOCK_DGRAM);
	return this->socketClass;
}

Socket* SocketBuilder::createTCPScoket(){
	createSocket(SOCK_STREAM);
	return this->socketClass;
}

SocketBuilder::~SocketBuilder(void)
{
	if(socketClass!=nullptr){
		delete socketClass;
		socketClass = nullptr;
	}
}
