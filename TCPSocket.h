#pragma once
#include "Socket.h"
class TCPSocket:public Socket
{
public:
	TCPSocket(void);
	TCPSocket* startListen(int max);//��ʼ����,max ���Ӷ������ֵ
	TCPSocket* startListen();      //��ʼ������Ĭ��10��

	TCPSocket* getConection();    //�õ�����
	void getConection(TCPSocket *socket);//�õ����Ӳ����ڳ�ʼ��һ��Socket*���͵�ָ��

	TCPSocket* connectTo(char *s,int port);//���ӵ�
	TCPSocket* connectTo(ISocketAddr addr);



	int read(char *buf,int len,const Socket *socket);//����
	int read(char *buf,int len);
	int read(char *buf,int len,SOCKET socket);

	int write(char *buf,int len,const Socket* socket);//����
	int write(char *buf,int len);
	int write(char *buf,int len,SOCKET socket);

	~TCPSocket(void);
};

