#include <iostream> 
using namespace std;

void multiply(int c[2][2],int a[2][2],int b[2][2],int mod)
{
	int tmp[4];
	tmp[0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	tmp[1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	tmp[2]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	tmp[3]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	c[0][0]=tmp[0]%mod;
	c[0][1]=tmp[1]%mod;
	c[1][0]=tmp[2]%mod;
	c[1][1]=tmp[3]%mod;
}//计算矩阵乘法，c=a*b

int fibonacci(int n,int mod)//mod表示数字太大时需要模的数
{
	if(n==0)return 0;
	else if(n ==1 )return 1;//这里表示第0项为0，第1，2项为1

	int a[2][2]={{7,19},{3,0}};
	int result[2][2]={{1,0},{0,0}};//初始化为单位矩阵
	int s;
	n-=2;
	while(n>0)
	{
		if(n%2 == 1)
			multiply(result,result,a,mod);
		multiply(a,a,a,mod);
		n /= 2;
	}//二分法求矩阵幂
	s=(result[0][0]+result[0][1])%mod;//结果
	return s;
}

int main()
{
	int n;
	while(cin>>n)
	{
		cout<<fibonacci(n,997)<<endl;
	}
	return 0;
}
