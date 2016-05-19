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
}//�������˷���c=a*b

int fibonacci(int n,int mod)//mod��ʾ����̫��ʱ��Ҫģ����
{
	if(n==0)return 0;
	else if(n ==1 )return 1;//�����ʾ��0��Ϊ0����1��2��Ϊ1

	int a[2][2]={{7,19},{3,0}};
	int result[2][2]={{1,0},{0,0}};//��ʼ��Ϊ��λ����
	int s;
	n-=2;
	while(n>0)
	{
		if(n%2 == 1)
			multiply(result,result,a,mod);
		multiply(a,a,a,mod);
		n /= 2;
	}//���ַ��������
	s=(result[0][0]+result[0][1])%mod;//���
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
