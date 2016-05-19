#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[105];
	int n,i,length;
	int t = 0,temp;
	memset(a,0,105);
	while(cin>>a>>n)
	{
		length = strlen(a);
		cout<<length<<endl;
		cout<<a<<endl;
		memset(a,0,105);
	}
}
