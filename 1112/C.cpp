#include <iostream>
using namespace std;

int main()
{
	int a[1050];
	int n,k;
	int t,i,j;
	while(cin>>n>>k)
	{
		int flag = 0;
		for(i = 0;i<n;i++)
		{
			cin>>a[i];
		}
		for(i = 0;i<=n-3;i++)
		{
			t = 0;
			for(j = i;j<=i+2;j++)
			{
				t += a[j];
			}
			if(t == k)
			{
				cout<<"YES"<<endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
