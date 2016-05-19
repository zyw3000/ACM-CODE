#include <algorithm>
#include <cstdio>
#include <cmath>
#define min(A,B) ((A) < (B) ? (A) : (B))
#define MAX 9999999.9
using namespace std;

typedef struct
{
	double x,y;
}point;

point data[100005];
int temp[100005];

double Dis(point a,point b)
{
	return sqrt(pow(fabs(a.x-b.x),2)+pow(fabs(a.y-b.y),2));
}

int cmp_y(int a,int b)
{
	return data[temp[a]].y < data[temp[b]].y;
}

int cmp_xy(point a,point b)
{
	if(a.x!=b.x)
		return a.x < b.x;
	return a.y < b.y;
}

double seek(int low,int high)
{
	double dis = MAX;
	if(low == high) return dis;
	if(low+1 == high) return Dis(data[low],data[high]);
	int mid = (low+high)/2;
	double dis1 = seek(low,mid);
	double dis2 = seek(mid+1,high);
	dis = min(dis1,dis2);
	int count = 0;
	
	for(int i = low; i <=high; i++)
		if(fabs(data[mid].x - data[i].x) < dis) 
			temp[count++] = i;
			
	sort(temp,temp+count,cmp_y);
	
	for(int i = 0; i < count; i++)
	{
		for(int j = i+1; (j < count && data[temp[j]].y - data[temp[i]].y < dis); j++)
		{
			double dis3 =  Dis(data[temp[i]],data[temp[j]]);  //TMD 这一句BUG找了好几天，卧槽，原来写的是data[i],data[j]  我操！！！ 
			if(dis > dis3)
				dis = dis3;
		}
	}
	return dis;
}

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF &&N)
	{
		for(int i = 0; i < N; i++)
			scanf("%lf%lf",&data[i].x,&data[i].y);
		sort(data,data+N,cmp_xy);
		double result = seek(0,N-1) / 2;
		printf("%.2lf\n",result);
	}
	return 0;
}
