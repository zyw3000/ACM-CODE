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
#define rep(i,n) for(int i = 1; i < n; i++)
using namespace std;
#define LL long long
const int maxn = 1e5+5;
const int INF = (1<<30);

int num[maxn];
int ans[maxn];

void init(){
	int max = 1;
	num[0] = 0;
	num[1] = 1;
	ans[0] = 0;
	ans[1] = 1;
	rep(i,maxn/2){
		num[2*i] = num[i];
//		if(num[2*i] > max)
//			max = ans[2*i];
		ans[2*i] = max;
		num[2*i+1] = num[i]+num[i+1];
		if(num[2*i+1] > max)
			max = num[2*i+1];
		ans[2*i+1] = max;
	}
	return;
}

int main()
{
	init();
	int t,n;
//	for(int i = 0; i < maxn; i++)
//		cout<<ans[i]<<" ";
	cin>>t;
	while(t--){
		scanf("%d",&n);
		cout<<ans[n]<<endl;
	}
	return 0;
}
