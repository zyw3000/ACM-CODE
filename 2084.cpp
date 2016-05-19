#include <iostream>
#include <cstring>
using namespace std;

int N,data[105][105],d[105][105]; 

int max(int a,int b)
{
	return a>b?a:b;
}

/*       µÝ¹éDP·½·¨ 
int dp(int i, int j)
{
	if(d[i][j]>=0) return d[i][j];
	if( i == N-1 ) return data[i][j];
	return d[i][j] = data[i][j]+max(dp(i+1,j),dp(i+1,j+1)); 
}
*/

int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		memset(data,0,sizeof(data));
		memset(d,-1,sizeof(d));
		cin>>N;
		for(int  i = 0; i < N; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				cin>>data[i][j];
			}
		}
	}
	return 0;
} 
