#include <iostream>
#include <cstring>
#include <cstdio> 
#include <algorithm>
using namespace std;



int main()
{
	int n,s;
	int time[10005];
	int sum[10005];
	int service[10005];
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		memset(sum,0,sizeof(sum));
		memset(service,0,sizeof(service));
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&time[i]);
		}
		sort(time,time+n);
		int i = 0, j = 0;
		while(i < n)
		{
			service[j] += time[i];
			sum[j] += service[j];
			++j,++i;
			if(j == s) j = 0;
		}
		double t = 0;
		for(i = 0; i < n; i++)
		{
			t += sum[i];
		}
		t /= n;
		printf("%.3lf\n",t);
		
	}
	return 0; 
}
