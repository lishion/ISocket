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
	//��sockaddr_inת��Ϊsockaddr���͵�ָ��
	sockaddr* getStanderStyle() const
	{
		return (sockaddr*)&addr;
	}
	//�õ��������͵ĵ�ַ
	char* getAddrLocalStyle() const
	{
		return inet_ntoa(addr.sin_addr);
	}
	//�õ��������͵Ķ˿�
	int getPortLocalStyle() const
	{
		 
		return ntohs(addr.sin_port);
	}

	void converStoAddr(const char *s,sockaddr_in &addr);//���ַ���ת��Ϊ��ַ����"192.168.0.1:9090",���Ǹõ�ַ�ַ����в��ܴ��ڿո�
	void setAddr(SocketAddr &addr);//���õ�ַ
	void setAddr(const char *s, int port);//���õ�ַ
	static void setAddr(sockaddr_in &addr,const char *s, int port);//���õ�ַ
	void setAddr(const char *s);//���õ�ַ
	string toString() const;//�����ַ�Ͷ˿ں���Ϣ
};

