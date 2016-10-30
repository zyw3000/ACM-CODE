#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 100000+5;
struct node
{
    int left, right, flag;
}a[MAXN];
inline bool cmp(node a, node b)
{
    if(a.right != a.right)
        return a.left < b.left;
    return a.right < b.right;
}
int Binary_search(int l, int r, int x)
{
    int mid;
    while(l < r)
    {
        mid = (l+r)>>1;
        if(a[mid].right >= x)
            r = mid-1;
        else
            l = mid+1;
    }
    while(l>0 && a[l].right>=x)
        l--;
    return l;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int c, r, cnt = 0;
        for(int i=1; i<=n; i++)
        {
            cin>>c>>r;
            a[i].left = c-r;
            a[i].right = c+r;
        }
        sort(a+1, a+n+1, cmp);
        a[0].left = a[0].right = -1;
        int ans = 0;
        for(int i=1; i<=n; i++)
            ans += Binary_search(1, i, a[i].left);
        cout<<ans<<endl;
    }
    return 0;
}
