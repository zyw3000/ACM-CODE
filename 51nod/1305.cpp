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
	int n,a[100005];
	while(scanf("%d",&n)!=EOF)
	{
		int c1 = 0, c2 = 0, other = 0;
		int sum = 0;
		rep(i,n){
			scanf("%d",&a[i]);
			if(a[i] == 1)
				c1++;
			else if(a[i] == 2)
				c2++;
			else other++;
		}
		sum = (c1 * (n-1)) + c2*(c2-1)/2;
		cout<<sum<<endl;
	}
	return 0;
}
