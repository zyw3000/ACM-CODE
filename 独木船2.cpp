#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int p[10005];
	int num,weight;
	while(cin>>num>>weight)
	{
		int ans = 0;
		for(int i = 0; i < num; i++)
			scanf("%d",&p[i]);
		sort(p,p+num);
		int i = 0;
		int j = num - 1;
		while(i < j)
		{
			if(p[i]+p[j] <= weight)
			{
				ans++;
				i++;
				j--;
			}
			if((p[i]+p[j]) > weight)
			{
				j--;
				ans++;
			}
		}
		if(i == j) ans++;
		cout<<ans<<endl;
	}
	return 0;
}
