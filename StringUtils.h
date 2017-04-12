#pragma once
#include <vector>
using namespace std;
class StringUtils
{
public:
	StringUtils(void);
	static vector<string> split(const char *s,char w);
	static vector<string> split(string &s,char w);
	static int convertToInt(const string s);
	static void removeWord(char c,string &s);
	~StringUtils(void);
};

