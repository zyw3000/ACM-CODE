//DP�㷨 

#include <iostream>
using namespace std;

int n,data[100005];
int ans[100005];
int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>data[i];
		for()
		cout<<ans<<endl;
	}
	return 0;	
}

//
//
//PS:
//
//dp += (i-w[x])*x;
//
//dp ��ʾ��ǰ�����xǰ������x���������еĺͣ�
//ÿ���¼�һ��x������ô������һ�γ��ֵ�ͬһ��x֮��ľ��������ģ�
//
//w[x] = i; ��¼����ǰ��һ��x�����ֵ�λ�ã�
//
//ģ��һ�¾�֪���ˣ�
//
//����   1     2     3
//
//dp      1     5     14
//
//sum   1     6      20
//
//w[i]     1     2      3
//
//
//�������£�
//
//#include <cstdio>
//#include <cstring>
//int main()
//{
//    int t;
//    int n;
//    int w[100017];
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d",&n);
//        int x;
//        memset(w,0,sizeof(w)); 
//        long long sum = 0, dp = 0;
//        for(int i = 1; i <= n; i++)
//        {
//            scanf("%d",&x);
//            dp += (i-w[x])*x;
//            sum+=dp;
//            w[x] = i;
//        }
//        printf("%lld\n",sum);
//    }
//    return  0;
//}
