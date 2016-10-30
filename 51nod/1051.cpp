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
#define rep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
#define LL long long
const int maxn = 505;
const int INF = -(1<<30);

int num[maxn][maxn];

int main()
{
	int m,n,data,sum,ans;
	while(cin>>m>>n)
	{
		ans = INF;
		rep(i,n){
			rep(j,m){
				scanf("%d",&data);
				num[i][j] = num[i-1][j]+data;
			}
		}
		for(int i = 1; i < n; i++){
			for(int j = i; j <= n; j++){
				sum = 0;
				for(int k = 1; k <= m; k++){
					sum += (num[j][k] - num[i-1][k]);
					if(sum < num[j][k]-num[i-1][k])
						sum = num[j][k]-num[i-1][k];
					if(sum > ans)
						ans = sum;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
