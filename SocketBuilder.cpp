
#include "SocketBuilder.h"
 using namespace ISOCKET;
	SocketBuilder::SocketBuilder(void)
	{
	}

	void SocketBuilder::initSocket(Socket *newSocket,int type){

		newSocket->iSocket = socket(AF_INET,type,0);
		if(newSocket->iSocket == SOCKET_ERROR){

			throw IEXPECTION("create socket error!!","createSocket",WSAGetLastError());
		}
	}

	SocketBuilder::SocketBuilder(int l,int h){

		if(Socket::wsa ==  nullptr){
			Socket::wsa = new WSAData();
			int code =  WSAStartup(MAKEWORD(h,l),Socket::wsa);//≥ı ºªØWinSock
			if(code != 0){
				throw IEXPECTION("initial socket error!!","SocketBuilder",code);
			}
		}

	}

	UDPSocket* SocketBuilder::createUDPScoket(){
		UDPSocket *socket = new UDPSocket();
		initSocket(socket,SOCK_DGRAM);

		return socket;
	}

	TCPSocket* SocketBuilder::createTCPScoket(){
		TCPSocket *socket = new TCPSocket();
		initSocket(socket,SOCK_STREAM);
		return socket;
	}

	SocketBuilder::~SocketBuilder(void)
	{

	}

 
 

