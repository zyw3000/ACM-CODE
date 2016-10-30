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
		return zhu[len] = 0;    //Ϳɫ����ʣ����������С����ҪͿɫ����������ֱ�ӷ��� 
	}
    if(zhu[len] != -1)
    {
    	return zhu[len];       //���������Ϸ�Ѿ������ֱ�ӷ���ֵ 
	}
	memset(ans,0,sizeof(ans));
    for(int i = 0; len-m-i >= 0; i++)
        ans[solve(i)^solve(len-i-m)] = 1;    //����Ϸ���ֳ������֣�������������������еĽ�� g1(x1)������gn(xn)
    for(int i = 0;; i++)
    {
    	if(ans[i] == 0)    //g(x) = 0 ΪP�㣬  
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

