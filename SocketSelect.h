#pragma once
#include <WinSock2.h>
#include "def.h"
namespace ISOCKET{

	class SocketSelect
	{
	private:
		timeval tv;
		fd_set* socketSetArry[5];

	public:
		fd_set socketSet;

		SocketSelect(void);

		SocketSelect* setBlockTime(long s,long ms);

		void addSocket(SOCKET s){
			FD_SET(s,&socketSet);
		}

		int selectSockets(unsigned char type);
		void clearSockets();
		bool contain(SOCKET socket);

		~SocketSelect(void);
	};
}

