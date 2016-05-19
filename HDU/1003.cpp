#include <iostream>
using namespace std;

int main()
{
	int N[100005];
	int T,low,high,sum,n,times = 1;
	int flag = 1;
	cin>>T;
	for(int k = 1; k <= T; k++)
	{
		if(k != 1)
		{
			cout<<endl;
		 } 
		cin>>n;
		for(int i = 0; i < n; i++)
		{
			cin>>N[i];
		}
		int b = 0;
		int sum = N[0];   //妈的逼，最关键的一点，SUM一定要给初值，若输入的数组的值全为负，sum初值为0的话，最大值产生偏差，WRONG ANSWER 
		int begin = 0;
		low = 0;
		high = 0;
		for(int i = 0; i < n; i++)
		{
			if(b >= 0) b+=N[i];
			else
			{
				b = N[i];
				begin = i;
			}
			if(b > sum)
			{
				sum = b;
				low = begin;
				high = i;
			}
		}
		cout<<"Case "<<times++<<":"<<endl;
		cout<<sum<<" "<<low+1<<" "<<high+1<<endl;
		
		
	}
	return 0; 
 } 
