#include "StringUtils.h"
#include "IEXCEPTION.h"
#include <math.h>
StringUtils::StringUtils(void)
{
}

vector<string> StringUtils::split(const char *s,char w){

	string str(s);
	vector<string> vecs;
	int index = 0;
	int lastIndex = 0;
	while( str.find(w) != string::npos ){
		if(str.at(index) == w){
			if(index !=0 ){
				vecs.push_back(str.substr(0,index));
			}
			str.erase(0,index+1);
			index = 0;
		}else{
			index++;
		}

	}
	if(str.size()>0){
		vecs.push_back(str);
	}
	return vecs;
}

int StringUtils::convertToInt(const string s){
	auto pow10 = [](int x)->int{
		int y = 1;
		for(int i=0;i<x;i++){
			y*=10;
		}
		return y;
	};

	int x = 0;
	int size = s.size();
	for(int i= 0;i<size;i++){
		if(s.at(i)<'0' || s.at(i)>'9'){
			throw IEXPECTION("invaid number format!!","convertToInt",0);
		}
		x += (s.at(i)-'0') * pow10((size-i-1));
		
	}
	return x;
}


StringUtils::~StringUtils(void)
{
}
