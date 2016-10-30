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
const int maxn = 1e4+5;
const int INF = (1<<30);

int main(){
	int T,n,sum,max,score,flag;
	scanf("%d",&T);
	while(T--){
		flag = 0;
		scanf("%d",&n);
		max = (n-1)*2;
		sum = n*(n-1)/2;
		while(n--){
			scanf("%d",&score);
			sum -= score;
			if(score > max)
				flag = 1;
		}
		if(flag || sum > 0)
			cout<<"F"<<endl;
		else cout<<"T"<<endl;
	}
	return 0;
}

