#pragma once
#include <WinSock2.h>
 
namespace ISocket{

	const  unsigned char READ = 0X01;
	const  unsigned char WRITE = 0X02;
	const  unsigned char EXCEPTION = 0X04;

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

