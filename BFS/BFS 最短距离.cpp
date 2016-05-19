#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

typedef struct{
	int x,y;
	int no;
}weizhi;

char maze[6][5] = {
	{'S','0','1','0','0'},
	{'0','1','0','0','0'},
	{'0','1','0','1','1'},
	{'0','1','0','0','E'},
	{'0','0','0','1','0'},
	{'0','0','0','0','0'}
};

weizhi NSWE[4]  = {
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int result[6][5];

int main()
{
	weizhi start,end,t;
	int flag = 0;
	int id = 0;
	queue<weizhi> q;
	memset(result,0,sizeof(result));
	for(int i = 0;i<6;i++)
	{
		for(int j = 0;j<5;j++)
		{
			if(maze[i][j] == 'S')
			{
				start.x = i;
				start.y = j;
				start.no = 0;
			}
			if(maze[i][j] == 'E')
			{
				end.x = i;
				end.y = j;
			}
		}
	}
	q.push(start);
	while(!q.empty())
	{
		t = q.front();
		q.pop();
		id = t.no+1;
		int k = 0;
		while(k<4)
		{
			
			if((t.x+NSWE[k].x)>=6 || (t.x+NSWE[k].x) < 0)
			{
				k++;
				continue;
			}                                                                   //超过边界的情况 
			if(t.y+NSWE[k].y >=5 || t.y+NSWE[k].y < 0)
			{
				k++;
				continue;
			}                                                                    //超过边界的情况 
			if(maze[t.x + NSWE[k].x][t.y + NSWE[k].y] == 'E')
			{
				result[t.x + NSWE[k].x][t.y + NSWE[k].y] = id;
				end.no = t.no + 1;
				flag = 1;
				break;
			}       
			
			else if( maze[t.x + NSWE[k].x][t.y + NSWE[k].y] != '1' && result[t.x + NSWE[k].x][t.y + NSWE[k].y] == 0)
			{
				weizhi temp = {t.x+NSWE[k].x,t.y+NSWE[k].y,t.no+1};
				q.push(temp);
				result[t.x + NSWE[k].x][t.y + NSWE[k].y] = id;
			}
			k++;
		}
		if(flag)
		{
			break;
		}
	}
	cout<<end.no<<endl;
	cout<<result[end.x][end.y]<<endl;
	return 0;
} 
