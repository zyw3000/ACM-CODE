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
#define maxn 1000005

int data[maxn];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int ans = 0;
		rep(i,n)
			scanf("%d",&data[i]);
		int t = 0;
		for(int i = n-1; i>=0; i--)
		{
			t += data[i];
			if(t >= 0)
			{
				t = 0;
				ans++;
			}
			else
			{
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
