#include "SocketSelect.h"

using namespace ISOCKET;
SocketSelect::SocketSelect(void)
{
	FD_ZERO(&socketSet);
	tv.tv_sec = 2;
	tv.tv_usec = 0;
	socketSetArry[0] = nullptr;
	socketSetArry[1] = &socketSet;
	socketSetArry[2] = &socketSet;
	socketSetArry[3] = nullptr;
	socketSetArry[4] = &socketSet;
 
}

int SocketSelect::selectSockets(unsigned char type){

	return select(0,socketSetArry[type&READ],
		socketSetArry[type&WRITE],
		socketSetArry[type&EXCEPTION],
		&tv);

}

SocketSelect* SocketSelect::setBlockTime(long s,long ms){
	tv.tv_sec = s;
	tv.tv_usec = ms;
	return this;
}

void SocketSelect::clearSockets(){
	FD_ZERO(&socketSet);
}

bool SocketSelect::contain(SOCKET socket){
	return ( FD_ISSET(socket,&socketSet) == 0);
}

SocketSelect::~SocketSelect(void)
{
}
