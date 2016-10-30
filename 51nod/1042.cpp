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
const int maxn = 12;
const int INF = (1<<30);


LL num[10];

int main()
{
	LL a,b;
	int cnt;
	int b2,a2;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		cnt = 0;
		while(a || b){
			b2 = b%10;
			a2 = a%10;
			for(int i = a2; i <= b2; i++){
				num[i] += pow(10,cnt)*( + 1);
			}
			cnt++;
			a /= 10;
			b /= 10;
		}
		rep(i,10)
			cout<<num[i]<<endl;
	}
	return 0;
}
