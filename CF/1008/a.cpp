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

string day[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main(){
	string fst,sed;
	int i;
	while(cin>>fst>>sed){
		for(i = 0; i < 7; i++)
			if(fst == day[i])
				break;
		if(fst == sed){
			cout<<"YES"<<endl;
			continue;
		}
		i = (i+2)%7;
		if(day[i] == sed){
			cout<<"YES"<<endl;
			continue;
		}
		i = (i+1)%7;
		if(day[i] == sed){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}

