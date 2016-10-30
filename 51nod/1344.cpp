#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
#define LL long long 

int main()
{
	int n,data[50005];
	while(cin>>n)
	{
		long long int ans = 0;
		LL int min = 0;
		rep(i,n){
			cin>>data[i];
			ans += data[i];
			if(ans < min)
			{
				min = ans;
			}
		}
		cout<<-min<<endl;
	}
	return 0;
}
