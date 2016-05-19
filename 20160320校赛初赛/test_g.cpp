#include <iostream>
using namespace std;


void getNum(long long int a[],int length)  
{  
    int s=0;//保存异或结果  
    for(int i=0;i<length;i++)  
    {  
        s=s^a[i];  
    }  
    int temp1=s;//临时保存异或结果  
    int temp2=s;//临时保存异或结果  
    int k=0;  
    while(!(temp1&1))//求位为1的位数  
    {  
        temp1=temp1>>1;  
        k++;  
    }  
    for(int i=0;i<length;i++)  
    {  
        if((a[i]>>k)&1)//将s与数组中第k位为1的数异或  
        {  
            cout<<a[i]<<" ";  
            s=s^a[i];  
        }  
       
    }   cout<<"end"<<endl;
    cout<<s<<" "<<(s^temp2)<<endl;//(s^temp2)用来求另外一个数  
}  

long long int a[1000005];

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i = 0; i < n; i++) 
		{
			cin>>a[i];
		}	getNum(a,n);	
	}
	return 0;
}
