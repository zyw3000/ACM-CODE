#include <iostream> 
using namespace std;

int main()
{
	int num = 1;
	int test[45000];
	test[0] = 3;
	int j = 0;
	int N;
	for(int i = 3; i < 45000; i++)
	{
		test[j+1] = test[j] + i;
		j++;
	}
	while(cin>>N)
	{
		int flag = 1;
		
		int i;
		for(i = 0; i < 45000; i++)
		{
			if(N < test[i])
			{
				i += 2;
				break;
			}
		}
		
		
		int TMD;
		for(; i > 1; i--)
		{
			if( i%2 == 0) TMD = N/i - (i/2)+1;
			else TMD = N/i - i/2;
			int sum = TMD;
			int t = TMD;
			for(int j = 2; j <= i; j++)
			{
				t += 1;
				sum = sum+t;
				if(sum == N) break; 
				else if(sum > N) break;
			}
			if(sum == N)
			{
				cout<<TMD<<endl;
				flag = 0;
			}
		}
		
		
		
		if(flag)
		{
			cout<<"No Solution"<<endl;
		}
		
	}
	return 0; 
}
