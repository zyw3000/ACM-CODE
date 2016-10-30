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
const int maxn = 105;

int w[maxn];
int p[maxn];
int dp[maxn][10005];

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int n,wit;
	while(scanf("%d%d",&n,&wit)!=EOF)
	{
		rep(i,n)
			scanf("%d%d",&w[i+1],&p[i+1]);
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= wit; j++){
				if(j < w[i]){
					dp[i][j] = dp[i-1][j];
				}
				else
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+p[i]);
			}
		cout<<dp[n][wit]<<endl;
	}
	return 0;
}
