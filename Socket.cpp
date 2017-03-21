#include "Socket.h"
WSAData* Socket::wsa = nullptr;
Socket* Socket::setAddr(char *s, int port){
	
	setAddr(this->sockAddr,s,port);
	return this;

}

Socket* Socket::setAddr(sockaddr_in &addr,char *s, int port){
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(s);

	memset(&(addr.sin_zero),0,8);
	return this;
}

Socket* Socket::setBlock(bool flag){

	long blcok = (isBlock = flag) ? 0 : 1;
	int code = ioctlsocket( iSocket, FIONBIO,(u_long*)&blcok);
	if(code == SOCKET_ERROR){
		throw SOCKET_EXPECTION("socket error!!","setBlock",WSAGetLastError());
	}
	return this;
}

Socket* Socket:: bindSocket(){

	int code =  bind( iSocket,toStanderStyle(),sizeof(sockAddr) );
	if(code == SOCKET_ERROR){
		throw SOCKET_EXPECTION("bind socket error!!","bindSocket",WSAGetLastError());
	}
	return this;
}

Socket* Socket::startListen(int max){
	int code =  listen(iSocket,max);
	if(code == SOCKET_ERROR){
		throw SOCKET_EXPECTION("start listen error!!","startListen",WSAGetLastError());
	}
	return this;
}

Socket* Socket::startListen(){
	 startListen(10);
	 return this;
}

Socket* Socket::getConection(){ 
	Socket *socket = new Socket();
	
	 
	socket->iSocket = accept(this->iSocket,toStanderStyle(),&(socket->addrLength));

	if(isBlock == false){
		return nullptr;
	}

	if(socket->iSocket == SOCKET_ERROR){
		delete socket;
		socket = nullptr;
		throw SOCKET_EXPECTION("accept error!!","getConection",WSAGetLastError());
		 
	}

	return socket;
}

Socket* Socket::connectTo(char *s,int port){

	sockaddr_in addr;
	setAddr(addr,s,port);

	int code = connect(iSocket,(sockaddr*)&(addr),sizeof(addr));

	if(code == SOCKET_ERROR){

		throw SOCKET_EXPECTION("connection error!!","connectTo",WSAGetLastError());
	}
	return this;
}

Socket* Socket::connectTo(Socket* socket){
	int code = connect(iSocket,toStanderStyle(),socket->addrLength);
	if(code == SOCKET_ERROR){

		throw SOCKET_EXPECTION("connection error!!","connectTo",WSAGetLastError());
	}
	return this;
}

void Socket::read(char *buf,int len,Socket *socket){

	int code = recv(socket->iSocket,buf,len,0);

	if(code == SOCKET_ERROR){

		throw SOCKET_EXPECTION("read error!!","read",WSAGetLastError());
	}
}

void Socket::write(char *buf,int len,Socket* socket){

	int code = send(socket->iSocket,buf,strlen(buf),0);

	if(code == SOCKET_ERROR){

		throw SOCKET_EXPECTION("write error!!","write",WSAGetLastError());
	}
}
