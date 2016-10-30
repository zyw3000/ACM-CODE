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
const int maxn = 20;
const int INF = (1<<30);

int dp[maxn][10];
int ans;
int lc[maxn],rc[maxn];

void init(){
	for(int i = 1; i <20; i++){
		for(int j = 0; j < 10; j++){
			if(i == 1){
				if(j % 2==0)
					dp[i][j] = dp[i][j-1]+1;
				else dp[i][j] = dp[i][j-1];
			}
			else if(j == 0)
				dp[i][j] = dp[i-1][9];
			else if((i%2) + (j%2) == 1){
				
			}
			else 
				dp[i][j] = 
		}
	}
}

int solve(int l, int r){
	int cnt = 0;
	while(l){
		lc[cnt++] = l % 10;
		l /= 10;
	}
	cnt = 0;
	while(r){
		rc[cnt++] = r % 10;
		r /= 10;
	}
}

int main(){
	int t,l,r;
	memset(dp,0,sizeof(dp));
	init();
	rep(i,20){
		rep(j,10){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cin>>t;
	while(t--){
		scanf("%d%d",&l,&r);
		cout<<solve(l,r)<<endl;
	}
	return 0;
}

