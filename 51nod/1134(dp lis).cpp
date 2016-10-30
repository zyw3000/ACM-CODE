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
//dp+¶þ·Ö O(nlogn) 
const int maxn = 50005;
const int INF = -1e9-100;

int a[maxn];
int b[maxn];

int main()
{
	int n,len;
	while(scanf("%d",&n)!=EOF)
	{
		len = 1;
		rep(i,n)
			scanf("%d",&a[i]);
		b[0] = a[0];
		for(int i = 1; i < n; i++){
			if(a[i] > b[len-1])
				b[len++] = a[i];
			else
				b[lower_bound(b,b+len,a[i])-b] = a[i];
		}
		cout<<len<<endl;
	}
	return 0;
}
