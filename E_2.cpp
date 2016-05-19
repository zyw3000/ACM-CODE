#include<stdio.h>

int main()
{
	char in;
	int t;
	int n = 1;
	int Quicksum;
	while(1)
	{
		getchar(in);
		if(in == '#')
		{
			break;
		}
		if(in == '\n')
		{
			printf("%d\n",Quicksum);
			Quicksum = 0;
			n = 0;
			continue;
		}
		if(in == ' ')
		{
			continue;
		}
		else
		{
			t = in-'A'+1;
			Quicksum += t*n;
			n++;
		}
	}
	return 0;
}
