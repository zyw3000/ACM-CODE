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
	LL int n;
	while(cin>>n)
	{
		LL int t = 0;
		t += n / 2;
		t += n / 3;
		t += n / 5;
		t += n / 7;
		t -= n / 2 / 3;
		t -= n / 2 / 5;
		t -= n / 2 / 7;
		t -= n / 3 / 5;
		t -= n / 3 / 7;
		t -= n / 5 / 7;
		t += n / 2 / 3 / 5;
		t += n / 2 / 3 / 7;
		t += n / 2 / 5 / 7;
		t += n / 3 / 5 / 7;
		t -= n / 2 / 3 / 5 / 7;
		cout<<n-t<<endl;
	}
	return 0;
}
