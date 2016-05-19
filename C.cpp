#include <iostream>
using namespace std;

int main()
{
	char c;
	int d;
	int i,j;
	while(cin>>c>>d)
	{
		for(i = 1;i<=d/2;i++)
		{
			for(int j=1;j<=d+2*(i-1);j++)
			{
				cout<<c;
			}
			cout<<endl;
		}
		for(i=1;i<=d/2;i++)
		{
			for(j=1;j<=2*d;j++)
			{
				cout<<c;
			}
			cout<<endl;
		}
		for(i=1;i<=d/2;i++)
		{
			for(j=1;j<=d;j++)
			{
				cout<<c;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
