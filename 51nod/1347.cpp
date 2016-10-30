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

char a[1000005];

int main(){
	int flag;
	int j;
	while(cin>>a){
		int n = strlen(a);
		flag = 0;
		if(n % 2 != 0){
			cout<<"NO"<<endl;
			continue;
		}
		else{
			rep(i,n){
				for(j = 0; j < n/2; j++){
					if(a[(i+j)%n] != a[(i+j+n/2)%n])
						break;
				}
				if(j == n/2)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
