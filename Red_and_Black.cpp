#include <iostream>
#include <cstring>
using namespace std;

char pic[25][25];
int idx[25][25];
int W,H;
int num;

void dfs(int x,int y)
{
	if(x < 0 || x >= H || y < 0 || y >= W) return;
	if(idx[x][y] > 0 || pic[x][y] == '#') return;
	num++;
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
		num = 0;
		int starti,startj;
		for(i = 0; i < H; i++)
		{
			for(j = 0; j < W; j++)
			{
				cin>>pic[i][j];
				if(pic[i][j] == '@')
				{
					starti = i;
					startj = j;
				}
			}
		}
		memset(idx,0,sizeof(idx));
		dfs(starti,startj);
		cout<<num<<endl;
	}
	return 0;
} 
