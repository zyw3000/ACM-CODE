#include <iostream>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
#define MAXN 1000010  
  
bool isPrime[MAXN];  
long primeList[MAXN];  
long ans[MAXN];
int primeCount = 0;
 
void solve()
{
    memset( isPrime, true, sizeof( isPrime));
    memset( primeList, 0, sizeof( primeList));
    memset( ans, 0, sizeof( ans));
    for ( int i = 2; i < MAXN; ++ i) {
        if ( isPrime[i]) {
            primeCount = primeCount + 1;
            primeList[ primeCount] = i;
        }  
        ans[i] = primeCount;  
        for ( int j = 1; j <= primeCount; ++ j) {
            if ( i * primeList[j] > MAXN) {
                break;
            }
            isPrime[ i * primeList[j]] = false;
            if ( 0 == i % primeList[j]) {
            	break;
            }
        }
    }
    ans[0] = ans[1] = 0;
    return ;
}

int main()
{
    solve();
    int n;
    while(cin >> n)
    	cout << ans[n] << endl;
    return 0;
}
