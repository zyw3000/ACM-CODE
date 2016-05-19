#include <iostream>
using namespace std;

class where
{
	public:
		int x,y;
};

int main()
{
	char maze[100][100];
	int N,M,i,j,step;
	where w[2];
	int num;
	cin>>num;
	while(num--)
	{
		step = 0;
		for(i = 0;i < N;i++)
		{
			for(j = 0;j < M;j++)
			{
				cin>>maze[i][j];
				if(maze[i][j] == 'S')
				{
					where[0].x = i;
					where[0].y = j;
				}
				if(maze[i][j] == 'E')
				{
					where[1].x = i;
					where[1].y = j;
				}
			}
			
		}
		
		cout<<step<<endl;
	}
	return 0;
}
