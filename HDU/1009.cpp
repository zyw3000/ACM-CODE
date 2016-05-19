#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct{
	double J;
	double F;
	double INF;
}Room;

int Cmp(Room a, Room b)
{
	return a.INF > b.INF;
}

int main()
{
	int n,m;
	double ans;
	Room r[1005];
	while(cin>>m>>n)
	{
		if(m == -1 && n == -1) break;
		ans = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>r[i].J>>r[i].F;
			r[i].INF = r[i].J / r[i].F;
		}
		sort(r,r+n,Cmp);
		int i = 0;
		double M = m;
		while(M > 0)
		{
			if(i == n) break;    //未注意数据越界问题！！！ 
			if(M >= r[i].F)
			{
				ans += r[i].J;
				M -= r[i].F;
				i++;
			}
			else
			{
				ans += (r[i].J*(M/r[i].F));
				M -= r[i].F;
				i++;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
} 
