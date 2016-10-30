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

typedef struct{
	int s;
	int e;
}XD;

XD x[10005];

int cmp(XD a, XD b)
{
	if(a.e == b.e)
		return a.s > b.s;
	return a.e < b.e;
}

int main()
{
	int n,ans,temp;
	while(scanf("%d",&n)!=EOF)
	{
		rep(i,n)
			scanf("%d%d",&x[i].s,&x[i].e);
		sort(x, x+n, cmp);
		ans = 1;
		temp = x[0].e;
		for(int i = 1; i < n; i++)
		{
			if( temp <= x[i].s)
			{
				ans++;
				temp = x[i].e;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
