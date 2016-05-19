#include <iostream>
#include <map>
using namespace std;

int main()
{
	int T,p,lim;
	string name;
	cin>>T;
	while(T--){
		map<string, int>S;
		map<string, int>M;
		map<string, int>D;
		int nums,numm,numd,sum = 0;
		cin>>nums>>numm>>numd;                                     
		for(int i = 0; i < nums; i++)
		{
			cin>>name>>p;
			S[name] = p;
		}
		for(int i = 0; i < numm; i++)
		{
			cin>>name>>p;
			M[name] = p;
		}
		for(int i = 0; i < numd; i++)
		{
			cin>>name>>p;
			D[name] = p;
		}
		//
		
		lim = nums / 2 + 1;
		map<string, int>::iterator pos1;
		pos1 = S.end();
		for(int i = 1; i < lim; i++, pos1--){
		}
		sum += pos1->second;
		//
		lim = numm / 2 + 1;
		map<string, int>::iterator pos2;
		pos2 = M.end();
		for(int i = 1; i < lim; i++, pos2--){
		}
		sum += pos2->second;
		//
		lim = numd / 2 + 1;
		map<string, int>::iterator pos3;
		pos3 = D.end();
		for(int i = 1; i < lim; i++, pos3--){
		}
		sum += pos3->second;
		
		cout<<sum<<" ";
		cout<<pos1->first<<" ";
		cout<<pos2->first<<" ";
		cout<<pos3->first<<" "<<endl;
		
		D.clear();M.clear();S.clear();
		
	}
	return 0;
}
