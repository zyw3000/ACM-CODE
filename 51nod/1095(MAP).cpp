#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
#define LL long long

char dic[12];
char que[12];
char s_que[12];


int main()
{
	int n,q,ans,flag;
	while(scanf("%d",&n)!=EOF)
	{
		map<string, int> mp_1, mp_2;
		rep(i,n){
			scanf("%s",&dic);
			mp_1[dic]++;
			sort(dic,dic+strlen(dic));
			mp_2[dic]++;
		}
		scanf("%d",&q);
		rep(i,q){
			scanf("%s",&que);
			int num1 = mp_1[que];
			sort(que,que+strlen(que));
			int num2 = mp_2[que];
			cout<<num2- num1<<endl;		
		}
	}
	return 0;
}
//Å£±ÆÐ´·¨ 
//#include<bits/stdc++.h>
//using namespace std;
//map<string,multiset<string> >mp;
//int main()
//{
//	string str,tmp;
//	int n,q,i,j,ans;
//	cin>>n;
//	for(i=1;i<=n;i++) {
//		cin>>str;
//		tmp=str;
//		sort(str.begin(),str.end());
//		mp[str].insert(tmp);
//	}
//	cin>>q;
//	while(q--) {
//		cin>>str;
//		tmp=str;
//		sort(str.begin(),str.end());
//		ans=mp[str].size()-mp[str].count(tmp);
//		cout<<ans<<endl;
//	//cout<<mp[str].size()<<" "<<mp[str].count(tmp)<<endl;
//	}
//	return 0;
//}
