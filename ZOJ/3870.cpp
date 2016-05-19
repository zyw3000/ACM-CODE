//“ÏªÚ‘ÀÀ„ 

#include <iostream>
#include <cstring>
using namespace std;


int n,data[100005];
int bit[50];

void solve(int x)
{
	int l = 31;
	while(l>=0)
	{
		if(x & (1<<l))
		{
			bit[l]++;
			return;
		}
		l--;
	}
	return ;
}

int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		int ans = 0;
		memset(bit,0,sizeof(bit));
		cin>>n;
		for(int i = 0; i < n; i ++)
		{
			cin>>data[i];
			solve(data[i]);
		}
		for(int i = 0; i < n; i++)
		{
			int l = 31;
			while(l >= 0)
			{
				if(data[i] & (1<<l)) break;
				l--;
			}
			while(l>=0)
			{
				if(!(data[i] & (1<<l)))	ans += bit[l];
				l--;
			}
		 }
		cout<<ans<<endl;
	}
	return 0;
}
