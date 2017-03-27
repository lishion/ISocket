#include "Socket.h"
WSAData* Socket::wsa = nullptr;
 

Socket* Socket::setBlock(bool flag){

	long blcok = (isBlock = flag) ? 0 : 1;
	int code = ioctlsocket( iSocket, FIONBIO,(u_long*)&blcok);
	if(code == SOCKET_ERROR){
		throw IEXPECTION("socket error!!","setBlock",WSAGetLastError());
	}
	return this;
}

Socket* Socket:: bindSocket(){

	int code =  bind( iSocket,socketAddr.getStanderStyle(),socketAddr.addrLength );
	if(code == SOCKET_ERROR){
		throw IEXPECTION("bind socket error!!","bindSocket",WSAGetLastError());
	}
	return this;
}
Socket* Socket::setAddr(char *s){
	socketAddr.setAddr(s);
	return this;
}

Socket* Socket::setAddr(char *s,int port){
	socketAddr.setAddr(s,port);
	return this;
}


Socket* Socket::converToSocket(SOCKET socket){
	Socket *newSocket = new Socket();
	newSocket->iSocket = socket;
	int code = getsockname(socket,newSocket->socketAddr.getStanderStyle(),&(newSocket->socketAddr.addrLength));
	if(code == SOCKET_ERROR ){

		throw IEXPECTION("get name error!!","converToSocket",WSAGetLastError());
	}
	return newSocket;
}

Socket Socket::clone(){
	Socket newSocket;

	newSocket.isBlock = isBlock;
	newSocket.iSocket = iSocket;
	newSocket.socketAddr = socketAddr;

	return newSocket;
}