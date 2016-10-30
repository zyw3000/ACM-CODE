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

int data[50005];

int main()
{
	int n,k,l,r,flag;
	while(scanf("%d%d",&k,&n)!=EOF){
		flag = 1;
		rep(i,n)
			scanf("%d",&data[i]);
		sort(data,data+n);
		l = 0;
		r = n-1;
		while(l != r){
			if(data[l] + data[r] == k){
				cout<<data[l]<<" "<<data[r]<<endl;
				flag = 0;
				if(l == r-1) break;
				l++;
				r--;
				continue;
			}
			if((data[l] + data[r]) > k)
				r--;
			else
				l++;
		}
		if(flag)
			cout<<"No Solution"<<endl;
	}
	return 0;
}
