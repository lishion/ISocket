#pragma  once
#include <iostream>
#include <sstream>
using namespace std;

class IEXPECTION{
public:
	string errorInfo;
	string functionName;
	int errorCode;
	IEXPECTION(string s,string f, int c):errorInfo(s),errorCode(c),functionName(f){};
	string getExpectStr(){
		 stringstream ss;
		 ss<<" exception: "<<errorInfo<<" function: "<<functionName<<" code: "<<errorCode;
		 return ss.str();

	}
};