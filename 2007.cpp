#include <iostream>
using namespace std;

int main()
{
	int a,b;
	int i;
	int ping,li;
	int g=0;
	do
	{
		if(g == 0)
		{
			g=1;
			continue;
		}
		else 
		{
			cout<<endl;
		}
		ping=0;
		li=0;
		for(i=a;i<=b;i++)
		{
			if((i%2) == 0)
			{
				ping += i*i;
			}
			else if((i%2) == 1)
			{
				li += i*i*i;
			}
		}
		cout<<ping<<" "<<li;
	}
	while( cin>>a>>b );
	return 0;
} 
