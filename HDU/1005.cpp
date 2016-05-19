#include <iostream>
#include <cstdio>
using namespace std;

int f[100000005];

int main()
{
	int A,B,n,size;
	f[1] = 1;
	f[2] = 1;
	while(cin>>A>>B>>n)
	{
		size = 0;
		if(A == 0 && B == 0 && n == 0) break;
		if(n==1 || n==2)
		{
			cout<<1<<endl;
			continue; 
		} 
		
		int i,j;
		for(i = 3; i <= n; i++)
		{
			f[i] = (A*f[i-1]+B*f[i-2])%7;
			for(j = 2; j < i; j++)
			{
				if(f[i] == f[j] && f[i-1] == f[j-1])
				{
					size = i - j;
					break;
				}
			}
			if(size) break;
		}
		if(size > 0)
		{
			f[n] = f[(n-j)%size+j];
        }
		cout<<f[n]<<endl;
	}
	return 0;
}
