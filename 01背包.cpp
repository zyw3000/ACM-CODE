#include <iostream>
using namespace std;
#define NUM 50
#define CAP 1500
int w[NUM];
int v[NUM];
int dp[NUM][CAP];
int W,N;

void dp()
{
	
	for(int i = W; i >= 0; i--)
	{
		for(int j = N; j >= 0; j--)
		{
			
		}
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(dp, 0, sizeof(dp));
		cin>>N;
		for(int i = 0; i < n; i++)
		{
			cin>>w[i]>>v[i];
		}
		dp();
		cout<<<<endl;
	}
	return 0;
}
