#include <stdio.h>

long long int a[1000005];

int main()
{
	int n;
	long long int t,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		t = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a[i]);
			t ^= a[i];
		}
		x = t;
		y = t;
		
	   	int j=0;
	   	
	    while(!(x&1)) 
	    { 
	        x = x>>1;  
	        j++;  
	    } 
	    for(int i = 0; i < n; i++)  
	    {  
	        if((a[i]>>j)&1)
	        {  
	            t ^= a[i];  
	        } 
	    }
	    long long int another = t^y;
	    if(another>t)
	    {
	    	another += t;
	    	t = another - t;
	    	another = another - t;
		}
	    printf("%d %d\n",another,t);
	}
	return 0;
}
