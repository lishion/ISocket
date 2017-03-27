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
	//将sockaddr_in转换为sockaddr类型的指针
	sockaddr* getStanderStyle() const
	{
		return (sockaddr*)&addr;
	}
	//得到本地类型的地址
	char* getAddrLocalStyle() const
	{
		return inet_ntoa(addr.sin_addr);
	}
	//得到本地类型的端口
	int getPortLocalStyle() const
	{
		 
		return ntohs(addr.sin_port);
	}

	void converStoAddr(const char *s,sockaddr_in &addr);//将字符串转换为地址，如"192.168.0.1:9090",但是该地址字符串中不能存在空格
	void setAddr(SocketAddr &addr);//设置地址
	void setAddr(const char *s, int port);//设置地址
	static void setAddr(sockaddr_in &addr,const char *s, int port);//设置地址
	void setAddr(const char *s);//设置地址
	string toString() const;//输出地址和端口号信息
};

