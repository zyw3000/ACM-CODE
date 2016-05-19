#include <iostream>
#include <cstring>
using namespace std;

char pic[85][1005];
int idx[85][1005];
int W,H;
int Max;
int num;

void dfs(int x,int y)
{
	if(x < 0 || x >= H || y < 0 || y >= W) return;
	if(idx[x][y] > 0 || pic[x][y] != '*') return;
	num++;
	if(num > Max)
	{
		Max = num;
	}
	idx[x][y] = 1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}

int main()
{
	int i,j;
	while(cin>>W>>H && W && H)
	{
		Max = 0;
		for(i = 0;i < H;i++)
		{
			for(j = 0;j < W;j++)
			{
				cin>>pic[i][j];
			}
		}
		memset(idx,0,sizeof(idx));
		for(i = 0;i < H;i++)
		{
			for(j = 0;j < W;j++)
			{
				if(pic[i][j] == '*' && idx[i][j] == 0)
				{
					num = 0;
					dfs(i,j);
				}
			}
		}
		cout<<Max<<endl;
	}
	return 0;
} 
