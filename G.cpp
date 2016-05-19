#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n,m;
	int i,j,k=0,g=0;
	char input[30][30];
	int result[200];
	memset(result,0,200);
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
		{
			while(g < k)
			{
				cout<<result[g++]<<endl;
			}
			break;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin>>input[i][j];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(input[i][j] == '@')
				{
					int k=4;
					while(k--)
					{
						if(k == 4)
						{
							if(j==0) continue;
							if(input[i][j-1]=='@')    //вС 
							{
								input[i][j]='1';
							}
							else if(input[i][j-1]=='1')
							{
								input[i][j]='1';
							}
						}
						if(k == 3)
						{
							if(i==0) continue;
							if(input[i-1][j]=='@')   //ио 
							{
								input[i][j]='1';
							}
							else if(input[i-1][j]=='1')
							{
								input[i][j]='1';
							}
						}
						if(k == 2)                  //ср 
						{
							if(j==m-1) continue;
							if(input[i][j+1]=='@')
							{
								input[i][j+1]='1';
							}
							else if(input[i][j+1]=='1')
							{
								input[i][j+1]='1';
							}
						}
						else if(k == 1)               //об 
						{
							if(i==n-1) continue;
							if(input[i+1][j]=='@')
							{
								input[i+1][j]='1';
							}
							else if(input[i][j+1]=='1')
							{
								input[i][j+1]='1';
							}
						}
					}
				}
				else if(input[i][j] == '1')
				{
					int k=3;
					while(k--)
					{
						if(k == 3)         // вС
						{
							if(j==0) continue;
							if(input[i][j-1]=='@')
							{
								input[i][j-1]='1';
							}
							else if(input[i][j-1]=='1')
							{
								input[i][j-1]='1';
							}
						}
						if(k == 2)         // ср 
						{
							if(j==m-1) continue;
							if(input[i][j+1]=='@')
							{
								input[i][j+1]='1';
							}
							else if(input[i][j+1]=='1')
							{
								input[i][j+1]='1';
							}
						}
						else if(k == 1)        //об 
						{
							if(i==n-1) continue;
							if(input[i+1][j]=='@')
							{
								input[i+1][j]='1';
							}
							else if(input[i][j+1]=='1')
							{
								input[i][j+1]='1';
							}
						}
					}
				}
			}
		}
		for(i = 0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(input[i][j]=='@')
				result[k]++;
			}
		}
		k++;
	}
	return 0;
}
