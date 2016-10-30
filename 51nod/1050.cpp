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
const int INF = -(1<<30);

int num[maxn];

int main()
{
	int n;
	LL max,min,sum,t1,t2,ans;
	while(scanf("%d",&n)!=EOF)
	{
		sum = 0;
		t1 = 0;
		t2 = 0;
		max = INF;
		min = -INF;
		rep(i,n){
			scanf("%d",num+i);
			sum += num[i];
		}
		rep(i,n){
			t1 += num[i];
			t2 += num[i];
			if(t1 < num[i])
				t1 = num[i];
			if(t2 > num[i])
				t2 = num[i];
			if(t1 > max)
				max = t1;
			if(t2 < min)
				min = t2;
		}
		min = sum - min;
		if(max > min)
			ans = max;
		else ans = min;
		cout<<ans<<endl;
	}
	return 0;
}
