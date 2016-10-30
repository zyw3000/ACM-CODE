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

int lim[50005];
int dish[50005];

int min(int a, int b)
{
	return a>b?b:a;
}

int main()
{
	int n,m,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans = 0;
		lim[n] = 1e9+100;
		rep(i,n){
			scanf("%d",&lim[n-i-1]);
			lim[n-i-1] = min(lim[n-i-1],lim[n-i]);
		}
		rep(i,m)
			scanf("%d",&dish[i]);
		int tp = 0,temp;
		rep(i,m){
			temp = lower_bound(lim+tp, lim+n, dish[i])-lim;//const
			if(temp == n)
				break;
			tp = temp+1;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
