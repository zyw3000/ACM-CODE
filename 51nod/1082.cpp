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

LL res[1000005];

void init()
{
	LL test;
	int flag,t;
	res[0] = 0;
	rep(i,1000002){
		flag = 0;
		t = i;
		if(t % 7 == 0){
			res[i] = res[i-1];
			continue;
		}
		while(t){
			if(t % 10 == 7){
				flag = 1;
				break;
			}
			t /= 10;
		}
		if(flag){
			res[i] = res[i-1];
			continue;
		}
		test = pow(i,2);
		res[i] = res[i-1]+test;
	}
}

int main()
{
	int idx,n;
	init();
	cin>>idx;
	while(idx--){
		scanf("%d",&n);
		cout<<res[n]<<endl;
	}
	return 0;
}
