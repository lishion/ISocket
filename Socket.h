#pragma once
#include <WinSock2.h>
#include "IEXCEPTION.h"
#include "SockAddr.h"
class Socket{

public:
	static WSAData *wsa;        //���WINSOCKET��Ϣ�Ľṹ��
	friend class SocketBuilder;
	SOCKET iSocket;            //�׽���
	SocketAddr socketAddr;     //��ַ
	bool isBlock;              //�Ƿ�����
	typedef SocketAddr ISocketAddr;

	Socket():isBlock(true){};

	static Socket* converToSocket(SOCKET socket);//���󶨺��ԭʼ�׽���ת��ΪSocket��ַ

	Socket* setBlock(bool flag);//�Ƿ�����
	Socket* bindSocket();       //��
	Socket  clone();            //�õ�һ����¡Socket���� ������ָ��
	Socket* setAddr(char *s);   //���õ�ַ
	Socket* setAddr(char *s,int port);//���õ�ַ

	virtual ~Socket(){

	}
};

