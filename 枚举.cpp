#include <iostream>
#include <cstring>
using namespace std;



void Print(int n,int *A,int cur)
{
	if(cur == n){
		for(int i = 0; i < n; i++)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
	else for(int i = 1; i <= n; i++)
	{
		int flag = 1;
		for(int j = 0; j < cur; j++)
		{
			if(A[j] == i) flag = 0;
		}
		if(flag)
		{
			A[cur] = i;
			Print(n,A,cur+1);
		}
	}
}

int main()
{
	int n;
	int A[100];
	memset(A,0,sizeof(A));
	cin>>n;
	Print(n,A,0);
	return 0;
}
