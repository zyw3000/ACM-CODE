#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;

char n[10000005];

int main()
{
	int k = 1;
	int i;
	while(scanf("%s",&n)!=EOF)
	{
		int len = strlen(n);
		cout<<"Case #"<<k++<<": ";
		int mod = 0;  
        for(i=0; i<len; i++)  
        {  
            mod=mod*10+n[i]-'0';  
            mod=mod%137;                     
        }  
        if(mod == 0)
		{
			for(i=0; i<len; i++)  
        	{  
            	mod=mod*10+n[i]-'0';  
            	mod=mod%73;
       		}
			if(mod == 0)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl; 
		}  
		else cout<<"NO"<<endl;
	}
	return 0;
}
