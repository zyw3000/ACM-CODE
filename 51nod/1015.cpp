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

int main()
{
	int n;
	int data[] = {153,370,371,407,1634};
	while(cin>>n)
	{
		rep(i,5)
		{
			if(data[i] >= n){
				cout<<data[i]<<endl;
				break;
			}
		}
	}
	return 0;
}
