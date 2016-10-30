#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T,a,b,d,n;
	cin>>T;
	while(T--)
	{int res = 0;
		scanf("%d%d%d%d",&a,&b,&d,&n);
		if(a*b < 10)
		{
			if(a*b == d) cout<<n<<endl;
			else cout<<0<<endl;
			continue;
		}
		else if(n <= 2)
		{
			int y = 0;
			while(n)
			{
				y += y*10 + a;
				n--;
			}
			y = y*b;
			while(y)
			{
				if(d == (y % 10)) 
				{
					y/=10;
					res++;
				}
			}
			cout<<res<<endl;
		}else{
			
			int qian,zhong,hou;
			int x = a*b;
			qian = x/10;
			hou = x%10;
			zhong = (qian+hou) % 10;
			if((qian+hou) < 10){
				if(d == qian) res += 1;
				if(d == zhong) res += (n-1);
				if(d == hou) res += 1;
				cout<<res<<endl;
				continue;
			}
			else{
				int si = x % 10;
				int san = (qian + hou) % 10;
				int er = san + 1;
				int yi = qian + 1;
				if(d == si) res += 1;
				if(d == san) res += 1;
				if(d == er) res += ( n - 2 );
				if(d == yi) res += 1;
				cout<<res<<endl;
				continue;	
			}
		}
	}
	return 0;
}
