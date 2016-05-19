#include <stdio.h>
#include <math.h>



int main()
{
	long long int n;
	int res[500000];
	double a,b;
	res[0] = 0;
	res[1] = 1;
	for(int i = 2; i < 500000; i++)
	{
		res[i] = (7*res[i-1]+19*res[i-2])%997;
	}
	
	while(scanf("%lld",&n)!=EOF)
	{
		n %= 497004;
		printf("%lld\n",res[n]);
	}
	return 0;
}
