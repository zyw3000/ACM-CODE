#include <iostream>
#include <cstring>
using namespace std;

struct node{
	int data,pre,s;
}X[505];

int main()
{
	int vis[505];
	int n,max,num,pos;
	while(scanf("%d",&n) != EOF)
	{
		max = 0;
		num = 0;
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&X[i].data);
			X[i].pre = i;
			X[i].s = 1;
		}
		for(int i = 1; i < n; i++)
		{
			for(int j = 0; j < i; j++)
			{
				if(X[i].data > X[j].data)
				{
					if(X[i].s <= X[j].s)
					{
						X[i].s = X[j].s+1;
						X[i].pre = j;
					}
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			if(max < X[i].s)
			{
				max = X[i].s;
				pos = i;
			} 
		}
		while(1)
		{
			vis[pos] = 1;
			if(X[pos].pre == pos)
				break;
			pos = X[pos].pre;
		}
		
		int max2 = max;
		while(max2 == max)
		{
			num++;
			max2 = 0;
			for(int i = 0; i < n; i++)
			{
				X[i].pre = i;
				X[i].s = 1;
			}
			for(int i = 1; i < n; i++)
			{
				if(vis[i]) continue;
				for(int j = 0; j < i; j++)
				{
					if(vis[j]) continue;
					if(X[i].data > X[j].data)
					{
						if(X[i].s <= X[j].s)
						{
							X[i].s = X[j].s + 1;
							X[i].pre = j; 
						}
					}
				}
			}
			for(int i = 0; i < n; i++)
			{
				if(vis[i]) continue;
				if(max2 < X[i].s)
				{
					max2 = X[i].s;
					pos = i;
				} 
			}
			while(1)
			{
				vis[pos] = 1;
				if(X[pos].pre == pos)
					break;
				pos = X[pos].pre;
			}
		}
		cout<<max<<endl;
		cout<<num<<endl;
	}
	return 0;
}
