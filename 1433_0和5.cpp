#include <iostream>
using namespace std;

int main()
{
	int n;
	char num;
	int countF;
	int countZ; 
	while(cin>>n)
	{
		//input
		countF = 0;
		countZ = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>num;
			if(num == '5') countF++;
			if(num == '0') countZ++;
		}
		//
		if(countF > 0 && countZ == 0)
		{
			cout<<-1<<endl;
			continue;
		}
		if(countF < 9 && countZ > 0)
		{
			cout<<0<<endl;
			continue;
		}
		//
		int times = countF/9;
		for(int i = 1; i <= times; i++)
		{
			for(int j = 1; j <= 9; j++)
				cout<<5;
		}
		for(int i = 1; i <= countZ; i++)
		{
			cout<<0;
		}
		cout<<endl;
	}
	return 0;
}
