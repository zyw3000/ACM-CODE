#include <iostream>
using namespace std;

int main()
{
	int n;
	int max;
	while(cin>>n)
	{
		max = 0;
		while(n)
		{
			if(max < (n%10) ) max = n%10;
			n /=10; 
		}
		cout<<max<<endl;
	}
	return 0;
}
