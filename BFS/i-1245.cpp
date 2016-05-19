#include <iostream>
using namespace std;

typedef struct{
	int x,y;
	int no;
}weizhi;

int main()
{
	char maze[105][105];
	int n,shu,heng;
	weizhi start,end,t;
	cin>>n;
	while(n--)
	{
		cin>>chang>>kuang;
		for(int i = 0;i < shu;i++)
		{
			for(int j = 0;j < heng;j++)
			{
				cin>>maze[i][j];
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
	}
}
