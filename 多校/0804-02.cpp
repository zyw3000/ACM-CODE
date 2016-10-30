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
LL mod = 1e18+5;
LL int n,m;
int r,ans;

LL int max(LL int a, LL int b)
{
	return a>b?a:b;
}

LL int min(LL int a, LL int b)
{
	return a<b?a:b;
}

typedef struct{
	LL int x,y;
}point;

point obs[105];

void find(LL int x,LL int y){
	if(2*min(x,y) < max(x,y)) return;
	if(((n-x)+(m-y))%3 != 0) return;
	if( x > n || y > m) return;
	if(x == n && y == m)
	{
		ans++;
		return;
	}
	int flag1 = 1,flag2 = 1;
	rep(i, r){
		if(x+2 == obs[i].x && y+1 == obs[i].y)
			flag1 = 0;
		if(x+1 == obs[i].x && y+2 == obs[i].y)
			flag2 = 0;
	}
	if(flag1) 
		find(x+2,y+1);
	if(flag2)
		find(x+1,y+2);
}

int main(){
	int idx = 1;
	while(scanf("%lld%lld%d",&n,&m,&r) != EOF){
		rep(i,r)
			scanf("%lld%lld",&obs[i].x,&obs[i].y);
		ans = 0;
		if(((n-1)+(m-1))%3 != 0)
		{
			cout<<"Case #"<<idx++<<": ";
			cout<<0<<endl;
			continue;
		}
		find(1,1);
		cout<<"Case #"<<idx++<<": ";
		cout<<ans<<endl;
	}
	return 0;
} 
