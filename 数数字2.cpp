#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
	int a,b,d,n,T;
	int res[15];
	cin>>T;
	while(T--)
	{
		scanf("%d%d%d%d",&a,&b,&d,&n);
		memset(res,0,sizeof res);
        if(n<=2)
		{
            int t=0;
            for(int i=0;i<n;i++)
                t=t*10+a;
            t=t*b;
            while(t)
			{
                res[t%10]++;
                t/=10;
            }
        }
		else
		{
            int c=a*b;
            res[c%10]++;
            int e=c/10;
            int t=e+a*b;
            res[t%10]++;
            e=t/10;
            t=e+a*b;
            res[t%10]+=n-2;
            if(t/10!=0)
            res[t/10]++;
        }
        cout<<res[d]<<endl;
	}
    return 0;
}


