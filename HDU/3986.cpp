#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define inf 999999999

bool flag;
int num,pd[1010],ps[1010],die[100010],dis[1010],box[1010];

struct node
{
    int v,pre,w;
	int co;
}side[100010];

void insert(int u,int v,int w)
{
    side[num].v = v;
    side[num].w = w;
    side[num].pre = box[u];
    box[u] = num++;
}

void spfa()
{
    int mid;
    bool iq[1010];
    queue<int>qq;
    memset(iq,0,sizeof(iq));
    memset(dis,inf,sizeof(dis));
    dis[1] = 0;
    qq.push(1);
    iq[1] = 1;
    while(qq.size())
    {
        mid = qq.front();
        qq.pop();
        iq[mid] = 0;
        for(int i = box[mid]; i > -1; i = side[i].pre)
            if(die[i] == 0 && dis[side[i].v] > (dis[mid] + side[i].w))
            {
                dis[side[i].v] = dis[mid]+side[i].w;
                if(flag)
                {
                    pd[side[i].v] = mid;
                    ps[side[i].v] = i;
                }
                if(!iq[side[i].v])
                {
                    iq[side[i].v] = 1;
                    qq.push(side[i].v);
                }
            }
    }
    flag = 0;
}

int main()
{
    int n,m,ans,t;
    cin>>t;
    while(t--)
    {
        int u,v,w;
        
	    num = 0;
	    flag = 1;
	    memset(box,-1,sizeof(box));
	    memset(die,0,sizeof(die));
	    scanf("%d%d",&n,&m);
	    for(int i = 0; i < m; i++)
	    {
	        scanf("%d%d%d",&u,&v,&w);
	        side[num].co = num + 1;
	        insert(u,v,w);
	        side[num].co = num - 1;
	        insert(u,v,w);
	    }
	    
        spfa();
        if(dis[n] >= inf)
            cout<<-1<<endl;
        else
        {
            ans = 0;
            for(int i = n; i > 1; i = pd[i])
            {
                die[ps[i]] = 1;
                die[side[ps[i]].co] = 1;
                spfa();
                ans = max(ans,dis[n]);
                die[ps[i]] = 0;
                die[side[ps[i]].co] = 0;
            }
            if(ans < inf)
                cout<<ans<<endl;
            else
                cout<<-1<<endl;
        }
    }
}
