#include "TCPSocket.h"
using namespace ISOCKET;

TCPSocket::TCPSocket(void)
{
}

TCPSocket* TCPSocket::startListen(int max){
	int code =  listen(iSocket,max);
	if(code == SOCKET_ERROR){
		throw IEXPECTION("start listen error!!","startListen",WSAGetLastError());
	}
	return this;
}

TCPSocket* TCPSocket::startListen(){
	startListen(10);
	return this;
}

TCPSocket* TCPSocket::getConection(){ 

	TCPSocket *socket = new TCPSocket();
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

void TCPSocket::getConection(TCPSocket *socket){

	socket->iSocket = accept(this->iSocket,socket->socketAddr.getStanderStyle(),&(socket->socketAddr.addrLength));

	if(socket->iSocket == SOCKET_ERROR){
		if(isBlock){	
			throw IEXPECTION("accept error!!","getConection",WSAGetLastError());
		}
	}
}

TCPSocket* TCPSocket::connectTo(char *s,int port){

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

TCPSocket* TCPSocket::connectTo(ISocketAddr addr){
	int code = connect(iSocket,addr.getStanderStyle(),(addr.addrLength));

	if(isBlock == false){
		return this;
	}
	if(code == SOCKET_ERROR){

		throw IEXPECTION("connection error!!","connectTo",WSAGetLastError());
	}
	return this;
}

int TCPSocket::read(char *buf,int len,const Socket *socket){

	int code = recv(socket->getOriginalSocket(),buf,len,0);


	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("read error!!","read",WSAGetLastError());
	}

	return code;
}

int TCPSocket::read(char *buf,int len){

	int code = recv(this->iSocket,buf,len,0);


	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("read error!!","read",WSAGetLastError());
	}
	return code;
}

int TCPSocket::read(char *buf,int len,SOCKET socket){

	int code = recv(socket,buf,len,0);


	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("read error!!","read",WSAGetLastError());
	}
	return code;
}

int TCPSocket::write(char *buf,int len,const Socket* socket){

	int code = send(socket->getOriginalSocket(),buf,strlen(buf),0);

	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","write",WSAGetLastError());
	}
	return code;
}


int TCPSocket::write(char *buf,int len){
	int code = send(iSocket,buf,strlen(buf),0);

	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","write",WSAGetLastError());
	}
	return code;
}

int TCPSocket::write(char *buf,int len,SOCKET socket){
	int code = send(socket,buf,strlen(buf),0);

	if(code == SOCKET_ERROR && isBlock == true){

		throw IEXPECTION("write error!!","write",WSAGetLastError());
	}
	return code;
}

TCPSocket::~TCPSocket(void)
{
}
