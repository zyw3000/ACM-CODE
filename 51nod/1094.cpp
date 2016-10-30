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

int num[maxn];

int main(){
	int n,k,i,j,sum,flag;
	while(scanf("%d%d",&n,&k)!=EOF){
		flag = 1;
		rep(i,n){
			scanf("%d",num+i);
		}
		rep(i,n){
			sum = 0;
			if(flag == 0) break;
			for(int j = i; j < n; j++){
				sum += num[j];
				if(sum == k){
					cout<<i+1<<" "<<j+1<<endl;
					flag = 0;
					break;
				}
			}
		}
		if(flag)
			cout<<"No Solution"<<endl;
	}
	return 0;
}
