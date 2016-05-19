#include <iostream>
#include <cstring>
using namespace std;

int Prime(int n)
{
	for(int i = 2; i < n; i++)
	{
		if(n % i == 0) return 0;
	}
	return 1;
}

int flag[1000005];
int primelist[1000005];

int main()
{
	int n,count;
	while(cin>>n)
	{
		memset(flag,0,sizeof(flag));
		count = 0;
		for(int i = 2; i <= n; i++)
		{
			if(Prime(i))
			{
				primelist[count++] = i;
			}
			for(int j = 1; j <= count; j++)
			{
				if(i * primelist[j] > n) break;
				flag[i * primelist[j]] = 1;
				if( i % primelist[j]) break;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
