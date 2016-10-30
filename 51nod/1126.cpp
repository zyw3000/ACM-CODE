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

int num[300];

int main()
{
	int a,b,n,i;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF){
		if(n == 1 || n == 2){
			cout<<1<<endl; 
			continue;
		}
		num[1] = 1;
		num[2] = 1;
		for(i = 3; i < 300; i++){
			num[i] = ((a*num[i-1]+b*num[i-2])%7+7)%7;
			if(num[i] == 1 && num[i-1] == 1)
				break;
		}
		num[0] = num[i-2]; // 重要，考虑到n mod = 0的时候 
		n = n%(i-2);
		cout<<num[n]<<endl;
	}
	return 0;
}
