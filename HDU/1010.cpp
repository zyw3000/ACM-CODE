#include <iostream>
#include <cstring> 
#include <cmath>
#include <cstdio> 
using namespace std;

char maze[10][10];
int flag[10][10];
int n,m,t,ans;
int begini,beginj,endi,endj;

void DFS(int x,int y,int step)
{
	if(ans) return; 
	//ÆæÅ¼¼ôÖ¦ 
	int temp = abs(x - endi)+abs(y - endj);
	if((temp+(t - step))%2 != 0 ) return ;
	
	
	if(x >= n || x < 0) return ;
	if(y >= m || y < 0) return ;
	if(step > t) return ;
	if(maze[x][y] == 'X') return ;
	if(step == t && maze[x][y] == 'D')
	{
		ans = 1;
		return ;
	}
	flag[x][y] = 1;
	if(flag[x+1][y] == 0) DFS(x+1,y,step+1);
	if(ans) return; 
	if(flag[x-1][y] == 0) DFS(x-1,y,step+1);
	if(ans) return; 
	if(flag[x][y+1] == 0) DFS(x,y+1,step+1);
	if(ans) return; 
	if(flag[x][y-1] == 0) DFS(x,y-1,step+1);
	if(ans) return; 
	flag[x][y] = 0;
}

int main()
{
	while(cin>>n>>m>>t)
	{
		if(n == 0 && m == 0 && t == 0) break;
		ans = 0;
		memset(flag,0,sizeof(flag));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin>>maze[i][j];
				if(maze[i][j] == 'S')
				{
					begini = i;
					beginj = j;
				}
				if(maze[i][j] == 'D')
				{
					endi = i;
					endj = j;
				}
			}
		}
		
		DFS(begini,beginj,0);
		if((abs(begini - endi)+abs(beginj-endj)+t)%2 != 0)
		{
			cout<<"NO"<<endl;
			continue;
		} 
		if(ans == 1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
