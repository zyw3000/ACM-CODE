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
int maxn = 2010;

int main()
{
	int t,n,m;
	int a[maxn],b[maxn];
	int c[maxn],vis[maxn];
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		rep(i,n)
			cin>>a[i];
		rep(i,n)
			cin>>b[i];
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		rep(i,n)
		{
			rep(j,n)
			{
				if(a[i] == b[j] && vis[j] == 0)
				{
					c[i] = j+1;
					vis[j] = 1;
					break;
				}
			}
		}
		rep(i,m)
		{
			int star,last;
			cin>>star>>last;
			star--;
			sort(c+star,c+last);
		}
		int flag = 1;
		rep(i,n-1)
			if(c[i] > c[i+1] || c[i] == 0)
			{
				cout<<"No"<<endl;
				flag = 0;
				break;
			}
		if(flag)
			cout<<"Yes"<<endl;
	}
	return 0;
}
