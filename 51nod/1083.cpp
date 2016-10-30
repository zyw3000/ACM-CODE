#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
#define LL long long

int a[505][505];
int dp[505][505];

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int n,ans;
	while(cin>>n){
		memset(dp,0,sizeof(dp));
		ans = 0;
		rep(i,n)
			rep(j,n)
				scanf("%d",&a[i][j]);
		for(int i = n-1; i >= 0; i--)
		{
			for(int j = n-1; j >= 0; j--)
			{
				if(i == n-1 && j == n-1){
					dp[i][j] = a[i][j];
					continue;
				}
				dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i][j+1]);
			}
		}
			
		cout<<dp[0][0]<<endl;
	}
	return 0;
}
