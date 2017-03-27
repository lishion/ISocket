#pragma once
#include <WinSock2.h>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
class SocketAddr
{
public:

	sockaddr_in addr;
	int addrLength;
	SocketAddr(void){
		addrLength = sizeof(sockaddr_in);
	}
	SocketAddr(const char *s){
		setAddr(s);
	}

	SocketAddr(const char *s,int port){
		setAddr(s,port);
	}
	sockaddr* getStanderStyle() const
	{
		return (sockaddr*)&addr;
	}
	char* getAddrLocalStyle() const
	{
		return inet_ntoa(addr.sin_addr);
	}
	int getPortLocalStyle() const
	{
		 

		return ntohs(addr.sin_port);
	}

 
	void converStoAddr(const char *s,sockaddr_in &addr);

	void setAddr(SocketAddr &addr);
	void setAddr(const char *s, int port);
	static void setAddr(sockaddr_in &addr,const char *s, int port);
	void setAddr(const char *s);
	string toString() const;
};

