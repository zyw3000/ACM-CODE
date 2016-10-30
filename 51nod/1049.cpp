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
const int maxn = 50005;
const int INF = -1e9-100;

int num[maxn];

int main()
{
	int n;
	LL ans,t;
	while(scanf("%d",&n)!=EOF)
	{
		t = 0;
		ans = INF;
		rep(i,n)
			scanf("%d",&num[i]);
		rep(i,n){
			t += num[i];
			if(t <= num[i])
				t = num[i];
			if(t > ans)
				ans = t;
		}
		cout<<ans<<endl;
	}
	return 0;
}
