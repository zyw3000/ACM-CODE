#include <iostream>
#include <cstring>
using namespace std;

char pic[85][1005];
int idx[85][1005];
int W,H;

void dfs(int x,int y,int id)
{
	if(x < 0 || x >= W || y < 0 || y >= H) return;
	if(idx[x][y] > 0 || pic[x][y] != '*') return;
	idx[x][y] = id;
	for(int dr = -1;dr <= 1; dr++)
	{
		for(int dc = -1;dc <= 1;dc++)
		{
			if(dr != 0 || dc != 0)
			{
				dfs(x+dr,y+dc,id);
			}
		}
	}
}

int main()
{
	int i,j;
	int cnt = 0;
	while(cin>>W>>H && W && H)
	{
		cnt = 0;
		for(i = 0;i < W;i++)
		{
			for(j = 0;j < H;j++)
			{
				cin>>pic[i][j];
			}
		}
		memset(idx,0,sizeof(idx));
		for(i = 0;i < W;i++)
		{
			for(j = 0;j < H;j++)
			{
				if(pic[i][j] == '*' && idx[i][j] == 0)
				{
					dfs(i,j,++cnt);
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
