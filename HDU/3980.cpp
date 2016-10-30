#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int zhu[1005];

int solve(int len)
{
	int ans[1005];
    if(len<m)
	{
		return zhu[len] = 0;    //涂色后，若剩余珠子数量小于需要涂色珠子数量，直接返回 
	}
    if(zhu[len] != -1)
    {
    	return zhu[len];       //若这个子游戏已经求过，直接返回值 
	}
	memset(ans,0,sizeof(ans));
    for(int i = 0; len-m-i >= 0; i++)
        ans[solve(i)^solve(len-i-m)] = 1;    //把游戏划分成两部分，这里是用搜索求解所有的结果 g1(x1)⊕…⊕gn(xn)
    for(int i = 0;; i++)
    {
    	if(ans[i] == 0)    //g(x) = 0 为P点，  
		{
			zhu[len] = i;
			return zhu[len];
		}
	}
        
}



int main()
{
	int t;
	cin>>t;
    for(int idx = 1; idx <= t; idx++)
    {
        scanf("%d%d", &n, &m);
        memset(zhu, -1, sizeof(zhu));
        cout<<"Case #"<<idx<<": ";
        if(n<m || solve(n-m))
			cout<<"abcdxyzk"<<endl;
        else
			cout<<"aekdycoin"<<endl;
    }
    return 0;
}

