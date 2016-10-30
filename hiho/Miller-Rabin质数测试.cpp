#include <cmath>

//如果n<2^64，只用选取a=2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37做测试即可

bool Miller-Rabin(int n)
{
	int a,u,x,y;
	if(n <= 2)
	{
		if(n == 2)
			return true;
		return false;
	}
	
	if((n%2) == 0)
		return false;
		
	u = n - 1;
	
	while( (n % 2) == 0)
		u /= 2;
		
	for(int i = 1; i <= 5; i++)
	{
		a = ((double)rand()/RAND_MAX)*((n-1)-2) + 2;
		x = pow(a,u) % n;
		while(u < n)
		{
			// 依次次检查每一个相邻的 a^u, a^2u, a^4u, ... a^(2^k*u)是否满足二次探测定
			y = pow(x, 2) % n;
			if(y == 1 && x != 1 && x != n-1)
				return false;
			x = y;
			u *= 2;
		}
		if(x != 1)
			return false;
	}
	return true;
}
