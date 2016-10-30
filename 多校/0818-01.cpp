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

int data[100005];

int main()
{
	int t,n,m,l1,r1,l2,r2;
	double sum,div1,div2;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		rep(i,n)
			scanf("%d",&data[i]);
		rep(i,m){
			scanf("%d%d",&l1,&r1);
			scanf("%d%d",&l2,&r2);
			sum = 0;
			for(int j = l1 -1; j < r1; j++)
			{
				sum += data[j];
			}
			div1 = sum / (r1-l1+1);
			sum = 0;
			for(int j = l2 -1; j < r2; j++)
			{
				sum += data[j];
			}
			div2 = sum / (r2-l2+1);
			cout<<(div1+div2)/2<<endl;
		}
	}
	return 0;
}
