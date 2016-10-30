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
const LL maxn = 1e18+100;
const int MAX = 70*70*70;

LL num[MAX];

LL cnt = 0;

void init()
{
	cnt = 0;
	for(LL i = 1; i < maxn; i *= 2)
		for(LL j = 1; j*i < maxn; j *= 3)
			for(LL k = 1; j*i*k < maxn; k *= 5)
				num[cnt++] = i*j*k;
}

int main()
{
	int t;
	LL q;
	init();
	sort(num, num+cnt);
	while(scanf("%d",&t)!=EOF)
	{
		while(t--){
			scanf("%lld",&q);
			LL temp = lower_bound(num+1, num+cnt+1, q)-num;
			cout<<num[temp]<<endl;
		}
	}
	return 0;
}
