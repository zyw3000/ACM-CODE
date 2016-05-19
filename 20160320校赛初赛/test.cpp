#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;



int main()
{
	int n;
	int res[500000];
	res[0] = 0;
	res[1] = 1;
	for(int i = 2; i <497004; i++)
	{
		res[i] = (7*res[i-1]+19*res[i-2]) % 997;
		cout<<res[i]%997<<endl;
	}
	return 0;
}
