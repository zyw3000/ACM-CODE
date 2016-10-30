#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define per(i,n,a) for(int i = n; i >= a; i--)
#define clc(a,b) memset(a,b,sizeof(a))
const int INF = 0x3f3f3f3f, MAXN = 11;
int dp[MAXN][10];//dp[i][j]从1~以j开头的i位数中有几个1
int bit[MAXN];

int main()
{
#ifdef SHY
	freopen("d:\\1.txt", "r", stdin);
#endif
	int tmp = 10;
	rep(i,1,10) dp[1][i] = 1;
	repe(i,2,9)
	{
		rep(j,1,10)
		{
			if(j == 1) dp[i][j] = dp[i-1][9]+tmp;
			else dp[i][j] = dp[i][j-1];
			dp[i][j] += dp[i-1][9];
		}
		tmp *= 10;
	}
	int n,cnt = 0;
	scanf("%d", &n);
	tmp = n;
	while(tmp)
	{
		bit[++cnt] = tmp%10;
		tmp /= 10;
	}
	int ans = 0,sum = 0;
	per(i,cnt,1)
	{
		if(bit[i] == 0) continue;
		if(bit[i] == 1) //如果当前位为1需要额外加上他后面所有位数的个数，就是n%pow(10,i-1);
			ans += dp[i-1][9]+1+n%((int)pow(10,i-1));
		else
			ans += dp[i][bit[i]-1];
	}
	printf("%d\n", ans);
	return 0;
}
