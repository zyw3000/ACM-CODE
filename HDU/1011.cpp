#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int bug[105],brain[105];
int contect[105][105];
int n,m,ans;

int DP(int d,int num,int value)
{
	
	if(d >= n) return value;
	
	num -= (bug[d] / 20 + 1);
	if(num < 0) return value;
	value += brain[d];
	
	int t,max = 0;
	for(int i = 1; i < n; i++)
	{
		if(contect[d][i] == 1)
		{
			t = DP(i,num,value);
			if(t > max) max = t;
		}
	}
	
	if(max != 0) value = max;
	return value;
}


int main()
{
	int father,son;
	while(scanf("%d%d",&n,&m))
	{
		memset(contect,0,sizeof(contect));
		if(n == -1 && m == -1)
			break;
		for(int i = 0; i < n; i ++)
			scanf("%d%d",&bug[i],&brain[i]);
		for(int i = 0; i < n-1; i++)
		{
			scanf("%d%d",&father,&son);
			contect[father-1][son-1] = 1;
		}
		cout<<DP(0,m,0)<<endl;
	}
	return 0;
}
