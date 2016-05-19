#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	string Data,T;
	int in;
	char data[8];
	char to[8];
	while(cin>>data>>in>>T)
	{
		strncpy(data,Data.c_str(),Data.length());
		strncpy(to,T.c_str(),T.length());
		
		printf("%7.s\n",&to);
	}
	return 0;
}
