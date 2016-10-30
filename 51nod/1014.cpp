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
	int p,a,flag;
	while(scanf("%d%d",&p,&a)!=EOF)
	{
		flag = 1;
		for(LL i = 1; i < p; i++)
		{
			if((i*i)%p == a){
				flag = 0;
				cout<<i<<" ";
			}
		}
		if(flag) cout<<"No Solution"<<endl;
	}
	return 0;
}
