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

typedef struct{
	int s;
	int e;
}XD;

XD data[50005];

int cmp(XD a, XD b)
{
	if(a.s == b.s)
		return a.e > b.e;
	return a.s < b.s;
}

int min(int a,int b)
{
	return a>b?b:a;
}

int main()
{
	int n,max;
	while(cin>>n)
	{
		max = 0;
		rep(i, n)
			cin>>data[i].s>>data[i].e;
		sort(data,data+n,cmp);
		int id = 0;
		for(int i = 1; i < n; i++){
			if(min(data[i].e-data[i].s,data[id].e-data[i].s) > max)
				max = min(data[i].e-data[i].s,data[id].e-data[i].s);
			if(data[i].e > data[id].e)
				id = i;
		}
		cout<<max<<endl;
	}
	return 0;
}
