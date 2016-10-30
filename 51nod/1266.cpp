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

int Min(int a, int b)
{
	return a>b?b:a;
}

int Max(int a, int b)
{
	return a>b?a:b;
}

int main()
{
	int n,l;
	int pot[50005];
	while(cin>>n>>l)
	{
		int min = 0, max = 0;
		rep(i,n)
			scanf("%d",&pot[i]);
		rep(i,n)
		{
			if(min < Min(l-pot[i],pot[i]))
				min = Min(l-pot[i],pot[i]);
			if(max < Max(l-pot[i],pot[i]))
				max = Max(l-pot[i],pot[i]);
		}
		cout<<min<<" "<<max<<endl;
	}
	return 0;
}
