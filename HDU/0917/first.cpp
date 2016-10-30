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
const int INF = (1<<30);

int ans,n,lim;
int v[maxn],need[maxn];
int limit[maxn];

void dfs(int cost,int lev,int time){
	if(lev == n){
		if(cost > ans)
			ans = cost;
		return;
	}
	if(cost+limit[lev-1]+v[lev] < ans)
		return;
	if(time+need[lev] <= lim)
		dfs(cost+v[lev],lev+1,time+need[lev]);
	dfs(cost,lev+1,time);
}

int main(){
	int sum;
	while(scanf("%d%d",&n,&lim)!=EOF){
		sum = 0;
		ans = 0;
		rep(i,n){
			scanf("%d%d",need+i,v+i);
			sum += v[i];
		}
		rep(i,n){
			sum -= v[i];
			limit[i] = sum;
		}
		dfs(0,0,0);
		cout<<ans<<endl;
	} 
	return 0;
}

