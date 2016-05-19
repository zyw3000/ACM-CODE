#include<iostream>                         //³¬Ê± 
using namespace std;
class day
{
	public:
		int a;
		int b;
};

int main()
{
	int n,a,b,sum;
    day d[1000];
	int i,j;
	day t;
	int x;
	while(cin>>n)
	{
		i = 0;
		if(n == 0)
		{
	 		return 0;
	  	}
	 	x = n;
		while(x--)
		{
	  		cin>>d[i++].a>>d[i].b;
	 	}
	  	for(i = 0;i<n;i++)
	  	{
	  		for(j = i+1;j<n;j++)
	  		{
	   			if(d[i].a>d[j].a)
		   		{
		     		t = d[j];
		   	 		d[j] = d[i];
		   			d[i] = t;
		   		}
	  		}
	 	}
	    d[i].a = 0;
	    d[i].b = 0;
	    sum = 0;
	    i = 0;
	    int flag = 1;
		while(i<=n-1)
		{
			if(d[i].b>=10)
			{
				sum++;
				d[i].b--;
				d[i].a++;
				if(d[i].a == d[i+1].a)
				{
				    d[i+1].b = d[i].b+d[i+1].b;
				    i++;
				}
			}
			if(d[i].b == 0)
			{
				i++;
			}
			if(d[i].b<10 && d[i].b!=0 )
			{
				d[i].b--;
				d[i].a++;
				if(d[i].a == d[i+1].a)
				{
				    d[i+1].b += d[i].b;
				    i++;
				}
			} 
		}
		cout<<sum<<endl;
	}
	return 0;
}
