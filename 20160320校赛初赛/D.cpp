#include <stdio.h>

int main()
{
	unsigned int input;
	while(scanf("%u",&input)!= EOF)
	{
		input = input<<16|input>>(32-16);
		printf("%u\n",input);
	}
	return 0;
}
