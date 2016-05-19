#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while(cin>>n)
	{
		int root = (int) sqrt(2*n+0.5);
		int flag = 1;
		for(int i = root; i >= 2; i--)
		{
			if((2*n)%i == 0 && (2*n-i*i+i)%(2*i) == 0)
			{
				cout<<(2*n-i*i+i)/2/i<<endl;
				flag = 0;
			}
		}
		if(flag) cout<<"No Solution"<<endl;
	}
	return 0;
 } 
