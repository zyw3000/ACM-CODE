#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,sum;
int connect[15][15];
int color[15];

bool Same(int t)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(connect[t][i] == 1 && (color[i] == color[t])) return false;
	}
	return true;
}

void Ans(int t)
{
	int i;
	if(t > n)
	{
		sum++;
		for(i = 1; i <= n; i++)
		{
			cout<<color[i]<<" ";
			
		} 
		cout<<endl;
		return ;
	}
	for(i = 1; i <= m; i++)
	{
		color[t] = i;
		if(Same(t)) Ans(t+1);
		color[t] = 0;
	}
}

int main()
{
	int x,y;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(connect, 0, sizeof(connect));
		memset(connect, 0, sizeof(color));
		sum = 0;
		while(scanf("%d%d",&x,&y))
		{
			if(x == 0 && y == 0) break;
			connect[x][y] = 1;
			connect[y][x] = 1;
		}
		Ans(1);
		cout<<sum<<endl;
	}
	return 0;
}
