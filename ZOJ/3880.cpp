#include <iostream>
using namespace std;

int main()
{
	int T,n;
	int data;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>data;
			if(data>6000) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
