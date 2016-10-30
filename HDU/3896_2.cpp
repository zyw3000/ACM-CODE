#include<cstdio>
#include <iostream>
#include<cstring>
using namespace std;

#define inf 0x3f3f3f3f

int flag,num;
int box[1005],cost[1005],Next[1005],queue[1005];

struct node
{
	int u,v,w,see,pre;
}side[100005];

void add(int u,int v,int w)
{
	side[num].u = u;
	side[num].v = v;
	side[num].w = w;
	side[num].see = 1;
	side[num].pre = box[u];
	box[u] = num++;
}

void init(int m)
{
	int u,v,w;
	memset(box,-1,sizeof(box));
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	memset(Next,-1,sizeof(Next));
	flag = 1;
}

int spfa(int n)
{
	int x,v,w,front = 0,end = 0;
	int FLAG[1005];
	memset(FLAG,0,sizeof(FLAG));
	for(int i = 1;i <= n;i++)
		cost[i] = inf;
	cost[1] = 0;
	queue[++end] = 1;
	//用数组模拟队列 
	while(front != end)
	{
		front = (front + 1) % 1005;
		x = queue[front];
		FLAG[x] = 0;
		for(int i = box[x]; ~i; i = side[i].pre)
		{
			if(side[i].see && cost[v = side[i].v] > (w = cost[x] + side[i].w))
			{
				cost[v] = w;
				if(flag)
					Next[v] = i;
				if(!FLAG[v])
				{					
					FLAG[v] = 1;
					end = (end + 1) % 1005;
					queue[end] = v;
				}
			}
		}
	}
	return cost[n];
}

int main()
{
	int n,m,t,ans;
	cin>>t;
	while(t--)
	{
		ans=-1;
		num=0;
		scanf("%d%d",&n,&m);
		init(m);
		spfa(n);
		
		int i,j,k;
		flag = 0;
		i = n;
		while(Next[i] != -1)
		{
			j = Next[i];
			side[j].see = 0;
			side[j^1].see = 0;
			//删去一条边再计算一次最短路径 
			k = spfa(n);
			side[j].see = 1;
			side[j^1].see = 1;
			//恢复路 
			if(k>ans)
				ans = k;
			i = side[j].u;
		}
		if(ans < inf)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
}

