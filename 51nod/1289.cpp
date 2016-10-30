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
	int w;
	int fx;
}Fish;

int main()
{
	Fish f[100005];
	int eat[100005];
	int n,j,ans;
	while(cin>>n)
	{
		ans = 0;
		memset(eat,0,sizeof(eat));
		rep(i,n){
			cin>>f[i].w>>f[i].fx;
			if(f[i].fx == 0)
				f[i].fx = -1;
		}
		rep(i,n){
			if(eat[i] == 1) continue;
			j = i;
			j += f[i].fx;
			while(j >= 0 && j < n)
			{
				if(eat[j] == 1){
					j += f[i].fx;
					continue;
				}
				if(f[i].w > f[j].w)
				{
					if(f[i].fx == f[j].fx)
						break;
					else{
						eat[j] = 1;
						j += f[i].fx;
					}
				}
				else
				{
					if(f[i].fx == f[j].fx)
						break;
					else{
						eat[i] = 1;
						break;
					}
				}
			}
		}
		rep(i,n){
			if(eat[i] == 0)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
