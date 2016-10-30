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

map<char, int>m;

int main()
{
	char input[1005];
	int ans;
	while(scanf("%s",&input)!=EOF){
		ans = 0;
		rep(i,strlen(input))
		{
			m[input[i]]++;
		}
		map<char, int>::iterator it;
		it = m.begin();
		while(it != m.end()){
			if(it->second % 2 == 1)
				ans++;
			it++;
		}
		cout<<ans<<endl;
		m.clear();
	}
	return 0;
}
