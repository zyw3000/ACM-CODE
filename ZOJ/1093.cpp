#include <iostream>
using namespace std;

typedef struct{
	int c;
	int k;
	int g;
}Thing;

void Swap(int &a,int &b, int &c)
{
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	if(b<c) swap(b,c);
}

int cmp(Thing a,Thing b)
{
	if(a.c == b.c) return a.k>b.k;
	return a.c>b.c;
}

int main()
{
	int n;
	Thing t[35];
	while(cin>>n && n)
	{
		for(int i = 0; i < n; i++)
		{
			cin>>t[i].c>>t[i].k>>t[i].g;
			Swap(t[i].c,t[i].k,t[i].g);
			
		}
		
	}
	return 0;
}
