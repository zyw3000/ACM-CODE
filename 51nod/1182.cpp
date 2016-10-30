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

int cmp(int a, int b)
{
	return a>b;
}

int main()
{
	char zimu[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int data[26],ans;
	char input[10005];
	while(scanf("%s",input)!=EOF)
	{
		ans = 0;
		memset(data,0,sizeof(data));
		rep(i,strlen(input)){
			if(input[i] <= 'Z'){
				input[i] += 32;
			}
				
			rep(j,26){
				if(input[i] == zimu[j])
				{
					data[j]++;
					break;
				}
			}
		}
		sort(data,data+26,cmp);
		rep(i,26){
			if(data[i] == 0) break;
			ans += (26-i)*data[i];
		}
		cout<<ans<<endl;
	}
}
