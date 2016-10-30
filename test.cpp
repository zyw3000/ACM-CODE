#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double s;
	double res;
	while(cin>>s)
	{
		res = sqrt(s*s*s/8/acos(-1))/3;
		printf("%lf\n",res);
	}
	return 0;
}
