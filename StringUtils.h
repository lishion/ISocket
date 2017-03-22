#pragma once
#include <vector>
using namespace std;
class StringUtils
{
public:
	StringUtils(void);
	static vector<string> split(const char *s,char w);
	static int convertToInt(const string s);
	~StringUtils(void);
};

