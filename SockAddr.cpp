#include "SockAddr.h"
#include "IEXCEPTION.h"
#include "StringUtils.h"
#include <sstream>
void SocketAddr::setAddr(const char *s, int port){
	setAddr(addr,s,port);
}

void SocketAddr::setAddr(sockaddr_in &addr,const char *s, int port){
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(s);

	memset(&(addr.sin_zero),0,8);
}

void SocketAddr::setAddr(SocketAddr &addr){

	this->addr.sin_family = addr.addr.sin_family;
	this->addr.sin_addr.s_addr = addr.addr.sin_addr.s_addr;
	this->addr.sin_port = addr.addr.sin_port;

	memset(&(this->addr.sin_zero),0,8);
}

void SocketAddr::setAddr(const char *s){
	 converStoAddr(s,addr);
}

void SocketAddr::converStoAddr(const char *s,sockaddr_in &addr){
	auto vecs = StringUtils::split(s,':');
	if(vecs.size()!=2){
		throw IEXPECTION("ip address error!!","converStoAddr",0);
	}
	string ip = vecs[0];
	int port = StringUtils::convertToInt(vecs[1]);
 
	setAddr(addr,ip.c_str() ,port);
}
string SocketAddr::toString() const
{
	stringstream ss;
	ss<<getAddrLocalStyle()<<":"<<getPortLocalStyle();
	return ss.str();

}