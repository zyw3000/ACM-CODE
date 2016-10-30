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
#define rep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
#define LL long long

int a[505][505];
int dp[505][505];

int main()
{
	int n,ans;
	while(cin>>n){
		ans = 0;
		rep(i,n)
			rep(j,i)
				scanf("%d",&a[i][j]);
		rep(j,n) dp[n][j] = a[n][j];
		for(int i = n-1; i >= 1; i--)
			for(int j = 1; j <= i; j++)
				dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		cout<<dp[1][1]<<endl;
	}
	return 0;
}
