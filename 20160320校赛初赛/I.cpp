#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char num[25][25];
int flag[25][25];
int N,M;

void dfs(int x,int y,int size)
{
	if(x < 0 || x >= N || y < 0 || y >= M) return;
	if(flag[x][y] > 0 || num[x][y] == '1') return;
	flag[x][y] = size;
	for(int dr = -1;dr <= 1; dr++)
	{
		for(int dc = -1;dc <= 1;dc++)
		{
			if(dr != 0 || dc != 0)
			{
				dfs(x+dr,y+dc,size);
			}
		}
	}
}

int main()
{
	while(cin>>N>>M)
	{
		memset(flag,0,sizeof(flag));
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				cin>>num[i][j];
			}
		}
		int size = 0;
		for(int i = 0; i < N;i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(num[i][j] == '0' && flag[i][j] == 0) dfs(i,j,++size);
			}
		}
		switch(size)
		{
			case 1:printf("1\n");break;
			case 5:printf("2\n");break;
			case 3:printf("3\n");break;
			case 2:printf("4\n");break;
			case 7:printf("5\n");break;
			case 4:printf("6\n");break;
			default :break;
		}
	}
	return 0;
}
