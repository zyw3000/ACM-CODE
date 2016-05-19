#include <iostream>
#include <cstring>
using namespace std;

int f[25][25][105];
int dp[25][25][105];
int ans;
int maxTime;

int Max(int a,int b,int c,int d,int e)
{
	if(a < b) a = b;
	if(a < c) a = c;
	if(a < d) a = d;
	if(a < e) a = e;
	return a;
}

void seek()
{
	for(int k = maxTime; k >=0; k--)
	{
		for(int i = 1; i < 21; i++)
		{
			for(int j = 1; j < 21; j++)
			{
				dp[i][j][k] = Max(dp[i][j][k+1],dp[i+1][j][k+1],dp[i-1][j][k+1],dp[i][j+1][k+1],dp[i][j-1][k+1]) + f[i][j][k];
				if(ans < dp[i][j][k]) ans = dp[i][j][k];
			}
		}
	}
	
}

int main()
{
	int n,m;
	cin>>n; 
	while(n--)
	{
		int x,y,T;
		ans = 0;
		maxTime = 0;
		memset(f,0,sizeof(f));
		memset(dp,0,sizeof(dp));
		cin>>m;
		for(int i = 0; i < m; i++)
		{
			cin>>T>>x>>y;
			if(T > maxTime) maxTime = T;
			++f[x][y][T];
		}
		seek();
		cout<<ans<<endl;
	}
	return 0;
}
