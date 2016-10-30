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
#define rep(i,n) for(int i = 2; i <= n; i++)
using namespace std;
#define LL long long

int main()
{
	int n,ans;
	while(cin>>n)
	{
		int t;
		ans = n/5;
		t = ans;
		while(t)
		{
			ans += t/5;
			t /= 5;
		}
		cout<<ans<<endl;
	}
	return 0;
}
