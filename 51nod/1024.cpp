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
#define rep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
#define LL long long

set<double> s;

int main()
{
	int a,b,m,n;
	double t;
	while(scanf("%d%d%d%d",&m,&n,&a,&b)!=EOF)
	{
		for(int i = b; i < b+m; i++)
			for(int j = a; j < a+n; j++){
				t = (double)i * log2(1.0 * j);
				s.insert(t);
			}
		cout<<s.size()<<endl;
	}
	return 0;
}
