#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N,data[1005];
	cin>>N;
	while(N--)
	{
		int n,t;
		cin>>n;
		memset(data,0,sizeof(data));
		for(int i = 0; i < n; i++)
		{
			cin>>t;
			data[t]++;
		}
		int max1 = 0, max2 = 0;
		for(int i = 1; i <= 1000; i++)
		{
			if(data[max1] < data[i])
			{
				max1 = i;
				continue;
			 } 
			if(data[max1] == data[i]) max2 = i;
		}
		if(data[max1] == data[max2]) cout<<"Nobody"<<endl;
		else cout<<max1<<endl;
	}
	return 0;
} 
