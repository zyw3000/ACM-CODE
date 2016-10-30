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

int data[1005];

int main()
{
	int n,ans,flag;
	while(cin>>n)
	{
		flag = 1;
		rep(i,n)
			scanf("%d",&data[i]);
		sort(data,data+n);
		rep(i,n-2){
			ans = 0;
			ans += data[i];
			for(int j = i+1; j < n-1; j++){
				ans += data[j];
				for(int k = j+1; k < n; k++){
					ans += data[k];
					if(ans == 0){
						flag = 0;
						cout<<data[i]<<" "<<data[j]<<" "<<data[k]<<endl;
						ans -= data[k];
					}
					else ans -= data[k];
				}
				ans -= data[j];
			}
		}
		if(flag)
			cout<<"No Solution"<<endl;
	}
	return 0;
}
