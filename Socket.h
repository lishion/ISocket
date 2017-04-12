#pragma once
#include <WinSock2.h>
#include "IEXCEPTION.h"
#include "SockAddr.h"
#include "def.h"
 
namespace ISOCKET{
	

	class Socket{
		friend class  SocketBuilder;
	protected:
		Socket():isBlock(true){};
		SOCKET iSocket;            //ԭʼ�׽���
	public:
		static WSAData *wsa;        //���WINSOCK��Ϣ�Ľṹ��
		SocketAddr socketAddr;     //��ַ
		bool isBlock;              //�Ƿ�����
		typedef SocketAddr ISocketAddr;

		static Socket* converToSocket(SOCKET socket);//���󶨺��ԭʼ�׽���ת��ΪSocket��ַ

		Socket* setBlock(bool flag);//�Ƿ�����
		Socket* bindSocket();       //��
		Socket  clone();            //�õ�һ����¡Socket���� ������ָ��
		Socket* setAddr(char *s);   //���õ�ַ
		Socket* setAddr(char *s,int port);//���õ�ַ
		void release();
		SOCKET getOriginalSocket() const{
			return iSocket;
		}
		virtual ~Socket(){

		}
	};


	 

}


