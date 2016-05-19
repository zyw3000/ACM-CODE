#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct
{
	int s;
	int e;
	int num;
}gene;

int cmp(gene a, gene b)
{
	if(a.e == b.e) return a.s > b.s;
	return a.e < b.e;
}

int main()
{
	int n;
	gene a[1005];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&a[i].s,&a[i].e);
			a[i].num = i+1;
		}
		sort(a,a+n,cmp);
		int preEnd = a[0].e;
		cout<<a[0].num;
		for(int i = 1; i < n; i++)
		{
			if(a[i].s > preEnd)
			{
				preEnd = a[i].e;
				cout<<" "<<a[i].num;
			}
		}
		cout<<endl;
	}
	return 0;
} 
