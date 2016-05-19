#include <iostream>
#include <cstring>
using namespace std;

int height[95];
int box[95][3];
int limit;

void Creat(int num,int a,int b,int c)
{
	box[num][0] = a;
	box[num][1] = b;
	box[num][2] = c;
}

int DP(int num)
{
	if(num >limit ) return 0;
	if(height[num] != -1) return height[num];
	int t = 0;
	for(int i = 1; i <= limit; i++)
	{
		if((box[i][0] < box[num][0] && box[i][1] < box[num][1]) ||
			(box[i][0] < box[num][1] && box[i][1] < box[num][0]))
			t = DP(i) + box[num][2];
		if(t > height[num]) height[num] = t;
	}
	return height[num];
}

int main()
{
	int n,a,b,c,num = 1;
	while(cin>>n && n)
	{
		limit = 3*n;
		memset(height,-1,sizeof(height));
		memset(box,0,sizeof(box));
		int number = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>a>>b>>c;
			Creat(++number,a,b,c);
			Creat(++number,b,c,a);
			Creat(++number,c,a,b);
		}
		
		
		
		cout<<"Case "<<num++<<": maxinum height = "<<height[0]<<endl;
	}
	return 0;
}
