 #include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

class Tnode
{
	public:
		int left,right;
		int color;
		Tnode *lnode,*rnode;
		void creat(int l,int r);
		void insert(int l,int r,int c);
		void count();
};
int len;
int ans[8005];
int many[8005];
Tnode Tree[16005];
Tnode *Root = &Tree[0];

void Tnode::creat(int l,int r)
{
	left = l;
	right = r;
	if(r - l == 1)
	{
		lnode = NULL;
		rnode = NULL;
		return ;
	}
	lnode = &Tree[++len];
	rnode = &Tree[++len];
	int mid = (l + r) >> 1;
	lnode->creat(l,mid);
	rnode->creat(mid,r);
}

void Tnode::insert(int l,int r,int c)
{
	if(color == c) return ;
	if(left == l && right == r)
	{
		color = c;
		return ;
	}
	if(color != -2)
	{
		lnode->color = color;
		rnode->color = color;
		color = -2;
	}
	int mid = (left + right) >>1;
	if(r<=mid) {lnode->insert(l,r,c); return;}
	if(l>=mid) {rnode->insert(l,r,c); return;}
	
	lnode->insert(l,mid,c);
	rnode->insert(mid,r,c);
	
}

void Tnode::count()
{
	if( color == -1) return ;
	if( color != -2)
	{
		for(int i = left; i < right; i++)
		{
			ans[i] = color;
		}
	}
	if( color == -2)
	{
		lnode->count();
		rnode->count();
	}
}

int main()
{
	int n;
	len = 0;
	Root->creat(0,8000);
	while(cin>>n)
	{
		int l,r,c;
		Root->color = -1;
		memset(ans,-1,sizeof(ans));
		memset(many,0,sizeof(many));
		for(int i = 0; i < n; i++)
		{
			cin>>l>>r>>c;
			Root->insert(l,r,c);
		}
		Root->count();
		int t = -1;
		for(int i = 0; i <= 8000; i++)
		{
			if(ans[i] == t) continue;
			t = ans[i];
			if(t != -1)
				many[t]++;
		}
		for(int i = 0; i <= 8000; i++)
		{
			if(many[i]) cout<<i<<" "<<many[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
} 
