#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define inf 0x3f3f3f3f

int dp[2][220][10][220];
int T/*时间*/, HS/*血量*/, A/*攻击*/, R/*血量减少*/, U/*攻击提升*/, D/*燃烧之矛耗血*/, FI/*燃烧之矛BD*FI*/, P/*系数*/;
int des[300];

void change(int &a, int b) 
{
	a = max(a, b);
}

void solve() 
{
	scanf("%d%d%d%d", &T, &HS, &A, &R);
	scanf("%d%d%d%d", &U, &D, &FI, &P);
	forn(i, T)
		scanf("%d", des + i + 1);
	memset(dp,-inf,sizeof(dp));
	int now = 0;
	dp[0][HS][0][0] = 0;
	for (int time = 1; time <= T; ++time) 
	{
		int fang = des[time];
		for (int i = 1; i <= HS; ++i) 
		{
			for (int j = 0; j <= 6; ++j) 
			{
				for (int k = 0; k <= T; ++k) 
				{
					if (dp[now][i][j][k] == -inf)
						continue;
					if (i > D) {
						int add = A + (HS - i) / R * U;
						if (add < fang)
							add = 0;
						else
							add -= fang;
						change(dp[now ^ 1][i - D][6][k + 1], dp[now][i][j][k]
								+ add + FI * k);
					}
					int add = A + (HS - i) / R * U;
					if (add < fang)
						add = 0;
					else
						add -= fang;
					if (j - 1 == 0)
						change(dp[now ^ 1][i][j - 1][0], dp[now][i][j][k] + add
								+ FI * k);
					else if (j)
						change(dp[now ^ 1][i][j - 1][k], dp[now][i][j][k] + add
								+ FI * k);
					else if (j == 0)
						change(dp[now ^ 1][i][j][k], dp[now][i][j][k] + add);
				}
			}
		}
		now = now ^ 1;
	}
	int ans = -inf;
	for(int j = 0; j < 220; j++)
		for(int k = 0; k < 10; k++)
			for(int l = 0; l < 220; l++)
			{
				if (dp[now ][j][k][l] != inf)
					change(ans, dp[now ][j][k][l] - (HS - j) * P);
			}
		cout<<ans<<endl;
}


int main() 
{
	int ex;
	cin>>ex;
	for(int i = 1; i <= ex; i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
