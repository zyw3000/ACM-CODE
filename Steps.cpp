#include <iostream>
using namespace std;

int dijian(int x)
{
	int result = 0;
	while(x>=1)
	{
		result += x--;
	}
	return result;
}

int main()
{
	int n;
	int x,y;
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		int t = y-x-1;
		int length = 1;
		int steps = 1;
		while(t)
		{
			if(t >= dijian(length+1))
			{
				steps++;
				length++;
				t -= length;
			}
			else 
			{
				if(t >= dijian(length))
				{
					steps++;
					t -= length;
				}
				else
				{
					steps++;
					length--;
					t -= length;
				}
			}
		}
		cout<<steps<<endl;
	}
	return 0; 
}
 
