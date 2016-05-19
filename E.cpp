#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char ch[256];
	int i,length;
	int Quicksum;
	string input;
	int t;
	while(getline(cin,input))
	{
		memset(ch,'\0',256);
		strcpy(ch,input.c_str());
		Quicksum = 0;
		length = strlen(ch);
		if(ch[0] == '#')
		{
			break;
		}
		else
		{
			for(i = 0;i < length;i++)
			{
				if(ch[i] == ' ')
				{
					t = 0;
				}
				else
				{
					t = ch[i]-'A'+1;
				}
				Quicksum += t*(i+1);
			}
			cout<<Quicksum<<endl;	
		}
	}
	return 0;
}
