#include <iostream>
#include <cstring>
#define MAX 105
using namespace std;

int data[MAX][MAX][MAX];

int isState1(int x,int y,int z)
{
	if(z == 1) return 0;
	if(data[x+1][y][z] == 1) return 0;
	if(data[x][y+1][z] == 1) return 0;
	if(data[x][y][z+1] == 1) return 0;
	if(data[x-1][y][z] == 1) return 0;
	if(data[x][y-1][z] == 1) return 0;
	if(data[x][y][z-1] == 1) return 0;
	return 1;
}

int isState2(int x,int y,int z)
{
	if(z == 1)
	{
		if(data[x+1][y][z] == 1 && data[x][y+1][z] == 1 && data[x][y][z+1] == 1 && data[x-1][y][z] == 1 && data[x][y-1][z] == 1) return 1;
	}
	else if(data[x+1][y][z] == 1 && data[x][y+1][z] == 1 && data[x][y][z+1] == 1 && data[x-1][y][z] == 1 && data[x][y-1][z] == 1 && data[x][y][z-1] == 1) return 1;
	return 0;
}

int main()
{
	int T,n,x,y,z,flag;
	cin>>T;
	while(T--)
	{
		memset(data,0,sizeof(data));
		cin>>n;
		flag = 1;
		for(int i = 0; i < n; i++)
		{
			cin>>x>>y>>z;
			data[x][y][z] = 1;
			if(isState1(x,y,z) || isState2(x,y,z))
			{
				flag = 0;
				break;
			}
		}
		if(flag == 0)
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}
