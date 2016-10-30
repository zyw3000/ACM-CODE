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
const int maxn = 12;
const int INF = (1<<30);

int life[maxn];
int n,a,b,min;
int fcost;

bool isover()
{
	rep(i,n)
		if(life[i] >= 0)
			return true;
	return false;;
}

void init(){
	int cs;
	cs = list[0]/b;
	cs++;
	fcost+=cs;
	life[0] -= cs*b;
	life[1] -= cs*a;
	life[2] -= cs*b;
	if(life[n-1] < 0)
		return;
	else{
		cs = list[n-1]/b;
		cs++;
		fcost += cs;
		life[n-1] -= cs*b;
		life[n-2] -= cs*a;
		life[n-3] -= cs*b;
	}
}

int dfs(int x, int ans){
	if(ans > min) return;
	if(isover){
		if(ans < min)
			min = ans;
		return;
	}
	for(int i = 1; i < n-1; i++)
	{
		if(life[i] >= 0){
			
		}
	}
}

int main()
{
	while(cin>>n>>a>>b)
	{
		fcost = 0;
		init();
		min = INF;
		rep(i,n)
			scanf("%d",life+i);
		dfs();
		cout<<min<<endl;
	}
	return 0;
}
