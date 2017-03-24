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

Socket* Socket::startListen(int max){
	int code =  listen(iSocket,max);
	if(code == SOCKET_ERROR){
		throw IEXPECTION("start listen error!!","startListen",WSAGetLastError());
	}
	return this;
}

Socket* Socket::startListen(){
	 startListen(10);
	 return this;
}

Socket* Socket::getConection(){ 

	Socket *socket = new Socket();
	socket->iSocket = accept(this->iSocket,socket->socketAddr.getStanderStyle(),&(socket->socketAddr.addrLength));

	if(socket->iSocket == SOCKET_ERROR){

		delete socket;
		socket = nullptr;

		if(isBlock){	
			throw IEXPECTION("accept error!!","getConection",WSAGetLastError());
		}else{
			return nullptr;
		}
	}

	return socket;
}

void Socket::getConection(Socket *socket){
 
	socket->iSocket = accept(this->iSocket,socket->socketAddr.getStanderStyle(),&(socket->socketAddr.addrLength));

	if(socket->iSocket == SOCKET_ERROR){
		if(isBlock){	
			throw IEXPECTION("accept error!!","getConection",WSAGetLastError());
		}
	}
}

Socket* Socket::connectTo(char *s,int port){

	ISocketAddr addr;

	addr.setAddr(s,port);

	int code = connect(iSocket,addr.getStanderStyle(),addr.addrLength);

	if(isBlock == false){
		return this;
	}
	if(code == SOCKET_ERROR){

		throw IEXPECTION("connection error!!","connectTo",WSAGetLastError());
	}
	return this;
}

Socket* Socket::connectTo(ISocketAddr addr){
	int code = connect(iSocket,addr.getStanderStyle(),(addr.addrLength));
	 
	if(isBlock == false){
		return this;
	}
	if(code == SOCKET_ERROR){

		throw IEXPECTION("connection error!!","connectTo",WSAGetLastError());
	}
	return this;
}

void Socket::read(char *buf,int len,Socket *socket){

	int code = recv(socket->iSocket,buf,len,0);

 
	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("read error!!","read",WSAGetLastError());
	}
}

void Socket::write(char *buf,int len,Socket* socket){

	int code = send(socket->iSocket,buf,strlen(buf),0);

	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","write",WSAGetLastError());
	}
}

Socket* Socket::setAddr(char *s){
	socketAddr.setAddr(s);
	return this;
}

Socket* Socket::setAddr(char *s,int port){
	socketAddr.setAddr(s,port);
	return this;
}

void Socket::write(char *buf,int len){
	int code = send(iSocket,buf,strlen(buf),0);

	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","write",WSAGetLastError());
	}
}

void Socket::write(char *buf,int len,SOCKET socket){
	int code = send(socket,buf,strlen(buf),0);

	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","write",WSAGetLastError());
	}
}

Socket Socket::converToSocket(SOCKET socket){
	Socket newSocket;
	newSocket.iSocket = socket;
	int code = getsockname(socket,newSocket.socketAddr.getStanderStyle(),&(newSocket.socketAddr.addrLength));
	if(code == SOCKET_ERROR ){

		throw IEXPECTION("get name error!!","converToSocket",WSAGetLastError());
	}
	return newSocket;
}