#include <iostream>
using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		if(N%2==0)
		{
			cout<<"Even"<<endl;
		}
		else if(N%2 == 1)
		{
			cout<<"Odd"<<endl;
		}
	}
	return 0;
}
