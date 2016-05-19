#include <iostream>
#include <cstring>
using namespace std;

int data[10005];

int run(int x)
{
	if(x % 4 == 0 && x % 100 != 0) return 1;
	if(x % 400 ==0) return 1;
	return 0;
}

int main()
{
	int W[] = {9,6,5,5,5,5,6};
	int T,t;
	cin>>T;
	memset(data,0,sizeof(data));
	t = 0;
	for(int i = 1928; i < 10000; i++)
	{
		if(run(i)) t = (t+1)%7;
		data[i] = W[t];
		t = (t + 1) % 7;
	}
	while(T--)
	{
		int d;
		cin>>d;
		cout<<data[d]<<endl;
	}
	return 0;
}
