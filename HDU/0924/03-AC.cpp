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
#include <utility>
#define ff first
#define ss second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9+250;
LL mod=1e9+7;
const int N=100005;
map<string,int> mp;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in1003.txt","r",stdin);
#endif
    string s;
    while(getline(cin,s)){
        //cout<<s<<endl;
        //cout<<s.find('\n')<<endl;;
        s.push_back('.');
        if(s[0]=='#'){
            string ans;
            int ct=0;
            for(auto x:mp){
                if(x.ss>ct){
                    ans=x.ff;
                    ct=x.ss;
                }
            }
            cout<<ans<<":"<<ct<<endl;
            mp.clear();
        }else{
            vector<string> a;
            int pos=0;
            while(1){
                while(pos<s.size()&&s[pos]==' '){
                    pos=pos+1;
                }
                if(pos>=s.size())break;
                auto t=s.find_first_of(" ,.",pos);
                if(s[t]==','||s[t]=='.'){
                    if(t-pos>0)
                        a.push_back(s.substr(pos,t-pos));
                    for(int i=0;i<(int)a.size()-1;i++){
                        mp[a[i]+" "+a[i+1]]++;
                    }
                    a.clear();
                    pos=t+1;
                }else{
                    if(t-pos>0)
                        a.push_back(s.substr(pos,t-pos));
                    pos=t+1;
                }
            }
        }
    }    
	return 0;
}








