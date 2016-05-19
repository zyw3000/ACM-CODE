#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char a[105];
	int n,i,length;
	int t = 0,temp;
	int flag;
	memset(a,0,105);
	while(cin>>a>>n)
	{
		length = strlen(a);
		flag = 0;
		for(i = length-1;i>=0;i++)
		{
			t = a[i]-'0';
			temp = t*n;
			if(i==0)
			{
				if(temp<10)
				{
					a[i] = temp;
				}
				else
				{
					flag = 1;
					a[i] = temp%10;
					temp /=10;
				}
			}
			if(temp>10)
			{
				a[i] = temp%10;
				a[i-1] += temp/10;
			}
			else 
			{
				a[i] = temp;
			}
		}
		if(flag)
		{
			cout<<temp;
		}
		cout<<a<<endl;
		memset(a,0,105);
	}
}
