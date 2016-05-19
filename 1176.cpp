/*
	馅饼题目 动态规划！！！ 
*/

#include <iostream>
#include <cstring>
using namespace std;

int maxTime,ans;
int pie[100005][15];
int dp[100005][15];

int max(int a,int b)
{
	return a>b?a:b;
}

void seek()
{
	for(int i = maxTime; i >= 0; i--)
	{
		for(int j = 1; j < 12; j++)
		{
			dp[i][j] = max(max(dp[i+1][j],dp[i+1][j-1]),dp[i+1][j+1]) + pie[i][j];
		}
	}
	ans = dp[0][6];
}



int main()
{
	int n,x,T;
	while(cin>>n && n)
	{
		maxTime = 0;
		memset(pie,0,sizeof(pie));
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < n; i++)
		{
			cin>>x>>T;
			if(T>maxTime) maxTime = T;
			++pie[T][x+1];
		}
		seek();
		cout<<ans<<endl;
	}
	return 0;
} 
