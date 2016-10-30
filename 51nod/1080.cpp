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
#define rep(i,n) for(int i = 0; i <= sqrt(n); i++)
using namespace std;
#define LL long long

int main()
{
	int n,t,flag;
	while(scanf("%d",&n)!=EOF){
		flag = -1;
		rep(i,n){
			if(i == flag) break;
			t = sqrt(n-(i*i));
			if((t*t + i*i) == n){
				cout<<i<<" "<<t<<endl;
				flag = t;
			}
		}
		if(flag == -1) cout<<"No Solution"<<endl;
	}
	return 0;
}
