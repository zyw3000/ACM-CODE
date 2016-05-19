#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct
{
	string name;
	int p;
}dish;

int cmp_p(dish a, dish b)
{
	return a.p < b.p; 
}

int main()
{
	int T,lim;
	dish data1[105],data2[105],data3[105];
	cin>>T;
	while(T--){
		int num1,num2,num3;
		cin>>num1>>num2>>num3;
		for(int i = 0; i < num1; i++)
			cin>>data1[i].name>>data1[i].p;
		sort(data1,data1+num1,cmp_p);
		for(int i = 0; i < num2; i++)
			cin>>data2[i].name>>data2[i].p;
		sort(data2,data2+num2,cmp_p);
		for(int i = 0; i < num3; i++)
			cin>>data3[i].name>>data3[i].p;
		sort(data3,data3+num3,cmp_p);
		int sum = 0;
		sum += data1[num1/2].p;
		sum += data2[num2/2].p;
		sum += data3[num3/2].p;
		cout<<sum<<" ";
		cout<<data1[num1/2].name<<" "<<data2[num2/2].name<<" "<<data3[num3/2].name<<endl;
	}
	return 0;
}
