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

int data[44721];

int BinarySearch(int A[], int l, int r, int key)
{
    int m;
    while( l <= r )
    {
        m = l + (r-l)/2;

        if( A[m] == key )
            return m;

        if( A[m] < key )
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

int main()
{
	int T;
	int num = 0;
	rep(i,44721)
	{
		data[i] = (i+1)*(i)/2+1;
	}
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n; 
		if(BinarySearch(data,0,44721,n) == -1)
			cout<<0<<endl;
		else 
			cout<<1<<endl;
	}
	return 0;
 } 
