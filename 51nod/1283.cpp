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
#define rep(i,n) for(int i = 1; i <= n; i++)
using namespace std;
#define LL long long

int main()
{
	int s;
	while(scanf("%d",&s)!=EOF)
	{
		for(int i = sqrt(s); i >= 1; i--)
		{
			if(s % i == 0)
			{
				cout<<(i+(s/i))*2<<endl;
				break;
			}
		}
	}
	return 0;
}
