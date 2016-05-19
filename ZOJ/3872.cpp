//DP算法 

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
//dp 表示当前输入的x前（包含x）的子序列的和；
//每次新加一个x，，那么他和上一次出现的同一个x之间的就是新增的，
//
//w[x] = i; 记录的是前面一次x最后出现的位置；
//
//模拟一下就知道了：
//
//输入   1     2     3
//
//dp      1     5     14
//
//sum   1     6      20
//
//w[i]     1     2      3
//
//
//代码如下：
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
