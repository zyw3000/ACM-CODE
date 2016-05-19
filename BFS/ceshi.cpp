#include <iostream>
using namespace std;

typedef struct{
	int x,y;
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

int main()
{
	weizhi a = {1,1};
	a.x = a.x + NSWE[1].x;
	cout<<a.x<<" "<<a.y<<endl;
	return 0;
}
