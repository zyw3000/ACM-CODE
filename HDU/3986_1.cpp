#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool flag;
int exp,num_dot,num_side,cnt,pd[1010],ps[1010],die[100010],dis[1010],box[1010];
struct node
{
    int to,next,w,co;
}side[100010];
void add(int from,int to,int w)
{
    side[cnt].to=to;
    side[cnt].w=w;
    side[cnt].next=box[from];
    box[from]=cnt++;
}
void init()
{
    int s,e,w;
    cnt=0;
    flag=1;
    memset(box,-1,sizeof(box));
    memset(die,0,sizeof(die));
    scanf("%d%d",&num_dot,&num_side);
    for(int i=0;i<num_side;i++)
    {
        scanf("%d%d%d",&s,&e,&w);
        side[cnt].co=cnt+1;
        add(s,e,w);
        side[cnt].co=cnt-1;
        add(e,s,w);
    }
}
void spfa()
{
    int mid;
    bool iq[1010];
    queue<int>qq;
    memset(iq,0,sizeof(iq));
    memset(dis,127,sizeof(dis));
    dis[1]=0;
    qq.push(1);
    iq[1]=1;
    while(qq.size())
    {
        mid=qq.front();
        qq.pop();
        iq[mid]=0;
        for(int i=box[mid];i>-1;i=side[i].next)
            if(die[i]==0&&dis[side[i].to]>dis[mid]+side[i].w)
            {
                dis[side[i].to]=dis[mid]+side[i].w;
                if(flag)
                {
                    pd[side[i].to]=mid;
                    ps[side[i].to]=i;
                }
                if(!iq[side[i].to])
                {
                    iq[side[i].to]=1;
                    qq.push(side[i].to);
                }
            }
    }
    flag=0;
}
int main()
{
    int ans;
    scanf("%d",&exp);
    while(exp--)
    {
        init();
        spfa();
        if(dis[num_dot]>50000000)
            printf("-1\n");
        else
        {
            ans=0;
            for(int i=num_dot;i>1;i=pd[i])
            {
                die[ps[i]]=1;
                die[side[ps[i]].co]=1;
                spfa();
                ans=max(ans,dis[num_dot]);
                die[ps[i]]=0;
                die[side[ps[i]].co]=0;
            }
            if(ans>50000000)
                printf("-1\n");
            else
                printf("%d\n",ans);
        }
    }
}
