#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
	int N,n,m;
	cin>>N;
	float result;
	while(N!=0)
	{
		cin>>n>>m;
		if(n==0)
		{
			continue;
		}
		result = 1;
		while(--m)
		{
			result = result*(n-1)/n;
			n--;
		}
		result = result/n;
		if(N==1)
		{
			cout<<fixed<<setprecision(2)<<result;
			break;
		}
		cout<<fixed<<setprecision(2)<<result<<endl;
		N--;
	}
	return 0;
}
