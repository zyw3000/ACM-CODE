#include <iostream>
using namespace std;


void getNum(long long int a[],int length)  
{  
    int s=0;//���������  
    for(int i=0;i<length;i++)  
    {  
        s=s^a[i];  
    }  
    int temp1=s;//��ʱ���������  
    int temp2=s;//��ʱ���������  
    int k=0;  
    while(!(temp1&1))//��λΪ1��λ��  
    {  
        temp1=temp1>>1;  
        k++;  
    }  
    for(int i=0;i<length;i++)  
    {  
        if((a[i]>>k)&1)//��s�������е�kλΪ1�������  
        {  
            cout<<a[i]<<" ";  
            s=s^a[i];  
        }  
       
    }   cout<<"end"<<endl;
    cout<<s<<" "<<(s^temp2)<<endl;//(s^temp2)����������һ����  
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
