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
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;
const int size  = 100005;

char s[size];
int rk[size],sa[size],height[size],w[size],wa[size],res[size];
int nxt[size]; 

int max(int a, int b)
{
	return a>b?a:b;
}

void getSa (int len,int up) {
	int *k = rk,*id = height,*r = res, *cnt = wa;
	rep(i,up) cnt[i] = 0;
	rep(i,len) cnt[k[i] = w[i]]++;
	rep(i,up) cnt[i+1] += cnt[i];
	for(int i = len - 1; i >= 0; i--) {
		sa[--cnt[k[i]]] = i;
	}
	int d = 1,p = 0;
	while(p < len){
		for(int i = len - d; i < len; i++) id[p++] = i;
		rep(i,len)	if(sa[i] >= d) id[p++] = sa[i] - d;
		rep(i,len) r[i] = k[id[i]];
		rep(i,up) cnt[i] = 0;
		rep(i,len) cnt[r[i]]++;
		rep(i,up) cnt[i+1] += cnt[i];
		for(int i = len - 1; i >= 0; i--) {
			sa[--cnt[r[i]]] = id[i];
		} 
		swap(k,r);
		p = 0;
		k[sa[0]] = p++;
		rep(i,len-1) {
			if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]] == r[sa[i+1]]&& r[sa[i]+d] == r[sa[i+1]+d])
				k[sa[i+1]] = p - 1;
			else k[sa[i+1]] = p++;
		}
		if(p >= len) return ;
		d *= 2,up = p, p = 0;
	}
}

void getHeight(int len) {
	rep(i,len) rk[sa[i]] = i;
	height[0] =  0;
	for(int i = 0,p = 0; i < len - 1; i++) {
		int j = sa[rk[i]-1];
		while(i+p < len&& j+p < len&& w[i+p] == w[j+p]) {
			p++;
		}
		height[rk[i]] = p;
		p = max(0,p - 1);
	}
}


int getSuffix(char s[]) {
	int len = strlen(s),up = 0;	
	for(int i = 0; i < len; i++) {
		w[i] = s[i];
		up = max(up,w[i]);
	}
	w[len++] = 0;
	getSa(len,up+1);
	getHeight(len);
	return len;
}


int main()
{
	char a;
	int x,t,lenth;
	scanf("%d",&t);
	for(int idx = 1; idx <= t; idx++)
	{
		long long int sum = 0;
		cin>>a;
		cin>>s;
		getSuffix(s);
		lenth = strlen(s);
		x = lenth;
        for(int i = lenth-1; i >= 0; i--) 
		{
            if(s[i] == a)
                x = i;
            nxt[i] = x;
        }
        
		for(int i = 1; i <= strlen(s); i++)
		{
			sum += strlen(s)-max(nxt[sa[i]],(sa[i] + height[i]));
		}
		cout<<"Case #"<<idx<<": ";
		cout<<sum<<endl;
	}
	return 0;
}
