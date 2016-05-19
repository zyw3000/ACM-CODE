#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a)
#define LL long long
const double pi = acos(-1.0);
#define Len 20005
#define mod 19999997
const int INF = 0x3f3f3f3f;

char s1[]= {"-=_+qwertyuiop[]QWERTYUIOP{}asdfghjkl;'ASDFGHJKL:\"zxcvbnm,./ZXCVBNM<>?"};
char s2[]= {"[]{}',.pyfgcrl/=\"<>PYFGCRL?+aoeuidhtns-AOEUIDHTNS_;qjkxbmwvz:QJKXBMWVZ"};
char c;

char print(char c)
{
    for(int i=0; s1[i]; i++)
        if(s1[i]==c)
            return s2[i];
    return c;
}
int main()
{
    w(~scanf("%c",&c))
    printf("%c",print(c));

    return 0;
}
