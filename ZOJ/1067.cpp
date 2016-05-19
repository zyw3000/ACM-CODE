#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double value(int r1, int r2, int g1, int g2, int b1, int b2)
{
	return sqrt(pow(abs(r1-r2),2)+pow(abs(g1-g2),2)+pow(abs(b1-b2),2));
}

int main()
{
	int color[16][3];
	int R,G,B,ans,count = 0;
	double result,t;
	while(scanf("%d %d %d",&R,&G,&B))
	{
		if(R == -1 && B == -1 && G == -1) break;
		if(count < 16)
		{
			color[count][0] = R;
			color[count][1] = G;
			color[count][2] = B;
			count++;
			continue;
		}
		
		result = 0;
		t = 0;
		for(int i = 0; i < 16; i++)
		{
			t = value(R,color[i][0],G,color[i][1],B,color[i][2]);
			if(i == 0)
			{
				result = t;
				ans = i;
				continue;
			}
			if(result > t)
			{
				result = t;
				ans = i;
			}
		}
		cout<<"("<<R<<","<<G<<","<<B<<")";
		cout<<" maps to ";
		cout<<"("<<color[ans][0]<<","<<color[ans][1]<<","<<color[ans][2]<<")"<<endl;
	}
	return 0;
} 
