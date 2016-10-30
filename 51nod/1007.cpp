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

int num[10005];
int dp[10005];

int max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int n,lim,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		rep(i,n){
			scanf("%d",&num[i]);
			sum += num[i];
		}
		lim = sum/2;
		rep(i,n)
			for(int j = lim; j >= num[i]; j--)
				dp[j] = max(dp[j],dp[j - num[i]] + num[i]);
		sum -= dp[lim];
		cout<<fabs(sum-dp[lim])<<endl;
	}
	return 0;
}
