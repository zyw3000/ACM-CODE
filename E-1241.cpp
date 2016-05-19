#include <iostream>
using namespace std;

class input
{
	public:
	int num;
	char sex;
};

int main()
{
	int m;
	int n;
	input people[30];
	cin>>m>>n;
	for(int i = 0;i < 2*n;i++)
	{
		cin>>people[i].num>>people[i].sex;
	}
	for(int i = 0;i < n;i++)
	{
		cout<<people[i].num<<people[i].sex;
	}
	return 0;
}
