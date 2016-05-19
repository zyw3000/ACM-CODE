#include <iostream>
using namespace std;

int main()
{
	int N;
	while(cin>>N && N)
	{
		int x1,x2,sum = 0;
		cin>>x1;
		sum = x1*6+5;
		for(int i = 2; i <= N; i++)
		{
			cin>>x2;
			if(x2>x1) sum += (x2-x1)*6+5;
			else sum += (x1-x2)*4+5;
			x1 = x2;
		}
		cout<<sum<<endl;
	}
	return 0;
} 
