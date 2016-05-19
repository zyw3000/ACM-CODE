#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<long long int,int> m;
	int n;
	long long out1,out2,mid;
	long long int t;
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>t;
			m[t]++;
		}
		int flag = 0;
		map<long long int,int>::iterator point;
		for(point = m.begin();point!=m.end();point++)
		{
			if((point->second)%2 == 1 && flag)
			{
				out2 = point->first;
				break;
			}
			if((point->second)%2 == 1)
			{
				out1 = point->first;
				flag = 1;
			}
		}
		
		if(out1>out2)
		{
			mid = out1;
			out1 = out2;
			out2 = mid;
		}
		cout<<out1<<" "<<out2<<endl;
	}
	return 0;
}
